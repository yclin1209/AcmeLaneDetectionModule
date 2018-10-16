/**
* @file SystemManager.hpp
* @brief SystemManager class
* @details Definition of SystemManager class
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/

#ifndef INCLUDE_SYSTEMANAGER_HPP_
#define INCLUDE_SYSTEMANAGER_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "LaneDetection.hpp"
#include "PlotManager.hpp"

class SystemManager {

private:
    LaneDetection  lanedetection_;
    PlotManager plot_;


public:
    SystemManager();
    ~SystemManager();
    int runLane(std::string filename , int no_of_frames, bool show_plot);
};


#endif // INCLUDE_SYSTEMANAGER_HPP_

