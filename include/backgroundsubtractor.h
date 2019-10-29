#ifndef BACKGROUND_SUBTRACTOR_H
#define BACKGROUND_SUBTRACTOR_H

#include <opencv2/imgproc.hpp>

class BaseSubtractor;
class QJsonArray;
namespace cv
{
class Mat;
class TickMeter;
} // namespace cv

class BackgroundSubtractor
{
 public:
  BackgroundSubtractor(QJsonArray const &a_subtractorConfiguration);
  ~BackgroundSubtractor();

  void configure(QJsonArray const &a_subtractorConfiguration);
  cv::Mat process(cv::Mat &a_image);
  double getElapsedTimeSubtractor();

 private:
  BaseSubtractor *m_subtractor{};
  cv::TickMeter m_timer;
};

#endif // BACKGROUND_SUBTRACTOR_H
