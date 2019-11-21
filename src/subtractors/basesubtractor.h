#ifndef BASE_SUBTRACTOR_H
#define BASE_SUBTRACTOR_H

#include <QDateTime>
#include "opencv2/bgsegm.hpp"
#include "opencv2/core.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/core/types.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

class BaseSubtractor
{
 public:
  BaseSubtractor();
  virtual ~BaseSubtractor();

  virtual cv::Mat process(cv::Mat &a_src) = 0;
};

#endif // BASE_SUBTRACTOR_H
