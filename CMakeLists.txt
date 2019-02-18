cmake_minimum_required(VERSION 3.11)
project(apuebegin C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES chapter1/ls1.c snappy/unzcdemo.c snappy/unzcdemo.h snappy/snappytest.cpp snappy/snappytest.h)
add_executable(ls1 ${SOURCE_FILES})



set(SOURCE_FILES snappy/zcdemo.c)
add_executable(zcdemo ${SOURCE_FILES})


add_executable(unzcdemo snappy/unzcdemo.c)

set(SOURCE_FILES chapter1/exec1.c)
add_executable(exec1 ${SOURCE_FILES})



include_directories(/usr/local/include)
target_link_libraries(ls1 /usr/local/lib/libapue.a)

target_link_libraries(exec1 /usr/local/lib/libapue.a)

target_link_libraries(zcdemo /usr/local/lib/libz.a)

target_link_libraries(unzcdemo /usr/local/lib/libz.a)

########################## chapter1 #######################
add_executable(myperror chapter1/myperror.c)
target_link_libraries(myperror /usr/local/lib/libapue.a)

















#add_executable(ls1 ls1.c )