# CMake file for building nRecycle library.
# Did a little rewrite ;)

cmake_minimum_required(VERSION 3.26)
project(nRecycle CXX)

set(
    NRECYCLE_SRC
    ${CMAKE_SOURCE_DIR}/Tools/recycle/src/main.cpp
)

# libnRecycle.a
add_library(${PROJECT_NAME} STATIC ${NRECYCLE_SRC})
# Pass options to the linker
target_link_options(${PROJECT_NAME} PUBLIC -static -static-libgcc -static-libstdc++)
# Include paths
target_include_directories(${PROJECT_NAME} PUBLIC ${GAME_HEADERS} ${NRECYCLE_HEADERS})