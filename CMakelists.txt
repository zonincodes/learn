cmake_minimum_required(VERSION 2.4) # sets a minimum cmake version required to evaluate current script

project(hello_world) # starts a new CMake project. This will trigger a lot of internal CMake
# logic, especially the detection of the default C and C++ compiler.
add_executable(app main.cpp) # With add_executable(app main.cpp) a build target app is created, which will invoke the
#configured compiler with some default flags for the current setting to compile an executable
#app from the given source file main.cpp.