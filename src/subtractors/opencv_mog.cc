#include "opencv_mog.h"
#include <QJsonObject>

constexpr auto HISTORY{ "History" };
constexpr auto N_MIXTURES{ "Nmixtures" };
constexpr auto BACKGROUND_RATIO{ "BackgroundRatio" };
constexpr auto NOISE_SIGMA{ "NoiseSigma" };

Subtractor::MOG::MOG(QJsonObject const &a_config)
  : m_history{ a_config[HISTORY].toInt() }
  , m_nmixtures{ a_config[N_MIXTURES].toInt() }
  , m_backgroundRatio{ a_config[BACKGROUND_RATIO].toDouble() }
  , m_noiseSigma{ a_config[NOISE_SIGMA].toDouble() }

{
  m_backgroundSubtractor =
      cv::bgsegm::createBackgroundSubtractorMOG(m_history, m_nmixtures, m_backgroundRatio, m_noiseSigma);
}

cv::Mat Subtractor::MOG::process(cv::Mat &a_src)
{
  m_backgroundSubtractor->apply(a_src, m_background);
  return m_background;
}
