/**
* @file LaneDetection.cpp
* @brief LaneDetection class
* @details Implementation of LaneDetection class
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/


#include <string>
#include <vector>
#include <math.h>
#include "opencv2/opencv.hpp"
#include "../include/LaneDetection.hpp"




LaneDetection::LaneDetection() {}

LaneDetection::~LaneDetection() {}


cv::Mat LaneDetection::filter(cv::Mat input_image) {
  cv::Mat image_output;
  // DO image Filtering Here
  return image_output;
}


cv::Mat LaneDetection::edgeDetector(cv::Mat image_filter) {
  cv::Mat image_output;
  // Do edge detection here

  return image_output;
}


cv::Mat LaneDetection::roiExtract(cv::Mat image_edge) {
  cv::Mat image_output;
  // Extract the Image output
  return image_output;
}


std::vector<cv::Vec4i> LaneDetection::getLines(cv::Mat image_roi) {
  std::vector<cv::Vec4i> line;

  // Detect line using HoughlineP

  return line;
}


std::vector<cv::Point> LaneDetection::lineFitting(std::vector<cv::Vec4i> lines, cv::Mat image_edge) {
  std::vector<cv::Point> output(4);
  // Do some filtering to avoid undesirbale slope
  // Segeregate in right and left lines
  // Fit the line using cv::fitLine


  return output;
}


std::string LaneDetection::turnPrediction(double thresh_vanish) {
  std::string text_output;
  // Predict turn using vanishing point

  return text_output;
}

double LaneDetection::driveHeading() {
  double drive_heading ;

  // Calulate the heading using simple trigonometry

  return drive_heading;

}


