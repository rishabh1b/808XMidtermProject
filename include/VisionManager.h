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
#include "OutputWriter.h"
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
  bool initDetection();
  /**
   * @brief Vision Manager Destructor
   */
  ~VisionManager();
 private:
  /**
   * @brief private constructor
   */
  VisionManager(bool showMatches = true, bool saveImages = true);
  /**
   * @brief private member variable of type VideoFrame which fetches next video frame
   */
  VideoFrame framesGenerator;

  /**
   * @brief private member variable of type ObjectDetector
   */
  std::unique_ptr<ObjectDetector> objDetector;
  /**
   * @brief private member variable storing centroid positions as seen across frames
   */
  std::vector<std::vector<int> > centroidPositions;
  /**
   * @brief private member variable to generate outputs
   */
  OutputWriter outputter;
  /**
   * @brief private member variable to control visualization
   */
  bool showMatches;
  /**
   * @brief private member variable to control saving output images
   */
  bool saveImages;
};

#endif /* INCLUDE_VISIONMANAGER_H_ */
