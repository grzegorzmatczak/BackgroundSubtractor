cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(MIFExample
  VERSION 0.0.1
  DESCRIPTION "Example usage of MultiImageFilter"
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS_COMMON}")
set(TARGET_NAME "MIFExample")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

find_package(Qt5Core REQUIRED)
find_package(BackgroundSubtractor)

set(SRC
  src/main.cc
)

set(HEADERS
)


add_executable(${TARGET_NAME}
    ${SRC}
    ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core BackgroundSubtractor opencv_highgui)
