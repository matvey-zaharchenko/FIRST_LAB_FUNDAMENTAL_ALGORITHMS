#include "funcs.h"

bool validNumber(char* number){
    if(*number == '-'){
        ++number;
    }
    while(number){
        if(*number == '\0'){
            break;
        }
        if('0' > *number || *number > '9'){
            return false;
        }
        ++number;
    }
    return true;
}

long long int exponintation(const int number, int exp){
    long long int result = 1;
    for(int i = 0; i < exp; ++i){
        result *= number;
    }
    return result;
}

int strToInt(char* number){
    int result = 0;
    int start = 0;
    if(number[0] == '-'){
        start = 1;
    }

    for(int i = start; i < strlen(number); ++i){
        result = result * 10 + (number[i] - '0');
    }

    if(start){
        return -result; 
    }
    return result;
}

int func_a(int* result, const int number){
    bool flag = true;
    int index = 0;
    for(int i = number; i <= 100; i += number){
        result[index] = i;
        ++index;
    }
    return index;

}

bool func_b(const int number){
    for(int i = 2; i < (int)sqrt(number) + 1; ++i){
        if(number % i == 0){
            return false;
        }
    }
    return true;
}

int func_c(char* result, const int number){
    int num = number;
    int index = 0;
    while(num != 0){
        if(num % 16 <= 9){
            result[index] = '0' + (num % 16);
        } else{
            result[index] = 'a' + ((num % 16) - 10);
        }
        num = num / 16;
        ++index;
    }
    if(index == 0){
        result[index] = '0';
        ++index;
    }
    return index;
}

void func_d(long long int* resultMatrix, const int number){
    for(int i = 0; i < number; ++i){
        for(int j = 0; j < 10; ++j){
            resultMatrix[10*i+j] = exponintation(j+1, i+1);
        }
    }
}

long long int func_e(const int number){
    long long int result = 0;
    for(int i = 1; i <= number; ++i){
        result += i;
    }
    return result;
}

long long int func_f(const int number){
    long long int result = 1;
    for(int i = 2; i <= number; ++i){
        result *= i;
    }
    return result;
}