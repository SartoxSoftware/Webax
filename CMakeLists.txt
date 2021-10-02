cmake_minimum_required(VERSION 3.7)
project(Webax)

set(CMAKE_CXX_STANDARD 23)

set(wxWidgets_ROOT_DIR </usr/include/wx-3.0>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

# CSock
set(CSOCK_FILES lib/include/csock/unix/BaseSocketUnix.hpp lib/include/csock/ClientSession.hpp lib/include/csock/BaseSocket.hpp lib/include/csock/Request.hpp lib/include/csock/windows/BaseSocketWindows.hpp lib/csock/unix/BaseSocketUnix.cpp lib/csock/ClientSession.cpp lib/csock/BaseSocket.cpp lib/csock/Request.cpp lib/csock/windows/BaseSocketWindows.cpp lib/csock/HttpClientSession.cpp lib/include/csock/HttpClientSession.hpp lib/csock/HttpRequest.cpp lib/include/csock/HttpRequest.hpp)
set(CSOCK_INCLUDE_DIRECTORY lib/include/csock)

add_library(csock ${CSOCK_FILES})
target_include_directories(csock PRIVATE ${CSOCK_INCLUDE_DIRECTORY})

add_executable(Webax ${CSOCK_FILES} main.cpp include/IO.hpp include/UI.hpp components/UI/app/WebaxApp.cpp components/UI/app/WebaxFrame.cpp components/UI/include/WebaxApp.hpp components/UI/include/WebaxFrame.hpp components/UI/include/WebaxEventIDs.hpp components/UI/widgets/EntryContainer/EntryContainer.cpp components/UI/include/EntryContainer.hpp components/UI/widgets/CoreRenderContainer/CoreRenderContainer.cpp components/UI/include/CoreRenderContainer.hpp include/Util.hpp)
target_include_directories(Webax PRIVATE ${CSOCK_INCLUDE_DIRECTORY})

target_link_libraries(Webax ${wxWidgets_LIBRARIES})