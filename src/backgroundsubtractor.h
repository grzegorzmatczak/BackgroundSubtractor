#ifndef BACKGROUND_SUBTRACTOR_H
#define BACKGROUND_SUBTRACTOR_H

#include "../../IncludeSpdlog/spdlog.h"

#include <opencv2/imgproc.hpp>

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include <QTimer>

class BaseSubtractor;
class QJsonObject;
namespace cv
{
class Mat;
class TickMeter;
} // namespace cv

class BackgroundSubtractor
{
 public:
  BackgroundSubtractor(QJsonObject const &a_config);
  ~BackgroundSubtractor();

  void configure(QJsonObject const &a_config);
  cv::Mat process(cv::Mat &a_image);
  double getElapsedTimeSubtractor();

 private:
  BaseSubtractor *m_subtractor{};
  cv::TickMeter m_timer;
};

#endif // BACKGROUND_SUBTRACTOR_H
