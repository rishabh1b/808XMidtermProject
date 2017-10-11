# Object Detection using SIFT features
[![Build Status](https://travis-ci.org/rishabh1b/808XMidtermProject.svg?branch=master)](https://travis-ci.org/rishabh1b/808XMidtermProject)
[![Coverage Status](https://coveralls.io/repos/github/rishabh1b/808XMidtermProject/badge.svg?branch=master)](https://coveralls.io/github/rishabh1b/808XMidtermProject?branch=master)
---

## Overview

A C++ project to segment a know box and return its centroid position. This project was implemented to learn about the software evolution process as part of the course ENPM808X at University of Maryland. Specifically, this project is being implemented in a one week sprint following SIP (Solo Iterative Process). The details about my experiments with this methodology is shown here at this link - 
[SIP](https://docs.google.com/spreadsheets/d/1hU2-KZ__otXOmWfRZpa-UvZP8Up15Qzi-F7m8GVSgRQ/edit?usp=sharing)

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

