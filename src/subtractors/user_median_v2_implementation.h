#ifndef MEDIAN_IMPLEMENTATION_H
#define MEDIAN_IMPLEMENTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "basesubtractor.h"
#include "omp.h"

using namespace std;

// Class to implement node
class Node
{
 public:
  int key;

  // Array to hold pointers to node of different level
  Node **forward;
  Node(int, int);
};

// Class for Skip list
class SkipList
{
  // Maximum level for this skip list
  int MAXLVL;

  // P is the fraction of the nodes with level
  // i pointers also having level i+1 pointers
  float P;

  // current level of skip list
  int level;

 public:
  // pointer to header node
  Node *header;

 public:
  SkipList(int, float);
  int randomLevel();
  Node *createNode(int, int);
  void insertElement(int);
  void deleteElement(int);
  void searchElement(int);
  void displayList();
};

namespace Subtractor
{
class imgMedian_V2
{
 public:
  std::vector<unsigned char>::iterator it;
  imgMedian_V2();
  imgMedian_V2(unsigned char R_temp);
  void InitMedian(cv::Mat &img);
  void RemoveNode();
  void AddImage(cv::Mat &img);
  void getMedian(cv::Mat &img);
  cv::Mat getMedian();

  virtual ~imgMedian_V2();

 private:
  unsigned int width;
  unsigned int height;
  unsigned int R;
  unsigned int R_half;
  cv::Mat localCopy;
  std::vector<SkipList> V;
  std::vector<std::deque<int>> v_historyList;
};
} // namespace Subtractor

#endif /* MEDIAN_IMPLEMENTATION_H */
