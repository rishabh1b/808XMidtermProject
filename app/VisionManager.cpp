/*
 * @file VisionManager.cpp which manages the perception module
 * @author Rishabh Biyani(rishabh1b)
 * @copyright MIT license (c) 2017 Rishabh Biyani
 */

#include "VisionManager.h"
#include <memory>
#include <string>
#include <vector>

VisionManager& VisionManager::get() {
  static VisionManager visManager;
  return visManager;
}

VisionManager::VisionManager(bool showMatches, bool saveImages)
    : framesGenerator(VideoFrame()),
      outputter(OutputWriter()) {
  std::string filename = "data/cornflakesCropped.png";
  auto imgObject = cv::imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
  // objDetector = new SiftDetector(imgObject);
  objDetector = std::make_unique<SiftDetector>(imgObject, showMatches,
                                               saveImages);
  framesGenerator.setFilename("data/demoshort.mp4");
  this->showMatches = showMatches;
  this->saveImages = saveImages;
}

bool VisionManager::initDetection() {
  bool flag = false;
  auto frame = framesGenerator.nextFrame();
  std::vector<int> vec;
  while (frame.data) {
    cv::cvtColor(frame, frame, cv::COLOR_RGB2GRAY);
    if (objDetector->detect(frame)) {
      vec.push_back(objDetector->getX());
      vec.push_back(objDetector->getY());
      centroidPositions.push_back(vec);
      vec.clear();
    }
    frame = framesGenerator.nextFrame();
  }
  if (saveImages) {
    outputter.writeCentroidValues(centroidPositions);
    outputter.writeFrames(objDetector->processedImages);
    outputter.writeOutputs(objDetector->processedImages, centroidPositions);
  }
  flag = true;
  return flag;
}

VisionManager::~VisionManager() {
}
