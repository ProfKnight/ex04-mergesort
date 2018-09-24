#include <iostream>
#include "mergesort.h"

int main(int argc, char *argv[]) {
    int array[] = {9, 10, 8, 1, 7, 2, 6, 3, 5, 4};
    edu::vcccd::vc::csv15::mergesort(array, 10);
    for(int i: array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}