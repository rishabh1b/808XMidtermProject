/**
 * @file main.cpp
 * @brief Toy function to check openCV integration
 * @author Rishabh Biyani(rishabh1b)
 * @copyright GNU Public License
 *
 */
/* #include <cv.h>
 #include <highgui.h> */

#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "VideoFrame.h"

// using namespace cv;

int main() {
  // dummy();
  /* std::string filename = "data/cornflakesCropped.png";
   cv::Mat image;
   image = cv::imread(filename, CV_LOAD_IMAGE_COLOR);

   if (!image.data) {
   printf("No image data \n");
   return -1;
   }

   cv::namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
   imshow("Display Image", image);

   cv::waitKey(0);*/

  VideoFrame vidFrame = VideoFrame("data/demo.mp4");
  cv::Mat frame = vidFrame.nextFrame();

   if (!frame.data) {
   printf("No image data \n");
   return -1;
   }


   cv::namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
   cv::imshow("Display Image", frame);

   cv::waitKey(0);
//  std::string filename = "data/demo.mp4";
//  cv::VideoCapture cap(filename);  // open the default camera
//  if (!cap.isOpened())  // check if we succeeded
//    return -1;
//
//  cv::Mat frame;
//  cap >> frame;
//
//  if (!frame.data) {
//    printf("No image data \n");
//    return -1;
//  }
//
//  cv::namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
//  cv::imshow("Display Image", frame);
//
//  cv::waitKey(0);

  return 0;
}
