/**
* @file SystemManager.hpp
* @brief SystemManager class
* @details Definition of SystemManager class
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/

#ifndef INCLUDE_SYSTEMMANAGER_HPP_
#define INCLUDE_SYSTEMMANAGER_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "LaneDetection.hpp"
#include "PlotManager.hpp"


/**
* @brief Class for LaneDetection
*/


class SystemManager {
 private:
    LaneDetection  lanedetection_;
    PlotManager plot_;

 public:
   /**
   * @brief Constructor to initialize the object
   */
    SystemManager();

  /**
  * @brief Destroys the object.
  */

    ~SystemManager();

  /**
  * @brief Method for running the whole LaneDetection system
  * @param filename Path to the input video to be tested
  * @param  no_of_frames Number of frames to be processed
  * @param show_plot Whether to show the frames or not
  */

    int runLane(std::string filename , int no_of_frames, bool show_plot);
};

#endif  // INCLUDE_SYSTEMMANAGER_HPP_

