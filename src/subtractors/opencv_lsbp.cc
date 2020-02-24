#include "opencv_lsbp.h"
#include <QJsonObject>

constexpr auto CAMERA_MOTION_COMPENSATION{ "CameraMotionCompensation" };
constexpr auto NUMBER_OF_SAMPLES{ "NumberOfSamples" };
constexpr auto LSBP_RADIUS{ "LSBPRadius" };
constexpr auto LSBP_T_LOWER{ "LSBP_Tlower" };
constexpr auto LSBP_T_UPPER{ "LSBP_Tupper" };
constexpr auto LSBP_T_INCREASE{ "LSBP_Tincrease" };
constexpr auto LSBP_T_DECREASE{ "LSBP_Tdecrease" };
constexpr auto LSBP_R_SCALE{ "LSBP_Rscale" };
constexpr auto LSBP_R_INCREASE{ "LSBP_Rincrease" };
constexpr auto LSBP_NOISE_BG{ "LSBP_NoiseBG" };
constexpr auto LSBP_NOISE_FG{ "LSBP_NoiseFG" };
constexpr auto LSBP_BINARY_THRESHOLD{ "LSBP_BinaryThreshold" };
constexpr auto LSBP_MIN_MATCHES_NUMBER{ "LSBP_minMatchesNumber" };

Subtractor::LSBP::LSBP(QJsonObject const &a_config)
  : m_cameraMotionCompensation{ a_config[CAMERA_MOTION_COMPENSATION].toInt() }
  , m_numberOfSamples{ a_config[NUMBER_OF_SAMPLES].toInt() }
  , m_LSBPRadius{ a_config[LSBP_RADIUS].toInt() }
  , m_LSBP_Tlower{ a_config[LSBP_T_LOWER].toDouble() }
  , m_LSBP_Tupper{ a_config[LSBP_T_UPPER].toDouble() }
  , m_LSBP_Tincrease{ a_config[LSBP_T_INCREASE].toDouble() }
  , m_LSBP_Tdecrease{ a_config[LSBP_T_DECREASE].toDouble() }
  , m_LSBP_Rscale{ a_config[LSBP_R_SCALE].toDouble() }
  , m_LSBP_Rincrease{ a_config[LSBP_R_INCREASE].toDouble() }
  , m_LSBP_NoiseBG{ a_config[LSBP_NOISE_BG].toDouble() }
  , m_LSBP_NoiseFG{ a_config[LSBP_NOISE_FG].toDouble() }
  , m_LSBP_BinaryThreshold{ a_config[LSBP_BINARY_THRESHOLD].toInt() }
  , m_LSBP_minMatchesNumber{ a_config[LSBP_MIN_MATCHES_NUMBER].toInt() }
{
  m_backgroundSubtractor =
      cv::bgsegm::createBackgroundSubtractorLSBP(
        m_cameraMotionCompensation, 
        m_numberOfSamples, 
        m_LSBPRadius,
        m_LSBP_Tlower,
        m_LSBP_Tupper,
        m_LSBP_Tincrease,
        m_LSBP_Tdecrease,
        m_LSBP_Rscale,
        m_LSBP_Rincrease,
        m_LSBP_NoiseBG,
        m_LSBP_NoiseFG,
        m_LSBP_BinaryThreshold,
        m_LSBP_minMatchesNumber
        );
}

cv::Mat Subtractor::LSBP::process(cv::Mat &a_src)
{
  m_backgroundSubtractor->apply(a_src, m_background);
  return m_background;
}
