#include "opencv_knn.h"
#include <QJsonObject>
//#include <opencv2/tracking/tracker.hpp>

constexpr auto LEARNING_RATE{ "LearningRate" };
constexpr auto HISTORY{ "History" };
constexpr auto VAR_THRESHOLD{ "VarThreshold" };
constexpr auto DETECT_SHADOW{ "DetectShadow" };

Subtractor::KNN::KNN(QJsonObject const &a_config)
  : m_learningRate{ a_config[LEARNING_RATE].toDouble() }
  , m_history{ a_config[HISTORY].toInt() }
  , m_varThreshold{ a_config[VAR_THRESHOLD].toDouble() }
  , m_detectShadows{ a_config[DETECT_SHADOW].toBool() }

{
  m_backgroundSubtractor = cv::createBackgroundSubtractorKNN(m_history, m_varThreshold, m_detectShadows);
}

cv::Mat Subtractor::KNN::process(cv::Mat &a_src)
{
  m_backgroundSubtractor->apply(a_src, m_background);
  return m_background;
}
