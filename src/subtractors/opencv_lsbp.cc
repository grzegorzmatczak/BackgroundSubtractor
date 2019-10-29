#include "opencv_lsbp.h"
#include <QJsonObject>

constexpr auto CAMERA_MOTION_COMPENSATION{ "CameraMotionCompensation" };
constexpr auto NUMBER_OF_SAMPLES{ "NumberOfSamples" };
constexpr auto LSBP_RADIUS{ "LSBPRadius" };

Subtractor::LSBP::LSBP(QJsonObject const &a_config)
  : m_cameraMotionCompensation{ a_config[CAMERA_MOTION_COMPENSATION].toInt() }
  , m_numberOfSamples{ a_config[NUMBER_OF_SAMPLES].toInt() }
  , m_LSBPRadius{ a_config[LSBP_RADIUS].toInt() }

{
  m_backgroundSubtractor =
      cv::bgsegm::createBackgroundSubtractorLSBP(m_cameraMotionCompensation, m_numberOfSamples, m_LSBPRadius);
}

cv::Mat Subtractor::LSBP::process(cv::Mat &a_src)
{
  m_backgroundSubtractor->apply(a_src, m_background);
  return m_background;
}
