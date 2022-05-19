cmake_minimum_required(VERSION 3.0)

project(ProjProg2022)

file(GLOB_RECURSE SRCS src/*)

add_executable(ProjProg2022 ${SRCS})
target_link_libraries(ProjProg2022 SDL2 SDLmain SDL2_image SDL2_ttf)
