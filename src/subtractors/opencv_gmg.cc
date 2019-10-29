#include "opencv_gmg.h"
#include <QJsonObject>

constexpr auto INITIALIZATION_FRAMES{"InitializationFrames"};
constexpr auto DECISION_THRESHOLD{"DecisionThreshold"};

Subtractor::GMG::GMG(QJsonObject const &a_config)
    : m_initializationFrames{a_config[INITIALIZATION_FRAMES].toInt()},
      m_decisionThreshold{a_config[DECISION_THRESHOLD].toDouble()}

{
  m_backgroundSubtractor = cv::bgsegm::createBackgroundSubtractorGMG(
      m_initializationFrames, m_decisionThreshold);
}

cv::Mat Subtractor::GMG::process(cv::Mat &a_src) {
  m_backgroundSubtractor->apply(a_src, m_background);
  return m_background;
}
