#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"
#include "../include/LaneDetection.hpp"
#include "../include/PlotManager.hpp"
#include "../include/SystemManager.hpp"


using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class MockLD : public LaneDetection {
public:
    MockLD() {}

    MOCK_METHOD1(turnPrediction, std::string (double));
    //MOCK_METHOD2(filter,cv::Mat(cv::Mat));
    MOCK_METHOD0(driveHeading, double());
    MOCK_METHOD1(success , bool ( double ));

};




TEST(MockLDTest , PredictionTest) {

    MockLD mld;
    SystemManager sm;

    EXPECT_CALL(mld, turnPrediction(10))
    .Times(1);

    EXPECT_CALL(mld, driveHeading())
    .Times(1);



    int value = sm.runLane("../input/project_video.mp4" ,600, false);
    EXPECT_EQ(value,0);

}


int main(int argc, char** argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
