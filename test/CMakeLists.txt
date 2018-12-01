set(GTEST_SHUFFLE 1)

add_executable(
    system-test
    MockTest.cpp
    ../app/LaneDetection.cpp
    ../app/PlotManager.cpp
    ../app/SystemManager.cpp
    
    
)

target_include_directories(system-test PUBLIC ../vendor/googletest/googlemock/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(system-test PUBLIC gmock gtest ${OpenCV_LIBS})
