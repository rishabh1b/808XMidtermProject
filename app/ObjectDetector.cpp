/*
 * @file base class for handling ObjectDetection
 * @author Rishabh Biyani(rishabh1b)
 * @copyright MIT license (c) Rishabh Biyani 2017
 */

#include "ObjectDetector.h"

//void ObjectDetector::setObjectKeypoints(std::string filename) {
//
//  imgObject = cv::imread( filename, CV_LOAD_IMAGE_GRAYSCALE );
//  detector.detect( img_object, keypoints_object );
//
//}

void calculateCentroid(const std::vector<cv::Point2f>& bboxcorners, int& x, int& y) {
  x = ((bboxcorners[0].x + bboxcorners[2].x) / 2);
  y = ((bboxcorners[0].y + bboxcorners[2].y) / 2);
}


