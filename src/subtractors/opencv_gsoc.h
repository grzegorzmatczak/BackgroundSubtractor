#ifndef OPENCV_GSOC_H
#define OPENCV_GSOC_H

#include <opencv2/bgsegm.hpp>
#include "basesubtractor.h"

class QJsonObject;

namespace Subtractor
{
class GSOC : public BaseSubtractor
{
 public:
  GSOC(QJsonObject const &a_config);
  cv::Mat process(cv::Mat &a_src);

 private:
  cv::Ptr<cv::BackgroundSubtractor> m_backgroundSubtractor;
  cv::Mat m_background;
  int m_cameraMotionCompensation;
  int m_numberOfSamples;
  double m_replaceRate;
  double m_propagationRate;
  int m_hitsThreshold;
};
} // namespace Subtractor

#endif // OPENCV_GSOC_H
