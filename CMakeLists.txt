cmake_minimum_required(VERSION 3.2.1)
project (scratch)

# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

find_package( OpenCV REQUIRED)

# We probably don't want this to run on every build.
option(COVERAGE "Generate Coverage Data" OFF)

if (COVERAGE)
    include(CodeCoverage)
    set(LCOV_REMOVE_EXTRA "'vendor/*'")
    setup_target_for_coverage(code_coverage test/system-test coverage)
    set(COVERAGE_SRCS app/main.cpp /app/LaneDetection.cpp /app/PlotManager.cpp /app/SystemManager.cpp /include/LaneDetection.hpp /include/PlotManager.hpp /include/SystemManager.hpp)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")
endif()

link_directories(/usr/local/lib)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -lhidapi-hidraw")
#TARGET_LINK_LIBRARIES(hidapi-hidraw)
link_libraries("/usr/local/lib/libhidapi-hidraw.so")

include(CMakeToolsHelpers OPTIONAL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(app)
# add_subdirectory(test)
# add_subdirectory(vendor/googletest/googletest)
