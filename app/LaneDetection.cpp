/**
* @file LaneDetection.cpp
* @brief LaneDetection class
* @details Implementation of LaneDetection class for detecting lanes
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/

#include <math.h>
#include <string>
#include <vector>
#include "../include/LaneDetection.hpp"

#define PI 3.14159265

/**
 * @brief Constructs the object.
 */

LaneDetection::LaneDetection() {}

/**
 * @brief Destroys the object.
 */

LaneDetection::~LaneDetection() {}


 /**
  * @brief Do image filtering on input image
  * @param input_image Input image frame to be filtered
  * @return Filtered Image
  */

cv::Mat LaneDetection::filter(cv::Mat input_image) {
  cv::Mat image_output;
  // Apply median filter
  cv::medianBlur(input_image, image_output , 3);

  return image_output;
}

 /**
  * @brief Do edge detection on filtered image
  * @param input_filter Input image frame
  * @return Image with edge detected
  */


cv::Mat LaneDetection::edgeDetector(cv::Mat image_filter) {
  cv::Mat image_output;
  // Apply Canny edge detector
  Canny(image_filter, image_output, 185, 250, 3);
  return image_output;
}

/**
  * @brief Extract region of interest
  * @param input_edge Input image  with edge detected
  * @return Image with region of interest
  */

cv::Mat LaneDetection::roiExtract(cv::Mat image_edge) {
  cv::Mat image_output;
  cv::Mat roi_mask = cv::Mat::zeros(image_edge.size(), image_edge.type());
  cv::Point points[4] = {
      cv::Point(212, 720),
      cv::Point(550, 450),
      cv::Point(710, 450),
      cv::Point(1280, 720)
  };

  // Create a binary polygon mask
  cv::fillConvexPoly(roi_mask, points, 4, cv::Scalar(255, 0, 0));
  // Multiply the edges image and the mask to get the output
  cv::bitwise_and(image_edge, roi_mask, image_output);

  return image_output;
}

/**
   * @brief Find lines on the image
   * @param input_roi Input image with region of interest
   * @return detected line
   */


std::vector<cv::Vec4i> LaneDetection::getLines(cv::Mat image_roi) {
  std::vector<cv::Vec4i> line;
  // Apply Hough Transform
  HoughLinesP(image_roi, line, 1, CV_PI/180, 20, 20, 30);
  return line;
}

/**
   * @brief Do the line fitting
   * @param input_roi Input image with region of interest
   * @return detected line
   */


std::vector<cv::Point> LaneDetection::lineFitting(std::vector<cv::Vec4i>
                                                lines, cv::Mat image_edge) {;
  cv::Point initial_point, final_point;
  std::vector<cv::Point> right_points, left_points;
  std::vector<cv::Point> output(4);
  cv::Vec4d right_line, left_line;
  // Calculate image centers
  imageCenterX_ = (image_edge.cols / 2);
  imageCenterY_ = (image_edge.rows / 2);

  for (auto i : lines) {
    initial_point = cv::Point(i[0], i[1]);
    final_point = cv::Point(i[2], i[3]);
    // Calculate slope = (y1 - y0)/(x1 - x0)
    double slope = (final_point.y - initial_point.y)/
                            (final_point.x - initial_point.x + 0.00001);
    if (slope > 0.5 && final_point.x > imageCenterX_ &&
                                           initial_point.x > imageCenterX_) {
      right_points.push_back(initial_point);
      right_points.push_back(final_point);
    } else if (slope < -0.5  && final_point.x < imageCenterX_ &&
                                            initial_point.x < imageCenterX_) {
        left_points.push_back(initial_point);
        left_points.push_back(final_point);
    }
  }
  if (right_points.size() > 0) {
      // The right line is formed here
      cv::fitLine(right_points, right_line, CV_DIST_L2, 0, 0.01, 0.01);
      rightSlope_ = right_line[1] / right_line[0];
      rightIntercept_ = cv::Point(right_line[2], right_line[3]);
    }
  if (left_points.size() > 0) {
      // The left line is formed here
      cv::fitLine(left_points, left_line, CV_DIST_L2, 0, 0.01, 0.01);
      leftSlope_ = left_line[1] / left_line[0];
      leftIntercept_ = cv::Point(left_line[2], left_line[3]);
    }

  int initial_point_y = image_edge.rows;
  int final_y = 470;
  double right_initial_point_x = ((initial_point_y - rightIntercept_.y) /
                                            rightSlope_) + rightIntercept_.x;
  double right_final_x = ((final_y - rightIntercept_.y) /
                                            rightSlope_) + rightIntercept_.x;
  double left_initial_point_x = ((initial_point_y - leftIntercept_.y) /
                                            leftSlope_) + leftIntercept_.x;
  double left_final_x = ((final_y - leftIntercept_.y) /
                                            leftSlope_) + leftIntercept_.x;
  // Storing the points
  output[0] = cv::Point(right_initial_point_x, initial_point_y);
  output[1] = cv::Point(right_final_x, final_y);
  output[2] = cv::Point(left_initial_point_x, initial_point_y);
  output[3] = cv::Point(left_final_x, final_y);
  return output;
}

/**
   * @brief Predict the turn
   * @param thresh_vanish Threshhold for deciding vanishing point
   * @return turn prediction : left, right or straight turn
   */

std::string LaneDetection::turnPrediction(double thresh_vanish) {
  std::string text_output;
  // Calculate vanihing point x and y
  vanishPointX_ = ((rightSlope_*rightIntercept_.x) -
                 (leftSlope_*leftIntercept_.x)
      - rightIntercept_.y + leftIntercept_.y) / (rightSlope_ - leftSlope_);
  vanishPointY_ = ((vanishPointX_*leftSlope_) -(leftSlope_*leftIntercept_.x)
                                     + leftIntercept_.y);
  // Predict turn
  if (vanishPointX_ < (imageCenterX_ - thresh_vanish))
    text_output = "Left Turn";
  else if (vanishPointX_ > (imageCenterX_ + thresh_vanish))
    text_output = "Right Turn";
  else if (vanishPointX_ >= (imageCenterX_ - thresh_vanish)
          && vanishPointX_ <= (imageCenterX_ + thresh_vanish))
    text_output = "Straight";
  return text_output;
}

/**
   * @brief Calculate the drive heading
   * @param None
   * @return None
   */

double LaneDetection::driveHeading() {
  double drive_heading = atan2((imageCenterX_ - vanishPointX_), vanishPointY_)
                                * 180 / PI;
  return drive_heading;
}

int runLane(std::string filename , int no_of_frames, bool show_plot) {
  return 0;
}

