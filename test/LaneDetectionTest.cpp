/**
* @file LaneDetectionTest.cpp
* @brief LaneDetection and PlotManager unit test
* @details Implementation of unit test for LaneDetection and PlotManager class
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/


#include <gtest/gtest.h>
#include <tuple>
#include "../include/LaneDetection.hpp"
#include "../include/PlotManager.hpp"


/**
* @brief Run the methods of LaneDetction class
* @param frame_number Number of frames to be processed
* @return Turn prediction and drive heading
*/

std::tuple<double, std::string> LaneTest(int frame_number) {
    LaneDetection lanedetector;
    PlotManager plotmanager;
    cv::Mat frame;
    std::string turn;
    cv::VideoCapture cap("../input/project_video.mp4");
    cap.set(cv::CAP_PROP_POS_FRAMES, frame_number);
    cap.read(frame);
    cv::Mat image_filter = lanedetector.filter(frame);
    cv::Mat image_edge = lanedetector.edgeDetector(image_filter);
    cv::Mat image_roi = lanedetector.roiExtract(image_edge);
    std::vector<cv::Vec4i> lines = lanedetector.getLines(image_roi);
    std::vector<cv::Point> lane = lanedetector.lineFitting(lines, frame);
    turn = lanedetector.turnPrediction(10);
    double drive_heading = lanedetector.driveHeading();
    plotmanager.plot(frame, lane, turn , drive_heading, false);
    std::tuple<double, std::string> result(drive_heading, turn);
    return result;
}

 /**
 * @brief Test for correct left turn prediction
 */

TEST(LaneTest, LeftTurn) {
  std::tuple<double, std::string>  result = LaneTest(5);
  EXPECT_EQ(std::get<1>(result), "Left Turn");
}

 /**
 * @brief Test for correct straight prediction
 */

TEST(LaneTest, NoTurn) {
  std::tuple<double, std::string>  result = LaneTest(525);
  EXPECT_EQ(std::get<1>(result), "Straight");
}

 /**
 * @brief Test for correct right turn prediction
 */

TEST(LaneTest, RightTurn) {
  std::tuple<double, std::string>  result = LaneTest(750);
  EXPECT_EQ(std::get<1>(result), "Right Turn");
}

/**
 * @brief Test for drive heading value
 */


TEST(LaneTest, drive_head) {
  std::tuple<double, std::string>  result = LaneTest(525);
  EXPECT_NEAR(std::get<0>(result), 0.3 , 0.2);
}



