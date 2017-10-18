/*
 * @file OutputWriter.cpp handles output writing to a file or a video
 * @author Rishabh Biyani(rishabh1b)
 * @copyright MIT License (c) Rishabh Biyani 2017
 */

#include "OutputWriter.h"
#include <string>
#include <vector>

OutputWriter::OutputWriter(std::string outputFileName)
    : numFrames(0),
      videoCreator(outputFileName, CV_FOURCC('H', '2', '6', '4'), 10,
                   cv::Size(480, 640)) {
}

bool OutputWriter::writeCentroidValues(
    const std::vector<std::vector<int> >& centroidPositions) {
  std::ofstream myfile;
  myfile.open("../Outputs/centroids.csv");
  for (auto currCentre : centroidPositions) {
    myfile << currCentre[0] << "," << currCentre[1] << "\n";
  }

  myfile.close();
  return true;
}

bool OutputWriter::writeFrames(const std::vector<cv::Mat>& processedImages) {
  for (auto frame : processedImages) {
    videoCreator.write(frame);
  }
  videoCreator.release();
  return true;
}

bool OutputWriter::writeOutputs(
    const std::vector<cv::Mat>& processedImages,
    const std::vector<std::vector<int> >& centroidPositions) {

  int counter = 0;
  std::stringstream ss;
  std::string xstr, ystr, number;
  std::string outputFilename;
  for (auto frame : processedImages) {
    auto currentCentre = centroidPositions[counter];
    numFrames++;
    int x = currentCentre[0];
    int y = currentCentre[1];
    ss << x;
    ss >> xstr;
    ss.clear();
    ss << y;
    ss >> ystr;
    ss.clear();

    std::string centroid = "(" + xstr + "," + ystr + ")";
    cv::Point org(x, y);
    cv::putText(frame, centroid, org, cv::FONT_HERSHEY_COMPLEX, 0.5,
                cv::Scalar(0, 0, 255), 1, 8);

    std::stringstream outputFilename;
    outputFilename << "../Outputs/detection" << counter <<  ".jpg";

    // For Testing
    // cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
    // cv::imshow("image", frame);
    // cv::waitKey(30);
    imwrite(outputFilename.str(), frame);
    counter++;
  }
  return true;
}

