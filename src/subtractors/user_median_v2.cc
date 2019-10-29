#include "user_median_v2.h"
#include <QJsonObject>

constexpr auto HISTORY{"History"};
constexpr auto HISTORYDELTA{"HistoryDelta"};
constexpr auto DECISION_THRESHOLD{"DecisionThreshold"};

Subtractor::Median_v2::Median_v2(QJsonObject const &a_config)
    : m_history{a_config[HISTORY].toInt()},
      m_historyDelta{a_config[HISTORYDELTA].toInt()},
      m_iteration(0),
      m_firstInitialization(true),
      m_firstTime(true),
      m_decisionThreshold{a_config[DECISION_THRESHOLD].toInt()} {}

cv::Mat Subtractor::Median_v2::process(cv::Mat &a_src) {
  m_iteration++;
  if (m_firstTime) {
    m_firstTime = false;
    m_backgroundSubtractor.InitMedian(a_src);
    m_backgroundSubtractor.AddImage(a_src);
    m_background = m_backgroundSubtractor.getMedian();
  } else if ((m_firstInitialization) and (m_iteration < m_historyDelta)) {
    m_backgroundSubtractor.AddImage(a_src);
  } else if ((m_firstInitialization) and (m_iteration >= m_historyDelta)) {
    m_firstInitialization = false;
  } else if (m_iteration >= m_historyDelta) {
    m_backgroundSubtractor.AddImage(a_src);
    m_background = m_backgroundSubtractor.getMedian();
    m_iteration = 0;
  }
  cv::Mat frame_diff;
  cv::absdiff(a_src, m_background, frame_diff);
  cv::threshold(frame_diff, frame_diff, m_decisionThreshold, 255, 0);
  return frame_diff;
}
