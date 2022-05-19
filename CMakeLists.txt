cmake_minimum_required(VERSION 3.0)

project(ProjProg2022)

file(GLOB_RECURSE SRCS src/*)

add_executable(ProjProg2022 ${SRCS} src/Rooms/Wall.cpp src/Rooms/Wall.h src/Rooms/Door.cpp src/Rooms/Door.h src/Rooms/ClosedDoor.cpp src/Rooms/ClosedDoor.h src/Rooms/Collision.cpp src/Rooms/Collision.h)
target_link_libraries(ProjProg2022 SDL2)
