cmake_minimum_required(VERSION 2.8)

project(greebles)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${greebles_SOURCE_DIR}/../bin)
set(CMAKE_BUILD_TYPE Debug)

add_definitions("-Wall")
add_definitions("-std=c++0x")

# WxWidgets Stuff
# http://wiki.wxwidgets.org/CMake
find_package(wxWidgets COMPONENTS core base REQUIRED)
include("${wxWidgets_USE_FILE}")

# sqlite3 Stuff
find_path(SQLITE3_INCLUDE_DIR sqlite3.h)
find_library(SQLITE3_LIBRARY sqlite3)

# SOAR Stuff
include_directories("/home/drautb/Dropbox/GitHub/SOAR/inc")
add_library(SOAR STATIC IMPORTED)
set_property(TARGET SOAR PROPERTY
			 IMPORTED_LOCATION /home/drautb/Dropbox/GitHub/SOAR/lib/libSOAR.a)

#include_directories("${CMAKE_SOURCE_DIR}/../game/inc")
include_directories("${CMAKE_SOURCE_DIR}/../setup/inc")
#include_directories("${CMAKE_SOURCE_DIR}/../custom/inc")
include_directories("${CMAKE_SOURCE_DIR}/../shared/inc")

#add_executable(game 
#			   ${CMAKE_SOURCE_DIR}/../*.cpp)
#target_link_libraries(game SOAR ${SQLITE3_LIBRARY})

add_executable(setup
			   ${CMAKE_SOURCE_DIR}/../setup/src/main.cpp
			   ${CMAKE_SOURCE_DIR}/../setup/src/SetupApp.cpp
			   ${CMAKE_SOURCE_DIR}/../setup/src/SetupFrame.cpp
			   ${CMAKE_SOURCE_DIR}/../shared/src/GeneralSettings.cpp
			   ${CMAKE_SOURCE_DIR}/../shared/src/GreeblesDatabase.cpp)
target_link_libraries(setup 
					  SOAR 
					  ${SQLITE3_LIBRARY} 
					  ${wxWidgets_LIBRARIES})

#add_executable(custom
#			   ${CMAKE_SOURCE_DIR}/../*.cpp)
#target_link_libraries(custom SOAR ${SQLITE3_LIBRARY})
