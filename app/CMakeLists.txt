FIND_PACKAGE( OpenCV REQUIRED )
add_executable(main main.cpp LaneDetection.cpp SystemManager.cpp PlotManager.cpp)
TARGET_LINK_LIBRARIES( main ${OpenCV_LIBS} )
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)
