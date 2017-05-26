cmake_minimum_required(VERSION 2.8)
set(EXE_NAME opensteno)

if(NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type")
endif()

project(${EXE_NAME})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(OPENSTENO_LIBRARIES "")

find_package(CXX14 REQUIRED)

set(CMAKE_CXX_FLAGS "${CXX14_FLAGS} ${CMAKE_CXX_FLAGS}")

find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})
list(APPEND OPENSTENO_LIBRARIES ${X11_LIBRARIES})

find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
list(APPEND OPENSTENO_LIBRARIES ${Qt5Widgets_LIBRARIES})

find_package (Threads)
list(APPEND OPENSTENO_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
  add_definitions("-Wall")
endif ()

add_subdirectory(source)

if (CMAKE_VERSION VERSION_GREATER 2.8.5)
  include(FeatureSummary)
  feature_summary(WHAT ALL)
endif ()
