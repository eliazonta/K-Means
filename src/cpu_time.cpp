#include <time.h>
#include <iostream>

int time(int argc, char** argv){
    clock_t start = clock();
    for(int i = 0; i < 100; ++i){
        std::cout<<i<<std::endl;
    }
    std::cout<<"time : "<<(double)(clock() - start)/CLOCKS_PER_SEC<<std::endl;
    return EXIT_SUCCESS;
}