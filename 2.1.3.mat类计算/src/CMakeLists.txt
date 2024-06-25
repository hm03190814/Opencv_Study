cmake_minimum_required(VERSION 3.15)
project(test)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp include/*.h)
add_executable(test ${SRC})
find_package(OpenCV REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS})
