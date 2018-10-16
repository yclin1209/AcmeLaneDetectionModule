/**
* @file main.cpp
* @brief main script for unit test
* @details Used to run all the unit test
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
