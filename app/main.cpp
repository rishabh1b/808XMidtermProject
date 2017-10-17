/**
 * @file main.cpp
 * @brief Toy function to check openCV integration
 * @author Rishabh Biyani(rishabh1b)
 * @copyright GNU Public License
 *
 */

// #include "opencv2/opencv.hpp"
// #include <opencv2/core/core.hpp>
// #include <opencv2/highgui/highgui.hpp>
// #include <opencv2/imgproc/imgproc.hpp>
#include "VisionManager.h"


int main() {
  VisionManager visManager;
  visManager.initDetection();
  return 0;
}
