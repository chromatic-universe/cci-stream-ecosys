# version
cmake_minimum_required(VERSION 3.2)


# project
project(cci_stream_mda)


#cpp flags
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g  -O0 -Duse_mongo -DACE_NTRACE=0 -DDEBUG -std=c++1z")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O3 -Duse_mongo -DACE_NTRACE=1 -DRELEASE  -std=c++1z")



add_subdirectory(src)

