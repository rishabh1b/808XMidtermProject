/*
 * @file VideoFrame.cpp implementation of the video parsing routine
 * @author Rishabh Biyani (rishabh1b)
 * @copyright MIT License
 */

#include "VideoFrame.h"

VideoFrame::VideoFrame(std::string filename) {
  vidcapture = cv::VideoCapture();
  vidcapture.open(filename);
  this->filename = filename;
}

cv::Mat VideoFrame::nextFrame() {
  cv::Mat frame;
  vidcapture >> frame;
  return frame;
}

void VideoFrame::setFilename(std::string filename) {
   this->vidcapture.release();
  // Reinitialize
  vidcapture = cv::VideoCapture();
  this->filename = filename;
  vidcapture.open(filename);

}

void VideoFrame::test(){
  vidcapture = cv::VideoCapture("demo.avi");

  cv::Mat frame;
  vidcapture>> frame;

    if (!frame.data) {
      printf("No image data \n");
          return;
    }


    cv::namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
    cv::imshow("Display Image", frame);

    cv::waitKey(0);

}
