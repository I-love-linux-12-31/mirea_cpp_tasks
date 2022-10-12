cmake_minimum_required(VERSION 3.23)
project(CPP_Synthesizer_cli_app)

set(CMAKE_CXX_STANDARD 23)

add_executable(CPP_Synthesizer_cli_app Synthesizer.cpp)

# target_link_libraries(CPP_Synthesizer_cli_app alut openal)
target_link_libraries(CPP_Synthesizer_cli_app GL glut X11 pthread Xrandr Xi dl)
add_compile_options(-O3)