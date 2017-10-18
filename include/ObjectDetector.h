/*
 * @file ObjectDetector.h
 * @author Rishabh Biyani(rishabh1b)
 * @copyright MIT license (c) 2017 Rishabh Biyani
 */

#ifndef INCLUDE_OBJECTDETECTOR_H_
#define INCLUDE_OBJECTDETECTOR_H_

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <vector>

class ObjectDetector {
  friend class VisionManager;
 public:
  /**
   * @brief pure virtual member detect function
   * @param imageScene a cv::Mat object
   * @param int, x co-ordinate of the centre of the object
   * @param int, y co-ordinate of the centre of the object
   * @return bool, to indicate whether success was returned
   */
  virtual bool detect(const cv::Mat& imageScene)= 0;
  /**
   * @brief virtual member function to set keypoints of the object to be detected
   * @param filename of the object to be detected
   */
  virtual void setObjectKeypoints(cv::Mat imgObject) = 0;


  virtual ~ObjectDetector() {
  }

  /**
   * @brief Getter for Centroid position x
   * @return integer value x in pixels of the centre position
   */
  int getX() {
    return centX;
  }
  /**
   * @brief Getter for centroid position y
   * @return integer value y in pixels of the centre position
   */
  int getY() {
    return centY;
  }

 protected:
  /**
   * @brief protected variable centre x
   */
  int centX;
  /**
   * @brief protected variable centre y
   */
  int centY;
  /**
   * @brief protected variable storing processed outputs
   */
  std::vector<cv::Mat> processedImages;
  /**
   * @brief protected variable storing keypoints from the object to be detected
   */
  std::vector<cv::KeyPoint> objKeypoints;
  /**
   * @brief protected variable objDescriptor storing different descriptor of the interesting keypoints
   */
  cv::Mat objDescriptor;
  /**
   * @brief protected variable storing imgObject to be detected under consideration
   */
  cv::Mat imgObject;
  /**
   * @brief centroid of the detected object
   */
  std::vector<int> bboxCentroid;
};

#endif /* INCLUDE_OBJECTDETECTOR_H_ */
