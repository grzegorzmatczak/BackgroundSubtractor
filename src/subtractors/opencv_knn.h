#ifndef OPENCV_KNN_H
#define OPENCV_KNN_H

#include <opencv2/video.hpp>
#include "basesubtractor.h"

class QJsonObject;

namespace Subtractor
{
class KNN : public BaseSubtractor
{
 public:
  KNN(QJsonObject const &a_config);
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

#endif // OPENCV_KNN_H
