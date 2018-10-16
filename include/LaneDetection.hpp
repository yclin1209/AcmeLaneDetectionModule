/**
* @file LaneDetection.hpp
* @brief LaneDetection class
* @details Definition of LaneDetection class
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/

#ifndef INCLUDE_LANEDETECTION_HPP_
#define INCLUDE_LANEDETECTION_HPP_

#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "opencv2/opencv.hpp"

/**
* @brief Class for LaneDetection
*/


class LaneDetection {
 private:
  double imageCenterX_= 0.0;
  double imageCenterY_= 0.0;
  double leftSlope_ = 0.0;
  double rightSlope_= 0.0;
  cv::Point leftIntercept_;
  cv::Point rightIntercept_;
  double vanishPointX_ = 0.0;
  double vanishPointY_ = 0.0;

 public:
  /**
  * @brief Constructor to initialize the object
  */
  LaneDetection();

  /**
  * @brief Destroys the object.
  */

  ~LaneDetection();

  /**
  * @brief Method to do image filtering
  * @param input_image Input image frame to be filtered
  * @return Filtered Image
  */

  cv::Mat filter(cv::Mat input_image);

  /**
  * @brief Method to do edge detection
  * @param input_filter Input image frame
  * @return Image with edge detected
  */

  cv::Mat edgeDetector(cv::Mat image_filter);

  /**
  * @brief Method to do extract region of interest
  * @param input_edge Input image  with edge detected
  * @return Image with region of interest
  */

  cv::Mat roiExtract(cv::Mat image_edge);

  /**
   * @brief Method to do find line in the image
   * @param input_roi Input image with region of interest
   * @return detected line
   */

  std::vector<cv::Vec4i> getLines(cv::Mat image_roi);

  /**
   * @brief Method to do fit a single line in the image
   * @param input_roi Input image with region of interest
   * @return detected line
   */

  std::vector<cv::Point> lineFitting(std::vector<cv::Vec4i> lines, cv::Mat input_image);
  std::string turnPrediction(double thresh_vanish);
  double driveHeading();

};

#endif //INCLUDE_LANEDETECTION_HPP_

