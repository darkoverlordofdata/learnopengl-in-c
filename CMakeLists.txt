cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)

include(CTest)
enable_testing()

set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w -std=c18 -O3" )

set ( SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c )

set (SOURCE ${SOURCE} ${CMAKE_CURRENT_SOURCE_DIR}/src/shmupwarz.c )
# set (SOURCE ${SOURCE} ${CMAKE_CURRENT_SOURCE_DIR}/src/triangle.c )

add_subdirectory ( libs/cfw )
add_subdirectory ( libs/util )
add_subdirectory ( libs/dna )
# add_subdirectory ( libs/artemis )

add_executable( ${PROJECT_NAME} ${SOURCE})

include_directories( ./include )
include_directories( ./libs/cfw/include )
include_directories( ./libs/util/include )
include_directories( ./libs/dna/include )
# include_directories( ./libs/artemis/include )
include_directories( ./external/stb )
include_directories( ./external/linmath.h )
 
target_link_libraries ( ${PROJECT_NAME} dl m corefw glfw GL )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
