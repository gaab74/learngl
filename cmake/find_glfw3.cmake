if (NOT DEFINED GLFW_INCLUDE_DIR)
    set(GLFW_INCLUDE_DIR ${LIBRARIES_DIR}/GLFW/include)

    if (NOT EXISTS "${GLFW_INCLUDE_DIR}")
        message(FATAL_ERROR "Couldn't find GLFW include dir!")
    endif()
endif()

if (NOT DEFINED GLFW_LIBRARY)
    set(GLFW_LIBRARY ${LIBRARIES_DIR}/GLFW/lib/glfw3.lib)

    if (NOT EXISTS "${GLFW_LIBRARY}")
        message(FATAL_ERROR "Couldn't find GLFW library!")
    endif()
endif()
