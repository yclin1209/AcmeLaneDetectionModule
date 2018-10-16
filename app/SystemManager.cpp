/**
* @file SystemManager.cpp
* @brief SystemManager class
* @details Implementation of SystemManager class
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/
#include <string>
#include <vector>
#include "opencv2/opencv.hpp"
#include "../include/SystemManager.hpp"
#include <opencv2/highgui/highgui.hpp>



SystemManager::SystemManager(){}

SystemManager::~SystemManager(){}

int SystemManager::runLane(std::string filename, int no_of_frames, bool show_plot) {
  cv::VideoCapture capture(filename);
  if (!capture.isOpened())
    return -1;
  cv::Mat frame;
  for (int i= 0 ; i < no_of_frames ; i++){

    if (!capture.read(frame)) {
      std::cout<<"No frame to process";
      break;
    }
    cv::Mat image_filter = lanedetection_.filter(frame);
    cv::Mat image_edge = lanedetection_.edgeDetector(image_filter);
    cv::Mat image_roi = lanedetection_.roiExtract(image_edge);
    std::vector<cv::Vec4i>  lines = lanedetection_.getLines(image_roi);

    if (!lines.empty()) {
      std::vector<cv::Point>  lane = lanedetection_.lineFitting(lines, image_roi);
      std::string turn = lanedetection_.turnPrediction(10);
      double drive_heading = lanedetection_.driveHeading();
      plot_.plot(frame, lane, turn,drive_heading, show_plot);
      cv::waitKey(20);
    }
    else {
      std::cout<<" NO lane Detected"<<std::endl;
    }

  }
  cv::destroyAllWindows();
  return 0;
}





