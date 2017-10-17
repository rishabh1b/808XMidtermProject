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
  // framesGenerator = VideoFrame("data/demo.mp4");
  objDetector = new SiftDetector(imgObject);
}


void VisionManager::initDetection() {
  // objDetector->setObjectKeypoints(imgObject);
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
  delete objDetector;
}
