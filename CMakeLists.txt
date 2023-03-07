cmake_minimum_required(VERSION 2.4)
project(learn_three) 
include_directories(${PROJECT_SOURCE_DIR})
add_library(applib foo.cpp)
add_executable(app main.cpp)
target_link_libraries(app applib)


CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)
SET(PROJ_NAME "app")
PROJECT(${PROJ_NAME})
# Configuration Types

SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
IF(DEFINED CMAKE_BUILD_TYPE AND CMAKE_VERSION VERSION_GREATER "2.8")
    SET_PROPERTY(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES})
ENDIF()

SET(${PROJ_NAME}_PATH_INSTALL "/opt/project" CACHE PATH "This directory contains installation Path")
SET(CMAKE_DEBUG_POSTFIX "D")

# install
# -------------------------------------#
INSTALL(TARGETS ${PROJ_NAME}
    DESTINATION "${${PROJ_NAME}_PATH_INSTALL}/bin/${CMAKE_BUILD_TYPE}/")