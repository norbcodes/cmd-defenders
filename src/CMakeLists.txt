# CMake file for game source code

cmake_minimum_required(VERSION 3.26)
project(CmdDefenders CXX)

# Our game source code
set(
    GAME_SRC
    ${CMAKE_SOURCE_DIR}/src/collision.cpp
    ${CMAKE_SOURCE_DIR}/src/deathmarker.cpp
    ${CMAKE_SOURCE_DIR}/src/entity.cpp
    ${CMAKE_SOURCE_DIR}/src/game.cpp
    ${CMAKE_SOURCE_DIR}/src/handbook_internal.cpp
    ${CMAKE_SOURCE_DIR}/src/handbook.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/maps.cpp
    ${CMAKE_SOURCE_DIR}/src/midi.cpp
    ${CMAKE_SOURCE_DIR}/src/renderer.cpp
    ${CMAKE_SOURCE_DIR}/src/rng.cpp
    ${CMAKE_SOURCE_DIR}/src/save.cpp
    ${CMAKE_SOURCE_DIR}/src/sound.cpp
    ${CMAKE_SOURCE_DIR}/src/strings.cpp
    ${CMAKE_SOURCE_DIR}/src/ui.cpp
    ${CMAKE_SOURCE_DIR}/src/utils.cpp
    ${CMAKE_SOURCE_DIR}/src/world.cpp
)

set(
    SURPRESS_WARNINGS  # Make the compiler shut up
    -Wall -Wno-narrowing -Wno-return-type -Wno-sign-compare
)

# Our exe :D
add_executable(${PROJECT_NAME} ${GAME_SRC})
# Include paths
target_include_directories(${PROJECT_NAME} PUBLIC ${GAME_HEADERS} ${NRECYCLE_HEADERS})
# Lib paths
target_link_directories(${PROJECT_NAME} PUBLIC ${GLOBAL_LIB_DIR})
# Link it all together
target_link_libraries(${PROJECT_NAME} winmm nRecycle fluidsynth-import)
# Also add our compiler options man
target_compile_options(${PROJECT_NAME} PUBLIC ${SURPRESS_WARNINGS})