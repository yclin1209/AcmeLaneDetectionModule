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
#include <opencv2/cudaimgproc.hpp>

#include <cstdio>

//extern double direction;

#define SHOW_FPS 0

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
#if SHOW_FPS
  static double fps=0;
  char string[10];
  static double t=0;
  static double avgDuration = 0.f;
#endif


  extern double direction;

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

#if SHOW_FPS
        t = (double) cv::getTickCount();
#endif
 
    	// Do image filtering
    	cv::Mat image_filter = lanedetection_.filter(frame);
    	
        // Do edge detection
#if 1
    	cv::Mat image_edge = lanedetection_.edgeDetector(image_filter);
#else
        cv::Ptr<cv::cuda::CannyEdgeDetector> canny = cv::cuda::createCannyEdgeDetector(185,250,3);
        cv::cuda::GpuMat image_edge_gpu,image_filter_gpu;
        cv::cvtColor(image_filter,image_filter, cv::COLOR_BGR2GRAY);
        image_filter_gpu.upload(image_filter);
        canny->detect(image_filter_gpu,image_edge_gpu);
        cv::Mat image_edge;
        image_edge_gpu.download(image_edge);
#endif
    	
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
            direction = drive_heading;
      
            // Plot the lane, turn direction and heading angle
            plot_.plot(frame, lane, turn, drive_heading, show_plot);
            
            cv::waitKey(1);//delay?

        } else {
        
            std::cout << " NO lane Detected" << std::endl;
        }

#if SHOW_FPS
        avgDuration += (( (double) cv::getTickCount() - t ) / cv::getTickFrequency() 
                        - avgDuration) * 0.1f;
        fps = 1.f / avgDuration ;
        std::sprintf(string, "%.1f", fps);
        //std::string fpsString("FPS:");
        //fpsString += string;
        printf("fps: %.1f\n", fps);
#endif

  }

  cv::destroyAllWindows();

  return 0;

}





