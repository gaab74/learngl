add_definitions(-DGLEW_STATIC)

if (NOT DEFINED GLEW_INCLUDE_DIR)
    set(GLEW_INCLUDE_DIR ${LIBRARIES_DIR}/GLEW/include)

    if (NOT EXISTS "${GLEW_INCLUDE_DIR}")
        message(FATAL_ERROR "Couldn't find GLEW include dir!")
    endif()
endif()

if (NOT DEFINED GLEW_LIBRARY)
    set(GLEW_LIBRARY ${LIBRARIES_DIR}/GLEW/lib/glew32s.lib)

    if (NOT EXISTS "${GLEW_LIBRARY}")
        message(FATAL_ERROR "Couldn't find GLEW library!")
    endif()
endif()
