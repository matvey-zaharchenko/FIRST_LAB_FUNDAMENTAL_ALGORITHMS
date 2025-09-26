#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>


enum Errors{
    WRONG_INPUT,
    WRONG_NUMBER,
    MALLOC_FAULT
};

int main(){
    int T, number, maxnumber = -100000;
    
    printf("Input count of request: ");
    scanf("%d", &T);
    
    if(T <= 0){
        printf("Error: count of request must be natural\n");
        return WRONG_INPUT;
    }

    printf("Input %d numbers: \n", T);

    int numbers[T];
    int res = 0;
    for(int i = 0; i < T; ++i){
        scanf("%d", &numbers[i]);
        if(numbers[i] > maxnumber){
            maxnumber = numbers[i];
        }
        if(numbers[i] <= 0){
            printf("Error: number must be natural\n");
            return WRONG_NUMBER;
        }

    }

    int* primes = (int*)malloc(sizeof(int)*maxnumber);
    int flag = fillPrimeNumbers(primes, maxnumber);
    if(!flag){
        printf("Memory allocation error\n");
        return MALLOC_FAULT;
    }
    for(int i = 0; i < T; ++i){
        printf("Prime number on %d position: %d\n", numbers[i], primes[numbers[i]-1]);
    }
    free(primes);
    return 0;
}