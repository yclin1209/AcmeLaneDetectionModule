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
#include "../include/SystemManager.hpp"
#include <opencv2/highgui/highgui.hpp>

/**
 * @brief      Constructs the object.
 */

SystemManager::SystemManager() {}

/**
 * @brief      Destroys the object.
 */

SystemManager::~SystemManager() {}

 /**
  * @brief run the complete lane detection system
  * @param filename Path to the input video to be tested
  * @param  no_of_frames Number of frames to be processed
  * @param show_plot Whether to show the frames or not
  */

int SystemManager::runLane(std::string filename, int no_of_frames,
                                                   bool show_plot) {
  // capture the video frame
  cv::VideoCapture capture(filename);
  // Check if captured succefully
  if (!capture.isOpened())
    return -1;
  cv::Mat frame;
  for (int i= 0 ; i < no_of_frames ; i++) {
    // Check if frame is avialable
    if (!capture.read(frame)) {
      std::cout << "No frame to process";
      break;
    }
    // Do image filtering
    cv::Mat image_filter = lanedetection_.filter(frame);
    // Do edge detection
    cv::Mat image_edge = lanedetection_.edgeDetector(image_filter);
    // Extract region of interest
    cv::Mat image_roi = lanedetection_.roiExtract(image_edge);
    // Get lines
    std::vector<cv::Vec4i>  lines = lanedetection_.getLines(image_roi);
    // Check if line found
    if (!lines.empty()) {
      // Fit the line
      std::vector<cv::Point>  lane =
                                lanedetection_.lineFitting(lines, image_roi);
      // Predit turn
      std::string turn = lanedetection_.turnPrediction(10);
      // Calculate drive heading
      double drive_heading = lanedetection_.driveHeading();
      // Plot the lane, turn direction and heading angle
      plot_.plot(frame, lane, turn, drive_heading, show_plot);
      cv::waitKey(20);
    } else {
      std::cout << " NO lane Detected" << std::endl;
    }
  }
  cv::destroyAllWindows();
  return 0;
}





