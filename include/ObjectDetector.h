/*
 * @file ObjectDetector.h
 * @author Rishabh Biyani(rishabh1b)
 * @copyright MIT license (c) 2017 Rishabh Biyani
 */
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

#ifndef INCLUDE_OBJECTDETECTOR_H_
#define INCLUDE_OBJECTDETECTOR_H_

class ObjectDetector {
 public:
  /**
   * @brief pure virtual member detect function
   * @param imageScene a cv::Mat object
   * @param int, x co-ordinate of the centre of the object
   * @param int, y co-ordinate of the centre of the object
   * @return bool, to indicate whether success was returned
   */
  bool detect(cv::Mat& imageScene, int&, int&)= 0;
  // void setObjectKeypoints(std::string filename);

 protected:
  /**
   * @brief protected member function to calculate the centroid out of the bounding box corners
   * @param int, x co-ordinate of the centre of the object
   * @param int, y co-ordinate of the centre of the object
   */
  void calculateCentroid(const std::vector<cv::Point2f>& bboxCorners, int& x,
                         int& y);
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

};

#endif /* INCLUDE_OBJECTDETECTOR_H_ */
