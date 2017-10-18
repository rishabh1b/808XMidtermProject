/*
 * @file ObjectDetection.cpp runs some test cases to verify the object detector
 * @author Rishabh Biyani (rishabh1b)
 * @copyright MIT license (c) 2017 Rishabh Biyani
 */

#include "VisionManager.h"
#include <gtest/gtest.h>
#include <memory>
#include <string>

/**
 * @brief Test the Entire Pipeline
 */
TEST(DetectionTest, testpipeline) {
  VisionManager& visManager = VisionManager::get();
  auto flag = visManager.initDetection();
  EXPECT_TRUE(flag);
}

/**
 * @brief Test the detection of false positives
 */
TEST(DetectionTest, falsePositive) {
  std::string filename = "data/cornflakesCropped.png";
  auto imgObject = cv::imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
  auto falseImage = cv::imread("data/lenna_false_positive.jpg",
                               CV_LOAD_IMAGE_GRAYSCALE);
  std::unique_ptr<ObjectDetector> detector = std::make_unique<SiftDetector>(
      imgObject, false, false);
  EXPECT_FALSE(detector->detect(falseImage));
}

