cmake_minimum_required(VERSION 3.10)
project(testing)

set(CMAKE_CXX_STANDARD 14)

add_executable(testing tmp_main.cpp HomophonicCipherMatrix.cpp DigramFreqMatrix.cpp utils.cpp RandomKeyInit.cpp)