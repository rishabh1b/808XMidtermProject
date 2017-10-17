/*
 * ObjectDetection.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: viki
 */

#include <gtest/gtest.h>
#include <memory>
#include "VisionManager.h"

/**
 * @brief Test the Entire Pipeline
 */
TEST(DetectionTest, testpipeline) {
  VisionManager& visManager = VisionManager::get();
  auto flag = visManager.initDetection();
  EXPECT_TRUE(flag);
}


