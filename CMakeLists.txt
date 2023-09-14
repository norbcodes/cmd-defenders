# RUN THIS TO COMPILE THE GAME!
cmake_minimum_required(VERSION 3.26)
# no project() directive here

set(GAME_HEADERS        ${CMAKE_SOURCE_DIR}/src/)
set(NRECYCLE_HEADERS    ${CMAKE_SOURCE_DIR}/Tools/recycle/src)
set(GLOBAL_LIB_DIR      ${CMAKE_SOURCE_DIR}/lib/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${GLOBAL_LIB_DIR})

set(BUILD_MODE "Release" CACHE STRING BUILD_MODE)
# NORB_BUILD_MODE might be:
# Release - No macros applied + optimization and static linkage
# Debug   - NORB_DEBUG; NORB_NO_SAVES; NORB_LOCAL macros applied
# Debug+  - All macros mentioned above + compile with debug and Og optimization

# Create nRecycle.a
add_subdirectory(${CMAKE_SOURCE_DIR}/Tools/recycle/)
# Now compile game source code!
add_subdirectory(${CMAKE_SOURCE_DIR}/src)