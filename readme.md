# Object Detection using SIFT features
[![Build Status](https://travis-ci.org/rishabh1b/808XMidtermProject.svg?branch=master)](https://travis-ci.org/rishabh1b/808XMidtermProject)
[![Coverage Status](https://coveralls.io/repos/github/rishabh1b/808XMidtermProject/badge.svg?branch=master)](https://coveralls.io/github/rishabh1b/808XMidtermProject?branch=master)
---

## Overview

A C++ project to segment a know box and return its centroid position. This project was implemented to learn about the software evolution process as part of the course ENPM808X at University of Maryland. Specifically, this project is being implemented in a one week sprint following SIP (Solo Iterative Process). The details about my experiments with this methodology is shown here at this link - 
[SIP](https://docs.google.com/spreadsheets/d/1hU2-KZ__otXOmWfRZpa-UvZP8Up15Qzi-F7m8GVSgRQ/edit?usp=sharing)
The project was motivated on a context that the component is being developed for a imaginary Robotics company - "Acme Robotics". My focus was on the perception module wherin I was developing a modular component to detect a *known* object from the environment. I chose household environment and a corn-flakes box for segmentation. Firstly, Object detection in principle is a combination of *Object Recognition* and then finding the actual location of this object. For Object Recognition part I used SIFT features and homography technique to get hold of the bounding box across the object. Then I find the centroid of the object by taking midpoint of these corners. 

The output is illustrated in the animation below - 
<p align="center">
  <img src="https://github.com/rishabh1b/808XMidtermProject/blob/master/results/output.gif?raw=true" alt="Bounding box and centroid estimation"/>
</p>
Essentially, this piece of software returns the centroid of the object detected. To use this piece of software for your own object, simply add a image of the object in the data folder and add path to this image in *SiftDetector* cpp file
Since, there was a restriction on the use of hardware, I ran the algorithm on a video file. Once, we have a calibrated camera we simply have to map the centroid values according to how many pixels correspond to how many mm. This will give the X, Y co-ordinates. The depth Z can either be estimated by calibrating the size of bounding box as a function of actual distance or by using a depth camera. 

At present, there are clearly two questions that one can think of. First, is the detection robust enough and can it be more general. Second, how can I port this code to an actual hardware? For the first question, yes the detection is not 100 % robust. This type of object detection now is being categorized as *traditional* object detection algorithms. To make it more general, we should be using a more state of the art deep learning algorithms. To make sure that the augmenting of exisiting implementation is simpler, I have followed 
*Open for Extension* principle. The base class called ObjectDetector is made abstract and the new classes we add simply have to extend this class with the promise that they will implement the **detect** pure virtual method. For camera integration the class **VideoFrame** is made general and it simply a matter of calling a different overloaded constructor for getting frames camera instead of video file.

## Standard install via command-line
```
git clone --recursive https://github.com/dpiet/cpp-boilerplate
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Dependencies
1. OpenCV 3.3.0. This can be downloaded by following the steps [here](https://www.learnopencv.com/install-opencv3-on-ubuntu/).

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/dpiet/cpp-boilerplate
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../cpp-boilerplate/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want 
the program to break).

2. In Eclipse, right click on the boilerplate-eclipse in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).

Note that the output video and images might not get generated through eclipse (because of debug mode). To get the outputs run the software through the command line using instructions mentioned at the top.

### Documentation
1. Detailed documentation can be found under ```/doc/html/index.html```. 
2. To generate documentation, run ```sudo apt-get install doxygen-gui```. This is basically a GUI for doxygen. Once installed, run 
```doxywizard``` on the command line to launch the application. Then four steps to generate the documention are self-explanatory as in the wizard.
