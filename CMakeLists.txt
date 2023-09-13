# CMake file for CMD Defenders
# no more .bat and Python ;)

cmake_minimum_required(VERSION "3.26")

project("CMD Defenders" CXX)

# Include paths and lib path
include_directories("./Tools/recycle/src/headers/")
include_directories("./src/")
link_directories("./lib/")

# Libraries to link against
set(NEEDED_LIBS "winmm.a" "fluidsynth.dll" "nrecycle.a")

# Make the compiler stop screaming at me
set(WARNINGS -Wall -Wno-narrowing -Wno-return-type -Wno-sign-compare)

# Where is our stuff?
set(SRC_FOLDER "./src/")

set(
    GAME_SOURCE_FILES
    # end me
    ${SRC_FOLDER}collision.cpp
    ${SRC_FOLDER}deathmarker.cpp
    ${SRC_FOLDER}entity.cpp
    ${SRC_FOLDER}game.cpp
    ${SRC_FOLDER}handbook_internal.cpp
    ${SRC_FOLDER}handbook.cpp
    ${SRC_FOLDER}main.cpp
    ${SRC_FOLDER}maps.cpp
    ${SRC_FOLDER}midi.cpp
    ${SRC_FOLDER}renderer.cpp
    ${SRC_FOLDER}rng.cpp
    ${SRC_FOLDER}save.cpp
    ${SRC_FOLDER}sound.cpp
    ${SRC_FOLDER}strings.cpp
    ${SRC_FOLDER}ui.cpp
    ${SRC_FOLDER}utils.cpp
    ${SRC_FOLDER}world.cpp
)

set(NORB_DEBUG FALSE CACHE BOOL "_NORB_DEBUG_")
set(NORB_ENTER_GAME FALSE CACHE BOOL "_NORB_ENTER_GAME_")
set(NORB_NO_SAVES FALSE CACHE BOOL "_NORB_NO_SAVES_")
set(NORB_LOCAL FALSE CACHE BOOL "_NORB_LOCAL_")

if(${NORB_DEBUG})
    list(APPEND MACROS "-D_NORB_DEBUG_")
endif()

if(${NORB_ENTER_GAME})
    list(APPEND MACROS "-D_NORB_ENTER_GAME_")
endif()

if(${NORB_NO_SAVES})
    list(APPEND MACROS "-D_NORB_NO_SAVES_")
endif()

if(${NORB_LOCAL})
    list(APPEND MACROS "-D_NORB_LOCAL_")
endif()

add_compile_options(${WARNINGS} ${MACROS})
# Very epic
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)
add_executable(CmdDefenders ${GAME_SOURCE_FILES})
target_link_libraries(CmdDefenders ${NEEDED_LIBS})
add_link_options(-static-libstdc++ -static-libstdc)