#include "funcs.h"

bool fillPrimeNumbers(int* primesNumbers, int lastPos){
    int k = 0;
    int countOfNum = lastPos * 20;
    int i_start = 0;
    int* array = NULL;
    while(k != lastPos){
        int* new_array = (int*)realloc(array, sizeof(int)*(countOfNum+1));
        if(!new_array){
            free(array);
            return false;
        }
        array = new_array;

        for(int i = 0; i <= countOfNum; ++i){
            array[i] = i;
        }
        for(int p = 2; p <= countOfNum; ++p){
            if(array[p] != 0){
                primesNumbers[k] = p;
                ++k;
                if(k == lastPos){
                    break;
                }
            
                for(long long j = (long long)p * p; j <= countOfNum; j += p){
                    if(j <= countOfNum){
                        array[(int)j] = 0;
                    }
                }
            }
        }
        if(k < lastPos){
            countOfNum *= 2;
        }
        
    }
    free(array);
    return true;
}