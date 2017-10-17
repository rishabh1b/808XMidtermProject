/*
 * VisionManager.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: viki
 */

#include "VisionManager.h"

VisionManager::VisionManager() {
  std::string filename = "data/cornflakesCropped.png";
  imgObject = cv::imread(filename, CV_LOAD_IMAGE_COLOR);
  // objDetector = new SiftDetector(imgObject);
  objDetector = std::make_unique<SiftDetector>(imgObject);
}

void VisionManager::initDetection() {
  cv::Mat frame = framesGenerator.nextFrame();
  int x, y;
  std::vector<int> vec;
  while (frame.data) {
    if (objDetector->detect(frame, x, y)) {
      vec.push_back(x);
      vec.push_back(y);
      centroidPositions.push_back(vec);
      vec.clear();
    }
    frame = framesGenerator.nextFrame();
  }
}

VisionManager::~VisionManager() {
}
