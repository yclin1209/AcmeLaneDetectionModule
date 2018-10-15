/**
* @file PlotManager.hpp
* @brief PlotManager class
* @details Definition of PlotManager class
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/

#ifndef INCLUDE_PLOTMANAGER_HPP_
#define INCLUDE_PLOTMANAGER_HPP_

#include <string>
#include <vector>
#include "opencv2/opencv.hpp"

/**
* @brief Class for PlotManager
*/


class PlotManager {
    public:
        /**
        * Constructor to initialize
        */
        PlotManager();
        /**
        * Destructor 
        */
        ~PlotManager();
        /**
        * @brief Method to plot the lane and drive heading on input image
        * @param input_image Input image
        * @param line_fit Both lane which are to be plotted
        * @param turnDirection Turn direction left, right or straight
        * @param drive_heading Drive heading value
        */

        void  plot(cv::Mat input_image, std::vector<cv::Point> line_fit, std::string turnDirection, double drive_heading);

};



#endif //INCLUDE_PLOTMANAGER_HPP_

