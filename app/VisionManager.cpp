/*
 * VisionManager.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: viki
 */

#include "VisionManager.h"

VisionManager& VisionManager::get(){
  static VisionManager visManager;
  return visManager;
}

VisionManager::VisionManager() {
  std::string filename = "data/cornflakesCropped.png";
  auto imgObject = cv::imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
  // objDetector = new SiftDetector(imgObject);
  objDetector = std::make_unique<SiftDetector>(imgObject);
}

bool VisionManager::initDetection() {
  bool flag = false;
  auto frame = framesGenerator.nextFrame();
  int x, y;
  std::vector<int> vec;
  while (frame.data) {
    cv::cvtColor(frame, frame, cv::COLOR_RGB2GRAY);
    if (objDetector->detect(frame, x, y)) {
      vec.push_back(x);
      vec.push_back(y);
      centroidPositions.push_back(vec);
      vec.clear();
    }
    frame = framesGenerator.nextFrame();
  }
  flag = true;
  return flag;
}

VisionManager::~VisionManager() {
}
