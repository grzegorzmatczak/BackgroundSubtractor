#ifndef OPENCV_GMG_H
#define OPENCV_GMG_H

#include <opencv2/bgsegm.hpp>

#include "basesubtractor.h"

class QJsonObject;

namespace Subtractor
{
class GMG : public BaseSubtractor
{
 public:
  GMG(QJsonObject const &a_config);
  cv::Mat process(cv::Mat &a_src);

 private:
  cv::Ptr<cv::BackgroundSubtractor> m_backgroundSubtractor;
  cv::Mat m_background;
  int m_initializationFrames;
  double m_decisionThreshold;
};
} // namespace Subtractor

#endif // OPENCV_GMG_H
