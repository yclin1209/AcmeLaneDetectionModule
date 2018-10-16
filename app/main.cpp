
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "opencv2/opencv.hpp"
#include "../include/SystemManager.hpp"


int main() {
    SystemManager laneDetection;
    laneDetection.runLane("../input/project_video.mp4", 800);

    return 0;
}
