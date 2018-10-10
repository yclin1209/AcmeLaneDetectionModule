# Lane Detection for Autonomous Vehicle
[![Build Status](https://travis-ci.org/Indushekhar/AcmeLaneDetectionModule.svg?branch=master)](https://travis-ci.org/Indushekhar/AcmeLaneDetectionModule)
[![Coverage Status](https://coveralls.io/repos/github/Indushekhar/AcmeLaneDetectionModule/badge.svg?branch=master)](https://coveralls.io/github/Indushekhar/AcmeLaneDetectionModule?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)



---

## Note 

This Project is still in development phase. Build and run instruction coming soon.

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

## Dataset
The dataset used for the system evaluation is taken from Advanced Lane Detection dataset from Udacity - Self Driving Nanodegree
program. The dataset can be downloaded from the link below :


https://drive.google.com/drive/folders/1XR0v4H73xvUQDT92OO_ud9MVqnTNOXJO?usp=sharing

## Solo Iterative Process

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
