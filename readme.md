# Lane Detection for Autonomous Vehicle
[![Build Status](https://travis-ci.org/Indushekhar/AcmeLaneDetectionModule.svg?branch=master)](https://travis-ci.org/Indushekhar/AcmeLaneDetectionModule)
[![Coverage Status](https://coveralls.io/repos/github/Indushekhar/AcmeLaneDetectionModule/badge.svg?branch=master)](https://coveralls.io/github/Indushekhar/AcmeLaneDetectionModule?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)



---
## Overview
The objective of this project is to design a lane detection (with lane turn signal and
drive heading output) system for autonomous vehicles/Robots. The proposed lane
detection algorithm by using a video feed input of a vehicle driving on the highway,
will detect the lane position and give drive heading angle. Which in turn can be
passed to steering control system to move the vehicle inside the lane. Maintaining
the lane on highway is very critical for autonomics vehicles. The system can be also
be integrated with the popular Lane departure warning system designed to warn the
driver when the vehicle begins to move out of its lane. The system being developed
in C++ language will provide very good real time performance.

## Standard install via command-line
git clone --recursive https://github.com/Indushekhar/AcmeLaneDetectionModule
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/system-test
Run program demo : ./app/main

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
