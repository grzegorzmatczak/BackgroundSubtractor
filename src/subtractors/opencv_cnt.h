#ifndef OPENCV_CNT_H
#define OPENCV_CNT_H

#include <opencv2/bgsegm.hpp>
#include "basesubtractor.h"
class QJsonObject;

namespace Subtractor
{
class CNT : public BaseSubtractor
{
 public:
  CNT(QJsonObject const &a_config);
  cv::Mat process(cv::Mat &a_src);

 private:
  cv::Ptr<cv::BackgroundSubtractor> m_backgroundSubtractor;
  cv::Mat m_background;
  int m_minPixelStability;
  int m_maxPixelStability;
  bool m_isParallel;
  bool m_useHistory;
};
} // namespace Subtractor

#endif // OPENCV_CNT_H
