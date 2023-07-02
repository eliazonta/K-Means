cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(K-Means)

set(CMAKE_CXX_STANDARD 17)

if(APPLE)
        set(CMAKE_C_COMPILER "/usr/local/opt/llvm/bin/clang")
        set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")
endif()


option(USE_OPENMP "Use OpenMP" ON)

add_executable(K-Means src/main.cpp src/k-means.cpp
        src/Point.cpp src/readWrite.cpp )
        
if(USE_OPENMP)
        find_package(OpenMP REQUIRED)
        if(OpenMP_CXX_FOUND)
                # set(OpenMP_CXX_FLAGS "-fopenmp")
                # set(OpenMP_C_FLAGS "-fopenmp")
                # set(OpenMP_EXE_LINKER_FLAGS "-fopenmp")
                target_link_libraries(K-Means PUBLIC OpenMP::OpenMP_CXX)

        endif()
endif()

        

