cmake_minimum_required(VERSION 3.16.0)
project(flipkart2_gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
find_package(catkin REQUIRED COMPONENTS 
    rviz 
    roscpp 
    sensor_msgs
    std_msgs
    )
include_directories(${catkin_INCLUDE_DIRS})
catkin_package()
set(CMAKE_PREFIX_PATH "/opt/Qt5.12.6/5.12.6/gcc_64")
set(ModuleList 
    Core
    Gui
    Widgets
    Network
)

foreach(QtModule ${ModuleList})
    set(Qt5${QtModule}_DIR ${CMAKE_PREFIX_PATH}/lib/cmake/Qt5${QtModule})
    message("foreach-> Qt5${QtModule}_DIR : ${Qt5${QtModule}_DIR}")
    set(QT_LIBRARIES ${QT_LIBRARIES} Qt5::${QtModule})
endforeach()
message("${QT_LIBRARIES}")
find_package(Qt5 REQUIRED ${ModuleList})
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/flipkart2_gui/*.hpp )
QT5_WRAP_UI(UI_HEADERS ui/mainwindow.ui)
QT5_WRAP_CPP(QT_MOC_HPP ${QT_MOC})
catkin_package()
include_directories( ${catkin_INCLUDE_DIRS})
file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp )
add_executable(flipkart2_gui  ${QT_SOURCES} ${QT_MOC_HPP} ${UI_HEADERS})
target_link_libraries(flipkart2_gui ${QT_LIBRARIES} ${catkin_LIBRARIES})
install(TARGETS flipkart2_gui RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
