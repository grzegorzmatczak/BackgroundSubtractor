#include "backgroundsubtractor.h"


#include "subtractor.h"

constexpr auto FILTER_NAME{ "Name" };

BackgroundSubtractor::BackgroundSubtractor(QJsonObject const &a_config)
{
  m_subtractor = new Subtractor::None();
}

BackgroundSubtractor::~BackgroundSubtractor()
{
  delete m_subtractor;
}

void BackgroundSubtractor::configure(QJsonObject const &a_config)
{
  delete m_subtractor;
  m_timer.reset();

  auto const NAME_STRING{ a_config[FILTER_NAME].toString().toStdString() };
  auto const NAME_SID{ SID(NAME_STRING.c_str()) };

  
  switch (NAME_SID)
  {
    case SID("GSOC"): m_subtractor = { new Subtractor::GSOC{ a_config} }; break;
    case SID("KNN"): m_subtractor = { new Subtractor::KNN{ a_config} }; break;
    case SID("MOG"): m_subtractor = { new Subtractor::MOG{ a_config} }; break;
    case SID("MOG2"): m_subtractor = { new Subtractor::MOG2{ a_config} }; break;
    case SID("GMG"): m_subtractor = { new Subtractor::GMG{ a_config} }; break;
    case SID("CNT"): m_subtractor = { new Subtractor::CNT{ a_config} }; break;
    case SID("LSBP"): m_subtractor = { new Subtractor::LSBP{ a_config} }; break;
    case SID("None"): m_subtractor = { new Subtractor::None() }; break;
    case SID("Median"): m_subtractor = { new Subtractor::Median(a_config) }; break;
    default: H_Logger->error("Unsupported subtractor type: {}", NAME_STRING); break;
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
