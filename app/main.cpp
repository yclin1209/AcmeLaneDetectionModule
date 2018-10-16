/**
* @file main.cpp
* @brief main script
* @details Used to run the system
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/

#include <iostream>
#include <string>
#include <vector>
#include "../include/SystemManager.hpp"

int main() {
    SystemManager laneDetection;
    laneDetection.runLane("../input/project_video.mp4", 800, true);

    return 0;
}
