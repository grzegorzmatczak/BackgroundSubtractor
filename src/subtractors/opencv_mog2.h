#ifndef OPENCV_MOG2_H
#define OPENCV_MOG2_H

#include <opencv2/video.hpp>
#include "basesubtractor.h"

class QJsonObject;

namespace Subtractor
{
class MOG2 : public BaseSubtractor
{
 public:
  MOG2(QJsonObject const &a_config);
  cv::Mat process(cv::Mat &a_src);

 private:
  cv::Ptr<cv::BackgroundSubtractor> m_backgroundSubtractor;
  cv::Mat m_background;
  double m_learningRate;
  int m_history;
  double m_varThreshold;
  bool m_detectShadows;
};
} // namespace Subtractor

#endif // OPENCV_MOG2_H
