cmake_minimum_required(VERSION 3.22)
project(K-Means)

set(CMAKE_CXX_STANDARD 17)

add_executable(K-Means src/main.cpp src/k-means.cpp
        src/Point.cpp src/readWrite.cpp )
