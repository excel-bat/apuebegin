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

add_executable(mysignal chapter1/mysignal.c)
target_link_libraries(mysignal /usr/local/lib/libapue.a)

########################## chapter2 #######################
add_executable(mypath_max chapter2/mypath_max.c)
target_link_libraries(mypath_max /usr/local/lib/libapue.a)

########################## chapter3 #######################
add_executable(mystdio chapter3/mystdio.c)
target_link_libraries(mystdio /usr/local/lib/libapue.a)
add_executable(myoffsetio chapter3/myoffsetio.c)
target_link_libraries(myoffsetio /usr/local/lib/libapue.a)
add_executable(myfcntl chapter3/myfcntl.c)
target_link_libraries(myfcntl /usr/local/lib/libapue.a)
add_executable(myeffectio chapter3/myeffectio.c)
target_link_libraries(myeffectio /usr/local/lib/libapue.a)
add_executable(mycreateempty chapter3/mycreateempty.c)
target_link_libraries(mycreateempty /usr/local/lib/libapue.a)

########################## chapter4 #######################
add_executable(myfiletype chapter4/myfiletype.c)
target_link_libraries(myfiletype /usr/local/lib/libapue.a)
















#add_executable(ls1 ls1.c )