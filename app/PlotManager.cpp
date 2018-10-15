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
  // Use putText function to plot.
  // fillConvexPoly to fill the lane



}




