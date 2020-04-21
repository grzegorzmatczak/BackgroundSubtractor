#ifndef MEDIAN_H
#define MEDIAN_H

#include <opencv2/bgsegm.hpp>

#include "basesubtractor.h"
#include "user_median_implementation.h"

class QJsonObject;

namespace Subtractor
{
class Median : public BaseSubtractor
{
 public:
  Median(QJsonObject const &a_config);
  cv::Mat process(cv::Mat &a_src);
  cv::Mat getDiff(cv::Mat &a_src);
  cv::Mat getBackground();

 private:
  Subtractor::imgMedian m_backgroundSubtractor;
  cv::Mat m_background;

  int m_history;
  int m_historyDelta;
  int m_iteration;
  bool m_firstInitialization;
  bool m_firstTime;
  int m_decisionThreshold;
};
} // namespace Subtractor

#endif // MEDIAN_H
