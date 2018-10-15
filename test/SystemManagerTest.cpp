/**
* @file SystemManagerTest.cpp
* @brief SystemManager unit test
* @details Implementation of unit test for SystemManager class
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/

#include <gtest/gtest.h>
#include "../include/SystemManager.hpp"



TEST(SystemManager, CompleteSystemTest) {
  SystemManager systemanager_;
  auto output = systemanager_.runLane("../build/project_video.mp4" , 1);
  EXPECT_EQ(0, output);
}

TEST(SystemManager, FileReadTest) {
  SystemManager systemanager_;
  auto output = systemanager_.runLane("../project_video.mp4" , 1);
  EXPECT_EQ(-1, output);
}

TEST(SystemManager, FrameExceedTest) {
  SystemManager systemanager_;
  auto output = systemanager_.runLane("../build/test.mp4" , 400);
  EXPECT_EQ(0, output);
}

TEST(SystemManager, NoDetectionTest) {
  SystemManager systemanager_;
  auto output = systemanager_.runLane("../build/test.mp4" ,10);
  EXPECT_EQ(0, output);
}

