#include "user_none.h"
//#include <opencv2/tracking/tracker.hpp>
#include <QJsonObject>

Subtractor::None::None() {}

cv::Mat Subtractor::None::process(cv::Mat &a_src)
{
  return a_src;
}
