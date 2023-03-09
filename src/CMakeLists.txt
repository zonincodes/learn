cmake_minimum_required(VERSION 3.0)
project(Glad)

add_library(src glad.h glad.c khrplatform.h)
target_include_directories(src PUBLIC include/)