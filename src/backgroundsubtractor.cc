#include "../../BackgroundSubtractor/include/backgroundsubtractor.h"
#include "../../IncludeSpdlog/spdlog.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include <QTimer>
#include "subtractor.h"

constexpr auto FILTER_NAME{ "Name" };

BackgroundSubtractor::BackgroundSubtractor(QJsonArray const &a_subtractorConfiguration)
{
  configure(a_subtractorConfiguration);
}

BackgroundSubtractor::~BackgroundSubtractor()
{
  delete m_subtractor;
}

void BackgroundSubtractor::configure(QJsonArray const &a_subtractorConfiguration)
{
  delete m_subtractor;
  m_timer.reset();
  // qDebug() << "BackgroundSubtractor:" << a_subtractorConfiguration << endl;
  for (auto const &SUBTRACTOR_CONFIG : a_subtractorConfiguration)
  {
    auto const NAME_STRING{ SUBTRACTOR_CONFIG[FILTER_NAME].toString().toStdString() };
    auto const NAME_SID{ SID(NAME_STRING.c_str()) };

    switch (NAME_SID)
    {
      case SID("OpenCV_GSOC"): m_subtractor = new Subtractor::GSOC{ SUBTRACTOR_CONFIG.toObject() }; break;
      case SID("OpenCV_KNN"): m_subtractor = { new Subtractor::KNN{ SUBTRACTOR_CONFIG.toObject() } }; break;
      case SID("OpenCV_MOG"): m_subtractor = { new Subtractor::MOG{ SUBTRACTOR_CONFIG.toObject() } }; break;
      case SID("OpenCV_MOG2"): m_subtractor = { new Subtractor::MOG2{ SUBTRACTOR_CONFIG.toObject() } }; break;
      case SID("OpenCV_GMG"): m_subtractor = { new Subtractor::GMG{ SUBTRACTOR_CONFIG.toObject() } }; break;
      case SID("OpenCV_CNT"): m_subtractor = { new Subtractor::CNT{ SUBTRACTOR_CONFIG.toObject() } }; break;
      case SID("OpenCV_LSBP"): m_subtractor = { new Subtractor::LSBP{ SUBTRACTOR_CONFIG.toObject() } }; break;
      case SID("None"): m_subtractor = { new Subtractor::None{ SUBTRACTOR_CONFIG.toObject() } }; break;
      default: H_Logger->error("Unsupported filter type: {}", NAME_STRING); break;
    }
  }
}

cv::Mat BackgroundSubtractor::process(cv::Mat &a_image)
{
  m_timer.start();
  H_Logger->trace("BackgroundSubtractor::process(a_image)");
  cv::Mat out = m_subtractor->process(a_image);
  m_timer.stop();
  return out;
}

double BackgroundSubtractor::getElapsedTimeSubtractor()
{
  return m_timer.getTimeMilli();
}
