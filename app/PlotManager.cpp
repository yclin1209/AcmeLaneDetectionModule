/**
* @file PlotManager.cpp
* @brief PlotManager class
* @details Implementation of PlotManager class
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/

#include <string>
#include <vector>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "../include/PlotManager.hpp"

/**
 * @brief      Constructs the object.
 */

PlotManager::PlotManager() {}

/**
 * @brief      Constructs the object.
 */

PlotManager::~PlotManager() {}

/**
* @brief Plot the lane and drive heading on input image
* @param input_image Input image
* @param line_fit Both lane which are to be plotted
* @param turnDirection Turn direction left, right or straight
* @param drive_heading Drive heading value
* @param show_plot whether to show plot or not
* @return None
*/

void PlotManager::plot(cv::Mat inputImage, std::vector<cv::Point> lane,
           std::string turn, double drive_heading, bool show_plot) {

#if 1 // to show lane and text on output image
  std::vector<cv::Point> ploygon_points;
  cv::Mat output_image;

  // Convert double to string
  auto head_text = std::to_string(drive_heading);

  inputImage.copyTo(output_image);
  
  // Store the points
  ploygon_points.push_back(lane[2]);
  ploygon_points.push_back(lane[0]);
  ploygon_points.push_back(lane[1]);
  ploygon_points.push_back(lane[3]);

  cv::fillConvexPoly( output_image, ploygon_points,
                      	cv::Scalar(255, 0, 255), cv::LINE_AA, 0 );

  cv::addWeighted( output_image, 0.3, inputImage, 1.0 - 0.3, 0, inputImage );

  cv::line( inputImage, lane[0], lane[1], cv::Scalar(0, 255, 255), 4, cv::LINE_AA );

  cv::line( inputImage, lane[2], lane[3], cv::Scalar(0, 255, 255), 4, cv::LINE_AA );

  cv::putText( inputImage, turn, cv::Point(50, 90), cv::FONT_HERSHEY_COMPLEX_SMALL, 2,
               cv::Scalar(255, 255, 0), 1, cv::LINE_AA );

  cv::putText( inputImage, "DriveHead ( + left -right )=" + head_text,cv::Point(50, 45), 
	       cv::FONT_HERSHEY_COMPLEX_SMALL, 2,cv::Scalar(255, 255, 0), 1, cv::LINE_AA );
#endif

  if (show_plot) {
#define SCREEN_W 1920
#define SCREEN_H 1080
#define BORDER 0
    cv::namedWindow( "LaneDetection", cv::WINDOW_NORMAL );
    cv::setWindowProperty( "LaneDetection", cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN );
    cv::resizeWindow("LaneDetection", SCREEN_W + BORDER, SCREEN_H + BORDER);
    cv::imshow( "LaneDetection", inputImage );
  }

}




