cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)

include(CTest)
enable_testing()

set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w -std=c18 -O3" )
set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fblocks" )

set (SOURCE ${SOURCE} ${CMAKE_CURRENT_SOURCE_DIR}/src/shmupwarz.c )
set (SOURCE ${SOURCE} ${CMAKE_CURRENT_SOURCE_DIR}/src/oop/animal.c )
set (SOURCE ${SOURCE} ${CMAKE_CURRENT_SOURCE_DIR}/src/oop/cat.c )
set (SOURCE ${SOURCE} ${CMAKE_CURRENT_SOURCE_DIR}/src/oop/dog.c )

# if (EXISTS ${CMAKE_SOURCE_DIR}/data )
#     add_subdirectory (data)
#     list ( APPEND RESOURCES ${resources_gresource_xml_C_FILE} )
# endif ()

add_subdirectory ( libs/cfw )
add_subdirectory ( libs/dna )
# add_subdirectory ( libs/artemis )

add_executable( ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c ${SOURCE} )


include_directories( ./include )
include_directories( ./libs/cfw/include )
include_directories( ./libs/dna/include )
# include_directories( ./libs/artemis/include )
include_directories( ./external/stb )
include_directories( ./external/linmath.h )
 
add_subdirectory(tests)
target_link_libraries ( ${PROJECT_NAME} dl m BlocksRuntime corefw glfw GL )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

