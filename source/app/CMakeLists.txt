set(INC
    .
    ../window
)

set(INC_SYS
    ${GLFW_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIR}
)

set(SRC
    intern/main.cpp
)

set(LIBS
    OpenGL32
    ${GLFW_LIBRARY}
    ${GLEW_LIBRARY}
    app_win_lib
)

include_directories(${INC})
include_directories(SYSTEM ${INC_SYS})
add_executable(app ${SRC})
target_link_libraries(app PRIVATE ${LIBS})

set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../build/bin
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../build/bin
)
