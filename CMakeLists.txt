cmake_minimum_required(VERSION 3.0.2)
project(rasmlite_ros)

find_package(catkin REQUIRED COMPONENTS roscpp sensor_msgs)
find_package(PCL REQUIRED)
find_package(CGAL REQUIRED)
catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
  ${CGAL_INCLUDE_DIRS}
)

add_library(RASMlite STATIC include/RASMlite/mapper/decimation.cpp)
target_link_libraries(RASMlite ${PCL_LIBRARIES} ${CGAL_LIBRARIES})

add_executable(decimation_node src/decimation_node.cpp)
target_link_libraries(decimation_node RASMlite ${catkin_LIBRARIES} ${PCL_LIBRARIES})
