#ifndef OPENCV_MOG_H
#define OPENCV_MOG_H

#include <opencv2/bgsegm.hpp>

#include "basesubtractor.h"

class QJsonObject;

namespace Subtractor
{
class MOG : public BaseSubtractor
{
 public:
  MOG(QJsonObject const &a_config);
  cv::Mat process(cv::Mat &a_src);

 private:
  cv::Ptr<cv::BackgroundSubtractor> m_backgroundSubtractor;
  cv::Mat m_background;
  int m_history;
  int m_nmixtures;
  double m_backgroundRatio;
  double m_noiseSigma;
};
} // namespace Subtractor

#endif // OPENCV_MOG_H
