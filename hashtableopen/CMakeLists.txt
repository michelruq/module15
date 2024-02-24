cmake_minimum_required (VERSION 3.5)

project (Module15)

set (SRC_LIST 
        main.cpp
		hashtableopen.cpp
		chainnode.cpp)
		
add_executable(hashtableopen ${SRC_LIST})

set (CXX_FLAGS "${CXX_FLAGS} -std=c++11  -Wall")		