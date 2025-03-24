set(INC
    .
)

set(INC_SYS
    ${GLFW_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIR}
)

set(SRC
    intern/window.cpp
    window.hpp
)

include_directories(${INC})
include_directories(SYS ${INC_SYS})
add_library(app_win_lib ${SRC})
