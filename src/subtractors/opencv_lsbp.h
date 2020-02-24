#ifndef OPENCV_LSBP_H
#define OPENCV_LSBP_H

#include <opencv2/bgsegm.hpp>
#include "basesubtractor.h"

class QJsonObject;

namespace Subtractor
{
class LSBP : public BaseSubtractor
{
 public:
  LSBP(QJsonObject const &a_config);
  cv::Mat process(cv::Mat &a_src);

 private:
  cv::Ptr<cv::BackgroundSubtractor> m_backgroundSubtractor;
  cv::Mat m_background;
  int m_cameraMotionCompensation;
  int m_numberOfSamples;
  int m_LSBPRadius;
  double m_LSBP_Tlower;
  double m_LSBP_Tupper;
  double m_LSBP_Tincrease;
  double m_LSBP_Tdecrease;
  double m_LSBP_Rscale;
  double m_LSBP_Rincrease;
  double m_LSBP_NoiseBG;
  double m_LSBP_NoiseFG;
  int m_LSBP_BinaryThreshold;
  int m_LSBP_minMatchesNumber;

};
} // namespace Subtractor

#endif // OPENCV_LSBP_H
