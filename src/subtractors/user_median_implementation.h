#ifndef MEDIAN_IMPLEMENTATION_H
#define MEDIAN_IMPLEMENTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include "basesubtractor.h"
#include "omp.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;

namespace Subtractor
{
class imgMedian
{
 public:
  std::vector<unsigned char>::iterator it;
  imgMedian();
  imgMedian(unsigned char R_temp);
  void InitMedian(cv::Mat &img);
  void ShowIterator();
  void ShowMedianNode(unsigned int temp);
  void RemoveNode();
  void AddImage(cv::Mat &img);
  void getMedian(cv::Mat &img);
  cv::Mat getMedian();
  void UnitTestInit(cv::Mat M, int R, vector<unsigned char> V1, vector<unsigned char> N1, vector<unsigned char> P1,
                    unsigned int interator);
  void UnitTestCheck(vector<unsigned char> V1, vector<unsigned char> N1, vector<unsigned char> P1);
  virtual ~imgMedian();

 private:
  unsigned int width;
  unsigned int height;
  unsigned char iterator;
  unsigned char R;
  unsigned char R_half;
  unsigned char q1;
  unsigned char q2;
  unsigned char q3;
  cv::Mat localCopy;
  std::vector<std::vector<unsigned char>> V;
  std::vector<std::vector<unsigned char>> NEXT;
  std::vector<std::vector<unsigned char>> PREV;
};
} // namespace Subtractor

#endif /* MEDIAN_IMPLEMENTATION_H */










