#ifndef MEDIAN_V2_H
#define MEDIAN_V2_H

#include "basesubtractor.h"
#include "user_median_v2_implementation.h"
class QJsonObject;

namespace Subtractor {
class Median_v2 : public BaseSubtractor {
 public:
  Median_v2(QJsonObject const &a_config);
  cv::Mat process(cv::Mat &a_src);

 private:
  imgMedian_V2 m_backgroundSubtractor;
  cv::Mat m_background;
  int m_history;
  int m_historyDelta;
  int m_iteration;
  bool m_firstInitialization;
  bool m_firstTime;
  int m_decisionThreshold;
};
}  // namespace Subtractor

#endif  // MEDIAN_V2_H
