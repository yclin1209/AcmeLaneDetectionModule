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
#include "opencv2/opencv.hpp"
#include "../include/PlotManager.hpp"
#include <iostream>

PlotManager::PlotManager(){}
PlotManager::~PlotManager(){}


void PlotManager::plot(cv::Mat inputImage, std::vector<cv::Point> lane, std::string turn, double drive_heading) {
  std::vector<cv::Point> ploygon_points;
  cv::Mat output_image;

  auto head_text = std::to_string(drive_heading);

  inputImage.copyTo(output_image);
  ploygon_points.push_back(lane[2]);
  ploygon_points.push_back(lane[0]);
  ploygon_points.push_back(lane[1]);
  ploygon_points.push_back(lane[3]);
  cv::fillConvexPoly(output_image, ploygon_points, cv::Scalar(255, 0, 255), CV_AA, 0);
  cv::addWeighted(output_image, 0.3, inputImage, 1.0 - 0.3, 0, inputImage);


  cv::line(inputImage, lane[0], lane[1], cv::Scalar(0, 255, 255), 4, CV_AA);
  cv::line(inputImage, lane[2], lane[3], cv::Scalar(0, 255, 255), 4, CV_AA);

  cv::putText(inputImage, turn, cv::Point(50, 90), cv::FONT_HERSHEY_COMPLEX_SMALL, 2, cvScalar(255, 255, 0), 1, CV_AA);
  cv::putText(inputImage, "DriveHead (+ left -right )=" + head_text  , cv::Point(50, 45), cv::FONT_HERSHEY_COMPLEX_SMALL, 2, cvScalar(255, 255, 0), 1, CV_AA);

  cv::namedWindow("LaneDetection", CV_WINDOW_AUTOSIZE);
  cv::imshow("LaneDetection", inputImage);

}




