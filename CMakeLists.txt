cmake_minimum_required(VERSION 2.8.3)
project(topic_transcriber)

add_compile_options(-std=c++17)
set(CMAKE_CXX_FLAGS "-std=c++17 ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_STANDARD 17)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
)

catkin_package(
    INCLUDE_DIRS include
)

include_directories(
 ${catkin_INCLUDE_DIRS}
 include/${PROJECT_NAME}
)

add_executable(topic_transcriber_example src/example.cpp)

target_link_libraries(topic_transcriber_example
  ${catkin_LIBRARIES}
)

add_dependencies(topic_transcriber_example ${catkin_EXPORTED_TARGETS})
