/*
 * @file SiftDetector.cpp implementation of the detection using sift features
 * @author Rishabh Biyani(rishabh1b)
 * @copyright MIT license (c) Rishabh Biyani 2017
 */

#include "SiftDetector.h"
size_t MIN_MATCH_COUNT = 30;

SiftDetector::SiftDetector(cv::Mat imgObject, bool showMatches,
                           bool saveImages) {

  this->showMatches = showMatches;
  this->saveImages = saveImages;
  siftfeature = cv::xfeatures2d::SIFT::create();
  setObjectKeypoints(imgObject);
}

void SiftDetector::setObjectKeypoints(cv::Mat imgObject) {
  this->imgObject = imgObject;
  siftfeature->detect(imgObject, objKeypoints);
  siftfeature->compute(imgObject, objKeypoints, objDescriptor);
}

bool SiftDetector::detect(cv::Mat& imageScene, int& x, int& y) {
  std::vector<int> bboxCentroid;
  if (findMatchingFeatures(imageScene, bboxCentroid)) {
    x = bboxCentroid[0];
    y = bboxCentroid[1];
    cv::imshow(OPENCV_WINDOW, currentEditedImage);
    cv::waitKey(3);
    return true;
  } else
    return false;
}

bool SiftDetector::findMatchingFeatures(cv::Mat imgScene,
                                        std::vector<int>& bboxCentroid) {

  // Step 1: Detect the keypoints in the scene using SIFT Detector
  std::vector<cv::KeyPoint> keypointsScene;

  siftfeature->detect(imgScene, keypointsScene);

  // Step 2: Calculate descriptors (feature vectors)

  cv::Mat descriptorsScene;
  siftfeature->compute(imgScene, keypointsScene, descriptorsScene);

  // Step 3: Matching descriptor vectors using FLANN matcher
  cv::FlannBasedMatcher matcher;
  // TODO: Typdef this
  std::vector<std::vector<cv::DMatch> > matches;
  if ( !descriptorsScene.empty() )
    matcher.knnMatch(objDescriptor, descriptorsScene, matches, 2);

  // Draw only "good" matches (i.e. whose distance is less than 3*min_dist - Lowe's test )
  std::vector<cv::DMatch> goodMatches;

  for (size_t i = 0; i < matches.size(); i++) {
    if (matches[i].size() == 2
        && (matches[i][0].distance < 0.85 * matches[i][1].distance))
      goodMatches.push_back(matches[i][0]);

  }

  if (goodMatches.size() > MIN_MATCH_COUNT) {
    std::vector<cv::Point2f> bboxCorners = getBBox(imgScene, keypointsScene,
                                                   goodMatches);
    bboxCentroid.push_back((bboxCorners[0].x + bboxCorners[2].x) / 2);
    bboxCentroid.push_back((bboxCorners[0].y + bboxCorners[2].y) / 2);
    return true;
  } else {
    return false;
  }
}

std::vector<cv::Point2f> SiftDetector::getBBox(
    const cv::Mat& imgScene, const std::vector<cv::KeyPoint>& keypointsScene,
    const std::vector<cv::DMatch>& goodMatches) {
  (this->imgMatches) = cv::Mat();
  // imgMatches = cv::Mat::zeros( imgScene.size(), CV_8UC3 );
  // Localize the object
  std::vector<cv::Point2f> obj;
  std::vector<cv::Point2f> scene;

  for (size_t i = 0; i < goodMatches.size(); i++) {
    // Get the keypoints from the good matches
    obj.push_back(objKeypoints[goodMatches[i].queryIdx].pt);
    scene.push_back(keypointsScene[goodMatches[i].trainIdx].pt);
  }

  cv::Mat H = findHomography(obj, scene, CV_RANSAC, 3);
  // Get the corners from the image_1 ( the object to be "detected" )
  std::vector<cv::Point2f> objCorners(4);
  objCorners[0] = cvPoint(0, 0);
  objCorners[1] = cvPoint(imgObject.cols, 0);
  objCorners[2] = cvPoint(imgObject.cols, imgObject.rows);
  objCorners[3] = cvPoint(0, imgObject.rows);
  std::vector<cv::Point2f> sceneCorners(4);
  perspectiveTransform(objCorners, sceneCorners, H);
  // Draw lines between the corners (the mapped object in the scene - image_2 )
  cv::Mat newImage(imgScene.size(), CV_8UC3);
  currentEditedImage = newImage;

  // convert grayscale to color image
  cv::cvtColor(imgScene, currentEditedImage, CV_GRAY2RGB);
  // Draw bounding box on top of image
  line(currentEditedImage, sceneCorners[0], sceneCorners[1],
       cv::Scalar(0, 255, 0), 4);
  line(currentEditedImage, sceneCorners[1], sceneCorners[2],
       cv::Scalar(0, 255, 0), 4);
  line(currentEditedImage, sceneCorners[2], sceneCorners[3],
       cv::Scalar(0, 255, 0), 4);
  line(currentEditedImage, sceneCorners[3], sceneCorners[0],
       cv::Scalar(0, 255, 0), 4);

  // Show detected matches
  if (showMatches) {
    drawMatches(imgObject, objKeypoints, imgScene, keypointsScene, goodMatches,
                imgMatches, cv::Scalar::all(-1), cv::Scalar::all(-1),
                std::vector<char>(),
                cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
    cv::imshow("Good Matches & Object detection", imgMatches);
    cv::waitKey(3);
  }
  if (saveImages) {
    processedImages.push_back(currentEditedImage);
  }

  return sceneCorners;

}
