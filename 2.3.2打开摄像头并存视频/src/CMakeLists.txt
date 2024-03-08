cmake_minimum_required(VERSION 3.16)
project(opencv_test)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED) # 找OPENCV4.5.0的安装路径
include_directories(${OpenCV_INCLUDE_DIRS}) #加载OPENCV4.5.0的头文件

add_executable(opencv_test main.cpp)
target_link_libraries(opencv_test ${OpenCV_LIBS})

