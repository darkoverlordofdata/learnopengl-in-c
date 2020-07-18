
add_executable( test_bitvector test_bitvector.c ${SOURCE} )
add_executable( test_cfw test_cfw.c ${SOURCE} )
add_executable( test_oop test_oop.c ${SOURCE} )
add_executable( test_random test_random.c ${SOURCE} )
add_executable( test_uuid test_uuid.c ${SOURCE} )

target_link_libraries ( test_bitvector dl m BlocksRuntime corefw glfw GL )
target_link_libraries ( test_cfw dl m BlocksRuntime corefw glfw GL )
target_link_libraries ( test_oop dl m BlocksRuntime corefw glfw GL )
target_link_libraries ( test_random dl m BlocksRuntime corefw glfw GL )
target_link_libraries ( test_uuid dl m BlocksRuntime corefw glfw GL )

add_test(bitvector test_bitvector )                      
add_test(cfw test_cfw )                      
add_test(oop test_oop )                      
add_test(random test_random )                      
add_test(uuid test_uuid )                      


