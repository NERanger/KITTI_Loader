cmake_minimum_required(VERSION 3.1)
project(kitti_loader)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
  add_definitions(-DNDEBUG)
endif()

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
  set(CMAKE_CXX_FLAGS "-Wall -Wextra")
  set(CMAKE_CXX_FLAGS_RELEASE  "-O3")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
  set(CMAKE_CXX_FLAGS_RELEASE  "/O2")
endif()

############### Dependencies ####################

# Eigen3
find_package(Eigen3 REQUIRED)

# PCL
find_package(PCL 1.3 REQUIRED COMPONENTS common visualization)
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(
	${PCL_INCLUDE_DIRS}
	${OpenCV_INCLUDE_DIRS}
)

############### source ######################
include_directories(${PROJECT_SOURCE_DIR})

add_executable(kitti_loader example.cc KittiLoader.cc)
target_link_libraries(kitti_loader ${PCL_LIBRARIES} ${OpenCV_LIBS} Eigen3::Eigen)