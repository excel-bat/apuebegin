cmake_minimum_required(VERSION 3.11)
project(apuebegin C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES ls1.c)
add_executable(ls1 ${SOURCE_FILES})

include_directories(/usr/local/include)
target_link_libraries(ls1 /usr/local/lib/libapue.a)

#add_executable(ls1 ls1.c )