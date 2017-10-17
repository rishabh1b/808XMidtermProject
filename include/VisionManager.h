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
  /**
   * @brief static member function that returns singleton instance of the vision manager
   */
  static VisionManager& get();
  /**
   * @brief public member function to initialize the object detection module.
   */
  void initDetection();
  /**
   * @brief Vision Manager Destructor
   */
  ~VisionManager();
 private:
  /**
   * @brief private constructor
   */
  VisionManager();
  /**
   * @brief private member variable of typr VideoFrame which fetches next video frame
   */
  VideoFrame framesGenerator;

  /**
   * @brief private member variable of type ObjectDetector
   */
  std::unique_ptr<ObjectDetector> objDetector;
  /**
   * @brief private member variable storing centroid positions as seen accross frames
   */
  std::vector<std::vector<int> > centroidPositions;

};

#endif /* INCLUDE_VISIONMANAGER_H_ */
