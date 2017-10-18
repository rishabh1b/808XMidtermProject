/*
 * @file VideoFrame.h
 * @author Rishabh Biyani(rishabh1b)
 * @copyright MIT license
 *  Created on: Oct 15, 2017
 */
#include <string>
#include "opencv2/opencv.hpp"

#ifndef INCLUDE_VIDEOFRAME_H_
#define INCLUDE_VIDEOFRAME_H_

class VideoFrame {
 public:
  /**
   * @brief VideoFrame constructor
   * @param filename a string specifying path to the video file
   */
  VideoFrame(std::string filename = "data/demoshort.mp4");

  /**
   * @brief Video Frame Destructor. It takes care
   * of releasing VideoCapture Object
   */
  ~VideoFrame() {
    this->vidcapture.release();
  }

  /**
   * @brief nextFrame member function
   * @return img a cv::Mat instance
   */

  cv::Mat nextFrame();

  /**
   * @brief setFilename member function
   * @param filename a string specifying path to a video file
   */
  void setFilename(std::string filename);

  /**
   * Test function
   */
  void test();

 private:
  /**
   * OpenCv videoCapture Object
   */
  cv::VideoCapture vidcapture;
  /**
   *filename of the video clip currently being parsed
   */
  std::string filename;
};

#endif /* INCLUDE_VIDEOFRAME_H_ */
