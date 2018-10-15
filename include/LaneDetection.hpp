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
  LaneDetection();
  ~LaneDetection();
  cv::Mat filter(cv::Mat input_image);
  cv::Mat edgeDetector(cv::Mat image_filter);
  cv::Mat roiExtract(cv::Mat image_edge);
  std::vector<cv::Vec4i> getLines(cv::Mat image_roi);
  std::vector<cv::Point> lineFitting(std::vector<cv::Vec4i> lines, cv::Mat input_image);
  std::string turnPrediction(double thresh_vanish);
  double driveHeading();

};

#endif //INCLUDE_LANEDETECTION_HPP_

