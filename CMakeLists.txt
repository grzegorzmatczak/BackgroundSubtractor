cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(BackgroundSubtractor
  VERSION 0.0.1
  DESCRIPTION "BackgroundSubtractor"
  LANGUAGES C CXX)

set(DEFAULT_BUILD_TYPE "Release")

#STNDARD STUFF
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS_COMMON}")

set(TARGET_NAME "BackgroundSubtractor")
include_directories("${PROJECT_SOURCE_DIR}/../IncludeSpdlog/include")
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(OpenCV REQUIRED)
#include fix for OpenCV
include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

set(SRC
    src/main.cc
    ../../IncludeSpdlog/spdlog.cc
    ../../IncludeSpdlog/spdlog.h
    src/subtractors/basesubtractor.h
    src/subtractors/basesubtractor.cc
    src/subtractors/opencv_gsoc.cc
    src/subtractors/opencv_gsoc.h
    src/subtractors/opencv_knn.cc
    src/subtractors/opencv_knn.h
    src/backgroundsubtractor.cc
    src/subtractor.h
    src/subtractors/opencv_mog2.cc
    src/subtractors/opencv_mog2.h
    src/subtractors/opencv_gmg.cc
    src/subtractors/opencv_gmg.h
    src/subtractors/opencv_cnt.cc
    src/subtractors/opencv_cnt.h
    src/subtractors/opencv_lsbp.cc
    src/subtractors/opencv_lsbp.h
    src/subtractors/opencv_mog.cc
    src/subtractors/opencv_mog.h
    src/subtractors/user_none.cc
    src/subtractors/user_none.h
    src/subtractors/user_median.cc
    src/subtractors/user_median.h
    src/subtractors/user_median_implementation.cc
    src/subtractors/user_median_implementation.h
)

set(HEADERS
    src/backgroundsubtractor.h
)

add_executable(${TARGET_NAME}
    ${SRC}
    ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core ${OpenCV_LIBS} Threads::Threads )
