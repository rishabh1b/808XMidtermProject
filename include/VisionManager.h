/*
 * VisionManager.h
 *
 *  Created on: Oct 16, 2017
 *      Author: viki
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
  ObjectDetector* objDetector;
  std::vector<std::vector<int> > centroidPositions;

};


#endif /* INCLUDE_VISIONMANAGER_H_ */
