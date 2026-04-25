################################################################################
# USE THIS IF YOU DON'T FEEL LIKE MAKING COMPLICATED MAKEFILES BY HAND.
################################################################################

add_executable(example1 example1_mathSpeedTest.cpp)
target_link_libraries(example1 PRIVATE perfkit)

## | EOF | ##