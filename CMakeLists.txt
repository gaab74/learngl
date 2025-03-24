cmake_minimum_required(VERSION 3.30)

# ignore warnings
add_link_options(/ignore:4099,4098)

project(LearnGL)

# set startup project
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT app)

# find/set libs path
if (NOT DEFINED LIBRARIES_DIR)
    set(LIBRARIES_DIR ${PROJECT_SOURCE_DIR}/../libs)

    if (NOT EXISTS "${LIBRARIES_DIR}")
        message(FATAL_ERROR "Libraries dir not found, couldn't compile!")
    endif()
endif()

# add dependencies
include(cmake/find_opengl.cmake)
include(cmake/find_glfw3.cmake)
include(cmake/find_glew.cmake)

# project source
add_subdirectory(source)
