cmake_minimum_required(VERSION 3.2) # sets a minimum cmake version required to evaluate current script

project(random) # starts a new CMake project. This will trigger a lot of internal CMake
# logic, especially the detection of the default C and C++ compiler.
include_directories(${PROJECT_SOURCE_DIR})
# add_executable(app main.cpp foo.cpp) # With add_executable(app main.cpp) a build target app is created, which will invoke the
#configured compiler with some default flags for the current setting to compile an executable
#app from the given source file main.cpp.
add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(external/glfw)

add_library(applib foo.cpp)
target_link_libraries(app applib)