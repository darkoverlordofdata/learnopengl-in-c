cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)

include(CTest)
enable_testing()

set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w -std=c18 -O3" )

set ( SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c )

set (SOURCE ${SOURCE} ${CMAKE_CURRENT_SOURCE_DIR}/src/shmupwarz.c )

add_subdirectory ( libs/dna )

add_executable( ${PROJECT_NAME} ${SOURCE})

include_directories(./include)
include_directories(./libs/dna/include)
include_directories(./external/stb)
 
target_link_libraries ( ${PROJECT_NAME} dl m corefw glfw GL )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
