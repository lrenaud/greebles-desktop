cmake_minimum_required(VERSION 2.8)

project(greebles)

##########################################################
# Select Build Type
##########################################################
set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)

##########################################################
# Select Platform
##########################################################
# set(CFG_PLATFORM windows)
# set(CFG_PLATFORM mac)
set(CFG_PLATFORM linux)

##########################################################
# Set lots of variables
##########################################################
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin/${CFG_PLATFORM}/${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_FLAGS_DEBUG "-DCFG_DEBUG -g")
set(CMAKE_CXX_FLAGS_RELEASE "-DCFG_RELEASE")

# Paths to source for Game, Setup App, and Custom App
set(SHARED_PATH_TO_INC ${CMAKE_SOURCE_DIR}/../src/shared/inc)
set(SHARED_PATH_TO_SRC ${CMAKE_SOURCE_DIR}/../src/shared/src)
set(GAME_PATH_TO_INC ${CMAKE_SOURCE_DIR}/../src/game/inc)
set(GAME_PATH_TO_SRC ${CMAKE_SOURCE_DIR}/../src/game/src)
set(SETUP_PATH_TO_INC ${CMAKE_SOURCE_DIR}/../src/setup/inc)
set(SETUP_PATH_TO_SRC ${CMAKE_SOURCE_DIR}/../src/setup/src)
set(CUSTOM_PATH_TO_INC ${CMAKE_SOURCE_DIR}/../src/custom/inc)
set(CUSTOM_PATH_TO_SRC ${CMAKE_SOURCE_DIR}/../src/custom/src)
set(JOIN_PATH_TO_INC ${CMAKE_SOURCE_DIR}/../src/join/inc)
set(JOIN_PATH_TO_SRC ${CMAKE_SOURCE_DIR}/../src/join/src)
set(ZAP_PATH_TO_INC ${CMAKE_SOURCE_DIR}/../src/zap/inc)
set(ZAP_PATH_TO_SRC ${CMAKE_SOURCE_DIR}/../src/zap/src)
set(ERROR_PATH_TO_INC ${CMAKE_SOURCE_DIR}/../src/error/inc)
set(ERROR_PATH_TO_SRC ${CMAKE_SOURCE_DIR}/../src/error/src)

set(COMMON_DIR common)
set(WINDOWS_DIR windows)
set(MAC_DIR mac)
set(LINUX_DIR linux)

##########################################################
# WxWidgets Library
# http://wiki.wxwidgets.org/CMake
##########################################################
find_package(wxWidgets COMPONENTS core base REQUIRED)
include("${wxWidgets_USE_FILE}")

##########################################################
# SQLite3 Library
##########################################################
find_path(SQLITE3_INCLUDE_DIR sqlite3.h)
find_library(SQLITE3_LIBRARY sqlite3)

##########################################################
# SOAR Library
##########################################################
set(SOAR_INC_PATH_BASE /home/drautb/Dropbox/GitHub/SOAR/src/soar/inc)
set(SOAR_LIB_PATH_BASE /home/drautb/Dropbox/GitHub/SOAR/lib)

set(SOAR_INC_PATH 
	${SOAR_INC_PATH_BASE}/${COMMON_DIR}
	${SOAR_INC_PATH_BASE}/${CFG_PLATFORM})

include_directories("${SOAR_INC_PATH}")

add_library(SOAR STATIC IMPORTED)

set_property(TARGET SOAR PROPERTY
			 IMPORTED_LOCATION ${SOAR_LIB_PATH_BASE}/${CFG_PLATFORM}/${CMAKE_BUILD_TYPE}/libSOAR.a)

##########################################################
# Greebles Include Directories
##########################################################
include_directories("${SHARED_PATH_TO_INC}/${COMMON_DIR}")
include_directories("${SHARED_PATH_TO_INC}/${CFG_PLATFORM}")

include_directories("${GAME_PATH_TO_INC}/${COMMON_DIR}")
include_directories("${GAME_PATH_TO_INC}/${CFG_PLATFORM}")

include_directories("${SETUP_PATH_TO_INC}/${COMMON_DIR}")
include_directories("${SETUP_PATH_TO_INC}/${CFG_PLATFORM}")

include_directories("${CUSTOM_PATH_TO_INC}/${COMMON_DIR}")
include_directories("${CUSTOM_PATH_TO_INC}/${CFG_PLATFORM}")

include_directories("${JOIN_PATH_TO_INC}/${COMMON_DIR}")
include_directories("${JOIN_PATH_TO_INC}/${CFG_PLATFORM}")

include_directories("${ZAP_PATH_TO_INC}/${COMMON_DIR}")
include_directories("${ZAP_PATH_TO_INC}/${CFG_PLATFORM}")

include_directories("${ERROR_PATH_TO_INC}/${COMMON_DIR}")
include_directories("${ERROR_PATH_TO_INC}/${CFG_PLATFORM}")

###########################################################
# Shared Source Files
###########################################################
set(SHARED_COMMON_SRCS
	${SHARED_PATH_TO_SRC}/${COMMON_DIR}/GeneralSettings.cpp
	${SHARED_PATH_TO_SRC}/${COMMON_DIR}/GreeblesDatabase.cpp
	${SHARED_PATH_TO_SRC}/${COMMON_DIR}/StaticLookup.cpp
	${SHARED_PATH_TO_SRC}/${COMMON_DIR}/DifficultyLookup.cpp
	${SHARED_PATH_TO_SRC}/${COMMON_DIR}/PlayerTypeLookup.cpp
	${SHARED_PATH_TO_SRC}/${COMMON_DIR}/PlayerSettings.cpp
	${SHARED_PATH_TO_SRC}/${COMMON_DIR}/KeyTranslator.cpp
	${SHARED_PATH_TO_SRC}/${COMMON_DIR}/ControlSet.cpp
	${SHARED_PATH_TO_SRC}/${COMMON_DIR}/Utility.cpp
    ${SHARED_PATH_TO_SRC}/${COMMON_DIR}/LocalHumanStringFormatter.cpp)

set(SHARED_WINDOWS_SRCS )

set(SHARED_MAC_SRCS )

set(SHARED_LINUX_SRCS )

###########################################################
# Game Source Files
###########################################################
set(GAME_COMMON_SRCS )

set(GAME_WINDOWS_SRCS )

set(GAME_MAC_SRCS )

set(GAME_LINUX_SRCS )

###########################################################
# Setup Source Files
###########################################################
set(SETUP_COMMON_SRCS 
	${SETUP_PATH_TO_SRC}/${COMMON_DIR}/main.cpp
	${SETUP_PATH_TO_SRC}/${COMMON_DIR}/SetupApp.cpp
	${SETUP_PATH_TO_SRC}/${COMMON_DIR}/SetupFrame.cpp
    ${SETUP_PATH_TO_SRC}/${COMMON_DIR}/wxNoLabelCheckBox.cpp
    ${SETUP_PATH_TO_SRC}/${COMMON_DIR}/wxFocusableStaticText.cpp
    ${SETUP_PATH_TO_SRC}/${COMMON_DIR}/NewKeyDialog.cpp
    ${SETUP_PATH_TO_SRC}/${COMMON_DIR}/wxPlayerDropTarget.cpp)

set(SETUP_WINDOWS_SRCS )

set(SETUP_MAC_SRCS )

set(SETUP_LINUX_SRCS )

###########################################################
# Custom Source Files
###########################################################
set(CUSTOM_COMMON_SRCS
    ${CUSTOM_PATH_TO_SRC}/${COMMON_DIR}/main.cpp
    ${CUSTOM_PATH_TO_SRC}/${COMMON_DIR}/CustomApp.cpp
    ${CUSTOM_PATH_TO_SRC}/${COMMON_DIR}/CustomFrame.cpp)

set(CUSTOM_WINDOWS_SRCS )

set(CUSTOM_MAC_SRCS )

set(CUSTOM_LINUX_SRCS )

###########################################################
# Join Source Files
###########################################################
set(JOIN_COMMON_SRCS 
    ${JOIN_PATH_TO_SRC}/${COMMON_DIR}/main.cpp
    ${JOIN_PATH_TO_SRC}/${COMMON_DIR}/JoinApp.cpp
    ${JOIN_PATH_TO_SRC}/${COMMON_DIR}/JoinFrame.cpp)

set(JOIN_WINDOWS_SRCS )

set(JOIN_MAC_SRCS )

set(JOIN_LINUX_SRCS )

###########################################################
# Zap Source Files
###########################################################
set(ZAP_COMMON_SRCS
    ${ZAP_PATH_TO_SRC}/${COMMON_DIR}/main.cpp
    ${ZAP_PATH_TO_SRC}/${COMMON_DIR}/ZapApp.cpp
    ${ZAP_PATH_TO_SRC}/${COMMON_DIR}/ZapFrame.cpp)

set(ZAP_WINDOWS_SRCS )

set(ZAP_MAC_SRCS )

set(ZAP_LINUX_SRCS )

###########################################################
# Error Source Files
###########################################################
set(ERROR_COMMON_SRCS
    ${ERROR_PATH_TO_SRC}/${COMMON_DIR}/main.cpp
    ${ERROR_PATH_TO_SRC}/${COMMON_DIR}/ErrorApp.cpp
    ${ERROR_PATH_TO_SRC}/${COMMON_DIR}/ErrorFrame.cpp)

set(ERROR_WINDOWS_SRCS )

set(ERROR_MAC_SRCS )

set(ERROR_LINUX_SRCS )

if (CFG_PLATFORM STREQUAL WINDOWS_DIR)
    add_definitions("-DWINDOWS")
    set(GAME_SRCS ${SHARED_COMMON_SRCS} ${SHARED_WINDOWS_SRCS} ${GAME_COMMON_SRCS} ${GAME_WINDOWS_SRCS})
    set(SETUP_SRCS ${SHARED_COMMON_SRCS} ${SHARED_WINDOWS_SRCS} ${SETUP_COMMON_SRCS} ${SETUP_WINDOWS_SRCS})
    set(CUSTOM_SRCS ${SHARED_COMMON_SRCS} ${SHARED_WINDOWS_SRCS} ${CUSTOM_COMMON_SRCS} ${CUSTOM_WINDOWS_SRCS})
    set(JOIN_SRCS ${SHARED_COMMON_SRCS} ${SHARED_WINDOWS_SRCS} ${JOIN_COMMON_SRCS} ${JOIN_WINDOWS_SRCS})
    set(ZAP_SRCS ${SHARED_COMMON_SRCS} ${SHARED_WINDOWS_SRCS} ${ZAP_COMMON_SRCS} ${ZAP_WINDOWS_SRCS})
    set(ERROR_SRCS ${SHARED_COMMON_SRCS} ${SHARED_WINDOWS_SRCS} ${ERROR_COMMON_SRCS} ${ERROR_WINDOWS_SRCS})
elseif (CFG_PLATFORM STREQUAL MAC_DIR)
    add_definitions("-DMACOSX")
    set(GAME_SRCS ${SHARED_COMMON_SRCS} ${SHARED_MAC_SRCS} ${GAME_COMMON_SRCS} ${GAME_MAC_SRCS})
    set(SETUP_SRCS ${SHARED_COMMON_SRCS} ${SHARED_MAC_SRCS} ${SETUP_COMMON_SRCS} ${SETUP_MAC_SRCS})
    set(CUSTOM_SRCS ${SHARED_COMMON_SRCS} ${SHARED_MAC_SRCS} ${CUSTOM_COMMON_SRCS} ${CUSTOM_MAC_SRCS})
    set(JOIN_SRCS ${SHARED_COMMON_SRCS} ${SHARED_MAC_SRCS} ${JOIN_COMMON_SRCS} ${JOIN_MAC_SRCS})
    set(ZAP_SRCS ${SHARED_COMMON_SRCS} ${SHARED_MAC_SRCS} ${ZAP_COMMON_SRCS} ${ZAP_MAC_SRCS})
    set(ERROR_SRCS ${SHARED_COMMON_SRCS} ${SHARED_MAC_SRCS} ${ERROR_COMMON_SRCS} ${ERROR_MAC_SRCS})
elseif (CFG_PLATFORM STREQUAL LINUX_DIR)
    add_definitions("-DLINUX")
    set(GAME_SRCS ${SHARED_COMMON_SRCS} ${SHARED_LINUX_SRCS} ${GAME_COMMON_SRCS} ${GAME_LINUX_SRCS})
    set(SETUP_SRCS ${SHARED_COMMON_SRCS} ${SHARED_LINUX_SRCS} ${SETUP_COMMON_SRCS} ${SETUP_LINUX_SRCS})
    set(CUSTOM_SRCS ${SHARED_COMMON_SRCS} ${SHARED_LINUX_SRCS} ${CUSTOM_COMMON_SRCS} ${CUSTOM_LINUX_SRCS})
    set(JOIN_SRCS ${SHARED_COMMON_SRCS} ${SHARED_LINUX_SRCS} ${JOIN_COMMON_SRCS} ${JOIN_LINUX_SRCS})
    set(ZAP_SRCS ${SHARED_COMMON_SRCS} ${SHARED_LINUX_SRCS} ${ZAP_COMMON_SRCS} ${ZAP_LINUX_SRCS})
    set(ERROR_SRCS ${SHARED_COMMON_SRCS} ${SHARED_LINUX_SRCS} ${ERROR_COMMON_SRCS} ${ERROR_LINUX_SRCS})
endif()

add_definitions("-Wall")                # Give ALL the warnings!
add_definitions("-Werror")              # Treat ALL The warnings as errors
add_definitions("-pedantic-errors")     # Only allow standard-compliant code
add_definitions("-std=c++11")           # Use the 2011 C++ Standard

#add_executable(game ${GAME_SRCS})
#target_link_libraries(game SOAR ${SQLITE3_LIBRARY} /usr/local/lib/FMOD/libfmodex64.so)

add_executable(setup ${SETUP_SRCS})
target_link_libraries(setup 
					  SOAR 
					  ${SQLITE3_LIBRARY} 
					  ${wxWidgets_LIBRARIES})

add_executable(custom ${CUSTOM_SRCS})
target_link_libraries(custom 
                      SOAR 
                      ${SQLITE3_LIBRARY}
                      ${wxWidgets_LIBRARIES})

add_executable(join ${JOIN_SRCS})
target_link_libraries(join 
                      SOAR 
                      ${SQLITE3_LIBRARY}
                      ${wxWidgets_LIBRARIES})

add_executable(zap ${ZAP_SRCS})
target_link_libraries(zap 
                      SOAR 
                      ${SQLITE3_LIBRARY}
                      ${wxWidgets_LIBRARIES})

add_executable(error ${ERROR_SRCS})
target_link_libraries(error 
                      SOAR
                      ${SQLITE3_LIBRARY} 
                      ${wxWidgets_LIBRARIES})
