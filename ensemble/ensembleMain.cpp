#include <iostream>
#include "ensemble.h"

int main() {
    Ensemble test;
    int arr1[3] = {1,2,3};
    Ensemble test1(arr1,3);
    int arr2[6] = {1,3,2,3,3};
    Ensemble test2(arr2,5);
    unsigned int max = test.cardMax;
    unsigned int act = test.cardAct;
    printf("max: %d, act: %d\n", max, act);
    max = test1.cardMax;
    act = test1.cardAct;
    printf("max: %d, act: %d\n", max, act);
    max = test2.cardMax;
    act = test2.cardAct;
    printf("max: %d, act: %d\n", max, act);
    int isit = 0;
    if(test1.EstEgal(test2)) {
        isit = 1;
    }
    for(int i=0; i < 5; i++) {
        std::cout << test2.bag[i] << "\n";
    }
    printf("bool: %d,\n", isit);
}