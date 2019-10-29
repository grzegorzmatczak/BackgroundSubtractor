#include "opencv_cnt.h"
#include <QJsonObject>

constexpr auto MIN_PIXEL_STABILITY{ "MinPixelStability" };
constexpr auto MAX_PIXEL_STABILITY{ "MaxPixelStability" };
constexpr auto IS_PARALLEL{ "IsParallel" };
constexpr auto USE_HISTORY{ "UseHistory" };

Subtractor::CNT::CNT(QJsonObject const &a_config)
  : m_minPixelStability{ a_config[MIN_PIXEL_STABILITY].toInt() }
  , m_maxPixelStability{ a_config[MAX_PIXEL_STABILITY].toInt() }
  , m_isParallel{ a_config[IS_PARALLEL].toBool() }
  , m_useHistory{ a_config[USE_HISTORY].toBool() }

{
  m_backgroundSubtractor =
      cv::bgsegm::createBackgroundSubtractorCNT(m_minPixelStability, m_useHistory, m_maxPixelStability, m_isParallel);
}

cv::Mat Subtractor::CNT::process(cv::Mat &a_src)
{
  m_backgroundSubtractor->apply(a_src, m_background);
  return m_background;
}
