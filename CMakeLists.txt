cmake_minimum_required(VERSION 3.2) # sets a minimum cmake version required to evaluate current script

project(random) # starts a new CMake project. This will trigger a lot of internal CMake
# logic, especially the detection of the default C and C++ compiler.
include_directories(${PROJECT_SOURCE_DIR})
# add_executable(app main.cpp foo.cpp) # With add_executable(app main.cpp) a build target app is created, which will invoke the
#configured compiler with some default flags for the current setting to compile an executable
#app from the given source file main.cpp.
add_executable(${PROJECT_NAME} main.cpp)

# Download ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT)

        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()


# CHECK ALL THE SUBMODULE
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off")
endif()

add_subdirectory(external/glfw)



add_library(applib foo.cpp)
target_link_libraries(${PROJECT_NAME} applib)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/src
)

target_link_libraries(${PROJECT_NAME} glfw)
