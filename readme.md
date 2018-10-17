# Lane Detection for Autonomous Vehicle
[![Build Status](https://travis-ci.org/Indushekhar/AcmeLaneDetectionModule.svg?branch=master)](https://travis-ci.org/Indushekhar/AcmeLaneDetectionModule)
[![Coverage Status](https://coveralls.io/repos/github/Indushekhar/AcmeLaneDetectionModule/badge.svg)](https://coveralls.io/github/Indushekhar/AcmeLaneDetectionModule)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)



---
## Overview
The objective of this project was to design a lane detection (with lane turn signal and
drive heading output) system for autonomous vehicles/Robots. The proposed lane
detection algorithm by using a video feed input of a vehicle driving on the highway, detects the lane position and give drive heading angle. Which in turn can be
passed to steering control system to move the vehicle inside the lane. Maintaining
the lane on highway is very critical for autonomics vehicles. The system can be also
be integrated with the popular Lane departure warning system designed to warn the
driver when the vehicle begins to move out of its lane. The system being developed
in C++ language provides very good real time performance.

 ![Test Image 1](https://github.com/Indushekhar/AcmeLaneDetectionModule/blob/master/images/ezgif.com-video-to-gif.gif) 

## Pipeline and Results 

The pipeline of the project can be summarized as :

## 1.Filter the Image

First step is to remove the noise using median filter. This smooths the image and removes any undesired pixel values that could prevent the correct detection of the lanes

## 2.Apply edge detection to extract vertical edges

Then apply edge detector to extract vertical edge. The intermediate output after edge detection is shown below

 ![Test Image 2](https://github.com/Indushekhar/AcmeLaneDetectionModule/blob/master/images/edge.png) 


## 3.Extract the Region Of Interest

As the image from previous step contains extra information which we do not need for lane finding, we extract the Region Of Interest.

![Test Image 2](https://github.com/Indushekhar/AcmeLaneDetectionModule/blob/master/images/roi.png) 



## 4. Find lines using Hough Transform

In this step we use Hough Transform to find lines on the image. Some paramter tuning is done to 


## 5. Fit line
In this step , we find out the peak hough lines, group them into two groups (positive,
negative gradients) and extrapolate lines in each group.

## 6. Predict turn and Calculate drive head

Using the intersection point of left and right lines, we get the vanishing point. Based on vanishing point and image center we predict the turns in the lane.

## 7. Plot the lane and drive head

![Test Image 2](https://github.com/Indushekhar/AcmeLaneDetectionModule/blob/master/images/plot_normal.png) 




## Standard install via command-line

'''
git clone --recursive https://github.com/Indushekhar/AcmeLaneDetectionModule
cd <path to repository>
mkdir build
cd build
cmake ..
make

Run tests: ./test/system-test
Run program: ./app/main

```

## Dependencies
1. OpenCV 3.3.0. This can be downloaded by following the steps of this [link](https://www.learnopencv.com/install-opencv3-on-ubuntu/)

## Dataset
The dataset used for the system evaluation is taken from Advanced Lane Detection dataset from Udacity - Self Driving Nanodegree
program. The dataset can be downloaded from the link below :


https://drive.google.com/drive/folders/1XR0v4H73xvUQDT92OO_ud9MVqnTNOXJO?usp=sharing

## Solo Iterative Process and Sprint Planning

Sprint planning details can be found on the following link.

https://docs.google.com/document/d/1Fxr27H92AX2Sr3t2H6NpyOqamlBIBs7oRIrZiXUN6i0/edit?usp=sharing


The software is being be developed by following the Solo Iterative Process(SIP). A product backlog, release backlog and 
work log(time log and code defect log) is being used as structure of the whole project. The log can be viewed at following link :

https://docs.google.com/spreadsheets/d/1IO5K6LXyBzSSsjxovvstrDoHjlVawQgHOqON_L0iJLY/edit?usp=sharing

## Doumentation

To generate documentation install dependencies first 

```
$ sudo apt-get install doxygen
$ sudo apt-get install doxygen-gui
$ doxywizard

```
It will open gui version. On the top of the gui window, It will required a working directory. Set the directory. Give the source folder path and check the recursive checkbox. Give target directory to save the documentations files.


## License

MIT License

Copyright (c) 2018 Indushekhar Singh

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
