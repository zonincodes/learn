cmake_minimum_required(VERSION 3.22)

project(random) 
find_package(OpenGL REQUIRED)
include_directories(${PROJECT_SOURCE_DIR})

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
add_subdirectory(external/linmath)
add_subdirectory(src)



add_library(applib foo.cpp)
target_link_libraries(${PROJECT_NAME} applib)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
    PUBLIC linmath
    PUBLIC src
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC external/linmath
    PUBLIC external/glfw/src
    PUBLIC src
)

target_link_libraries(${PROJECT_NAME} glfw linmath src)
