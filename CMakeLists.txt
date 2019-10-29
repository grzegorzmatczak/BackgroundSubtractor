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

# include QT
set(CMAKE_AUTOMOC ON)
find_package(Qt5Core REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Block REQUIRED)
#include fix for OpenCV
include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set(SRC
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
    src/subtractors/user_median.cc
    src/subtractors/user_median.h
    src/subtractors/user_median_implementation.cc
    src/subtractors/user_median_implementation.h
    src/subtractors/user_median_v2.cc
    src/subtractors/user_median_v2.h
    src/subtractors/user_median_v2_implementation.cc
    src/subtractors/user_median_v2_implementation.h
    src/subtractors/user_none.cc
    src/subtractors/user_none.h
)

set(HEADERS
    include/backgroundsubtractor.h
)

add_library(${PROJECT_NAME} SHARED
    ${SRC}
    ${HEADERS}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    opencv_core
    opencv_imgcodecs
    opencv_bgsegm
    Block
)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "/usr" CACHE PATH "default install path" FORCE )
endif()

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Config
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES  ${HEADERS} DESTINATION include)
install(EXPORT ${PROJECT_NAME}Config DESTINATION share/${PROJECT_NAME}/cmake)

export(TARGETS ${PROJECT_NAME} FILE ${PROJECT_NAME}Config.cmake)
add_subdirectory(example)
