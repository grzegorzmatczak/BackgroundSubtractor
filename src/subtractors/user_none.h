#ifndef USER_NONE_H
#define USER_NONE_H

#include <opencv2/video.hpp>

#include "basesubtractor.h"

class QJsonObject;

namespace Subtractor
{
class None : public BaseSubtractor
{
 public:
  None();
  cv::Mat process(cv::Mat &a_src);

 private:
};
} // namespace Subtractor

#endif // USER_NONE_H
