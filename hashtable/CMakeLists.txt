cmake_minimum_required (VERSION 3.5)

project (Module15)

set (SRC_LIST 
        main.cpp
		hashtable.cpp)
		
add_executable(hashtable ${SRC_LIST})

set (CXX_FLAGS "${CXX_FLAGS} -std=c++11  -Wall")		