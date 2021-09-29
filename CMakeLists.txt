cmake_minimum_required(VERSION 3.7)
project(Webax)

set(CMAKE_CXX_STANDARD 23)

set(wxWidgets_ROOT_DIR </usr/include/wx-3.0>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(Webax main.cpp include/IO.hpp include/UI.hpp components/UI/app/WebaxApp.cpp components/UI/app/WebaxFrame.cpp components/UI/include/WebaxApp.hpp components/UI/include/WebaxFrame.hpp components/UI/include/WebaxEventIDs.hpp)

target_link_libraries(Webax ${wxWidgets_LIBRARIES})