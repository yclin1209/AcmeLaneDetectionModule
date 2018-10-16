set(GTEST_SHUFFLE 1)

add_executable(
    system-test
    main.cpp
    LaneDetectionTest.cpp
    SystemManagerTest.cpp
    ../app/LaneDetection.cpp
    ../app/PlotManager.cpp
    ../app/SystemManager.cpp
    
)

target_include_directories(system-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(system-test PUBLIC gtest ${OpenCV_LIBS})
