#include "funcs.h"
#include <stdio.h>

enum Errors{
    INCORRECT_NUMBER_OF_ARGUMENTS,
    INCORRECT_FLAG,
    MALLOC_ERROR,
    NEGATIVE_NUMBER_ERROR,
    WRONG_NUMBER,
    DIVISION_BY_ZERO
};

int main(int argc, char* argv[]){
    if(argc < 3){
        printf("Error: Incorrect input\n");
        printf("Usage: %s <number> <flag>\n", argv[0]);
        return INCORRECT_NUMBER_OF_ARGUMENTS;
    }

    if(!validNumber(argv[1])){
        printf("Error: the number must be integer\n");
        return WRONG_NUMBER;
    }

    int number = strToInt(argv[1]);
    
    if(strcmp(argv[2], "-h") == 0 || strcmp(argv[2], "/h") == 0){
        if(number == 0){
            printf("Error: devision by zero\n");
            return DIVISION_BY_ZERO;
        } 
        if(number < 0){
            printf("Error: the number must be natural\n");
            return NEGATIVE_NUMBER_ERROR;
        }

        int* array = (int*)malloc(100 * sizeof(int));
        if(!array){
            printf("Memory allocation error");
            return MALLOC_ERROR;
        }

        int array_size = func_a(array, number);

        if(array_size){
            for(int i = 0; i < array_size; ++i){
                printf("%d ", array[i]);
            }
        } else{
            printf("No such numbers");
        }
        printf("\n");
        free(array);
    } else if(strcmp(argv[2], "-p") == 0 || strcmp(argv[2], "/p") == 0){
        if(number <= 1){
            printf("The number isn't composite and isn't prime\n");
        } else{
            if(func_b(number)){
                printf("The number is prime\n");
            }else{
                printf("The number is composite\n");
            }
        }
    } else if(strcmp(argv[2], "-s") == 0 || strcmp(argv[2], "/s") == 0){
        if(number < 0){
            printf("Error: number must be positive\n");
            return NEGATIVE_NUMBER_ERROR;
        }
        char* hexNumber = (char*)malloc(sizeof(char)*9);
        if(!hexNumber){
            printf("Memory allocation error\n");
            return MALLOC_ERROR;
        }
        int hexNumSize = func_c(hexNumber, number);
        for(int i = hexNumSize - 1; i >= 0; --i){
            printf("%c ", hexNumber[i]);
        }
        printf("\n");
        free(hexNumber);
    } else if(strcmp(argv[2], "-e") == 0 || strcmp(argv[2], "/e") == 0){
        if(number < 1 || number > 10){
            printf("Error: number must be 1 to 10\n");
            return WRONG_NUMBER;
        }

        long long int* matrix = (long long int*)malloc(sizeof(long long int) * 10 * number);
        func_d(matrix, number);

        for(int i = 0; i < number; ++i){
            for(int j = 0; j < 10; ++j){
                printf("%12lld", matrix[10*i+j]);
            }
            printf("\n");
        }
        free(matrix);
    } else if(strcmp(argv[2], "-a") == 0 || strcmp(argv[2], "/a") == 0){
        if(number <= 0){
            printf("Error: the number must be natural\n");
            return WRONG_NUMBER;
        }
        printf("Sum 1 to %d = %lld\n", number, func_e(number));
    } else if(strcmp(argv[2], "-f") == 0 || strcmp(argv[2], "/f") == 0){
        if(number < 0){
            printf("Error: number must be positive\n");
            return NEGATIVE_NUMBER_ERROR;
        }
        printf("Factorial %d = %lld\n", number, func_f(number));
    } else{
        printf("Flag must be: -flag or /flag\n");
        printf("Valid flags: h p s e a f\n");
        return INCORRECT_FLAG;
    }

    return 0;
}