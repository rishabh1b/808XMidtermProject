/*
 * @file SiftDetector.h which is one of the concrete version of the base ObjectDetector
 * @author Rishabh Biyani(rishabh1b)
 * @copyright MIT License (c) Rishabh Biyani 2017
 */

#ifndef INCLUDE_SIFTDETECTOR_H_
#define INCLUDE_SIFTDETECTOR_H_
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include "ObjectDetector.h"

static const std::string OPENCV_WINDOW = "Matches found";

class SiftDetector : public ObjectDetector {
 public:
  /**
   * @brief detect function checks whether similar object is located in scene.
   * It overrides the detect function in base class
   * @sa ObjectDetector
   * @param imageScene current frame as seen from the camera/videoclip
   * @param x - passed as reference x coordinate of bounding box
   * @param y - passed as reference y coordinate of bounding box
   */
  bool detect(cv::Mat& imageScene, int& x, int& y);
  /**
   * @brief setObjectKeypoints, overrides the base class method to
   * set keypoints of the know object to be detected
   * @param filename string specifying the file path
   */
  void setObjectKeypoints(cv::Mat imgObject);

  /*
   * @brief SifDetector constructor
   * @param cv::Mat image file for the object to be detected
   * @param showMatches default argument to turn on or off the matches shown
   * @param saveImages default argument to control saving of image files processed by detector
   */
  SiftDetector(cv::Mat imgObject, bool showMatches = false, bool saveImages =
                   true);

 private:
  /*
   * @brief getBBox private member function to get bounding box across the object detected
   * @param imgscene current frame as seen in the video file or the camera
   * @param keypointsscene keypoints on the scene frame
   * @param goodMatches DMatch vector with positive matches
   * @return a vector of corner of the bounding box found
   */
  std::vector<cv::Point2f> getBBox(
      const cv::Mat& imgScene, const std::vector<cv::KeyPoint>& keypointsScene,
      const std::vector<cv::DMatch>& goodMatches);
  /*
   * @brief findMatchingFeatures finds if there are any matching features in scene when compared to the object.
   * @param imgscene current frame as seen in the video file or the camera
   * @param bboxcentroid passed as a reference which gets populated with corners of the object in scene
   * @return boolean indicating whether find was successfull
   */
  bool findMatchingFeatures(cv::Mat imgscene, std::vector<int>& bboxcentroid);
  /**
   * @brief siftfeature private member variable to detect sift features
   */
  cv::Ptr<cv::Feature2D> siftfeature;
  /**
   * @brief imgMatches private member variable to keep a track of the current frame being edited
   */
  cv::Mat imgMatches;
  bool showMatches, saveImages;
};

#endif /* INCLUDE_SIFTDETECTOR_H_ */
