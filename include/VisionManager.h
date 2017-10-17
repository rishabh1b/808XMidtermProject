/*
 * @file VisionManager.h
 * @author Rishabh Biyani (rishabh1b)
 * @copyright MIT license (c) Rishabh Biyani 2017
 */

#ifndef INCLUDE_VISIONMANAGER_H_
#define INCLUDE_VISIONMANAGER_H_

#include "VideoFrame.h"
#include "ObjectDetector.h"
#include "SiftDetector.h"
#include <vector>

class VisionManager {
 public:
  VisionManager();
  void initDetection();
  ~VisionManager();
 private:
  VideoFrame framesGenerator;
  cv::Mat imgObject;
  std::unique_ptr<ObjectDetector> objDetector;
  std::vector<std::vector<int> > centroidPositions;

};


#endif /* INCLUDE_VISIONMANAGER_H_ */
