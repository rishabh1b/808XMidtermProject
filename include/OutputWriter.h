/*
 * @file OutputWriter.h header files for OutputWriter Prototypes
 * @author Rishabh Biyani(rishabh1b)
 * @copyright MIT license (c) 2017 Rishabh Biyani
 */

#ifndef INCLUDE_OUTPUTWRITER_H_
#define INCLUDE_OUTPUTWRITER_H_
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class OutputWriter {
 public:
  /**
   * @brief OutputWriter Class Constructor
   * @param outputFileName - filename of the
   */
  explicit OutputWriter(std::string outputFileName =
      "../Outputs/outputvideo.avi");
  /**
   * @brief writeCentroidValues dumps centroid positions to a file
   * @param a vector of vectors taken as constant reference
   * @return a boolean to indicate success
   */
  bool writeCentroidValues(
      const std::vector<std::vector<int> >& centroidPositions);
  /**
   * @brief writeFrames takes images and creates a Video File
   * @param processedImages are the output images from object detector taken as constant reference
   * @return a boolean to indicate success
   */
  bool writeFrames(const std::vector<cv::Mat>& processedImages);

  /**
   * Dump the centroid values onto the images
   */
  bool writeOutputs(const std::vector<cv::Mat>& processedImages,
                    const std::vector<std::vector<int> >& centroidPositions);
  /**
   * Number of frame written
   */
  int numFrames;

 private:
  /**
   * @brief videoCreator is a private member variable which is openCV library cv::VideoWriter type object
   */
  cv::VideoWriter videoCreator;
};

#endif /* INCLUDE_OUTPUTWRITER_H_ */
