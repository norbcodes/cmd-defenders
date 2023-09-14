# RUN THIS TO COMPILE THE GAME!
cmake_minimum_required(VERSION 3.26)
# no project() directive here

set(GAME_HEADERS        ${CMAKE_SOURCE_DIR}/src/)
set(NRECYCLE_HEADERS    ${CMAKE_SOURCE_DIR}/Tools/recycle/src)
set(GLOBAL_LIB_DIR      ${CMAKE_SOURCE_DIR}/lib/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${GLOBAL_LIB_DIR})

# Create nRecycle.a
add_subdirectory(${CMAKE_SOURCE_DIR}/Tools/recycle/)
# Now compile game source code!
add_subdirectory(${CMAKE_SOURCE_DIR}/src)