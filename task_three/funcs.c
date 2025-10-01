#include "funcs.h"

int getThreeFloatNumbers(int argc, char* argv[], float* a, float* b, float* c) {
    if (argc < 6) {
        printf("Error: Incorrect number of arguments\n");
        printf("Usage: %s %s epsilon <num1> <num2> <num3>\n", argv[0], argv[1]);
        return INCORRECT_NUMBER_OF_ARGUMENTS;
    }
    
    if (!(validFloatNumber(argv[3]) && 
        validFloatNumber(argv[4]) && 
        validFloatNumber(argv[5]))) {
            printf("Error: Incorrect input, numbers must be float\n");
            return INCORRECT_INPUT;
    }
    
    *a = strToFloat(argv[3]);
    *b = strToFloat(argv[4]);
    *c = strToFloat(argv[5]);
    
    return SUCCESS;
}

int validatePositiveNumbers(float a, float b, float c, float epsilon) {
    if (a < 0 || b < 0 || c < 0 ||
        fabs(a) < epsilon || fabs(b) < epsilon || fabs(c) < epsilon) {
        printf("Error: numbers can't be negative or zeros\n");
        return INCORRECT_INPUT;
    }
    return SUCCESS;
}


int QuadraticFlag(int argc, char* argv[]) {
    float epsilon, a, b, c;
    
    int result = getThreeFloatNumbers(argc, argv, &a, &b, &c);
    if (result != 0) {
        return result;
    }
    epsilon = strToFloat(argv[2]);
    func_a(a, b, c, epsilon);
    
    return SUCCESS;
}

int MultipleFlag(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Error: Incorrect number of arguments\n");
        printf("Usage: %s %s <num1> <num2>\n", argv[0], argv[1]);
        return INCORRECT_NUMBER_OF_ARGUMENTS;
    }

    if (!(validIntNumber(argv[2]) && validIntNumber(argv[3]))) {
        printf("Error: numbers must be integer\n");
        return INCORRECT_INPUT;
    }

    int num1 = strToInt(argv[2]);
    int num2 = strToInt(argv[3]);

    if (num1 == 0 || num2 == 0) {
        printf("Error: numbers must be not a zero\n");
        return INCORRECT_INPUT;
    }

    if (func_b(num1, num2)) {
        printf("The first number (%d) is multiple of the second (%d)\n", num1, num2);
    } else {
        printf("The first number (%d) isn't multiple of the second (%d)\n", num1, num2);
    }
    
    return SUCCESS;
}

int TriangleFlag(int argc, char* argv[]) {
    float epsilon, a, b, c;
    
    int result = getThreeFloatNumbers(argc, argv, &a, &b, &c);
    if (result != 0) {
        return result;
    }

    epsilon = strToFloat(argv[2]);
    
    result = validatePositiveNumbers(a, b, c, epsilon);
    if (result != 0) {
        return result;
    }

    if (func_c(a, b, c, epsilon)) {
        printf("Numbers can be lengths of a right triangle\n");
    } else {
        printf("Numbers can't be lengths of a right triangle\n");
    }
    
    return SUCCESS;
}

int flagParsing(char* flag){
    if(strcmp(flag, "-q") == 0 || strcmp(flag, "/q") == 0){
        return 1;
    } else if(strcmp(flag, "-m") == 0 || strcmp(flag, "/m") == 0){
        return 2;
    } else if(strcmp(flag, "-t") == 0 || strcmp(flag, "/t") == 0){
        return 3;
    } else{
        return -1;
    }
}

bool validFloatNumber(char* number){
    int dotCount = 0;
    if(*number == '-'){
        ++number;
    }
    while(*number != '\0'){
        if(*number == '\0'){
            break;
        }
        if('0' > *number || *number > '9'){
            if(*number == '.'){
                ++dotCount;

                if(dotCount > 1){
                    return false;
                }
            }else if(*number != '.'){
                return false;
            }
        }
        ++number;
    }
    return true;
}

bool validIntNumber(char* number){
    if(*number == '-'){
        ++number;
    }
    while(*number != '\0'){
        if('0' > *number || *number > '9'){
            return false;
        }
        ++number;
    }
    return true;
}

float strToFloat(char* number){
    float result = 0;
    float fraction = 0.0f;
    float divisor = 10.0f;
    bool negative = false;
    bool dotFlag = false;

    if(*number == '-'){
        negative = true;
        ++number;
    }

    while(*number != '\0'){
        if(*number >= '0' && *number <= '9'){
            if(!dotFlag){
                result = result * 10 + (*number - '0'); 
            } else{
                fraction += (*number - '0') / divisor;
                divisor *= 10.0f;
            }
        } else if(*number == '.'){
            dotFlag = true;
        }
        ++number;
    }

    result += fraction;
    
    if(negative){
        result = -result;
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

int solutionsOfEquation(float a, float b, float c, float eps, float* result){
    result[0] = 0;
    result[1] = 0;
    if(!(fabs(a) < eps) && !(fabs(b) < eps) && !(fabs(c) < eps)){
        float D = powf(b, 2) - 4 * a * c;
        if(D < 0){
            return 0; // no one
        }

        if(fabs(D) < eps){
            result[0] = (-b / (2 * a));
            return 1;
        }

        result[0] = ((-b - sqrt(D)) / (2*a));
        result[1] = ((-b + sqrt(D)) / (2*a));
        return 2;
    } else if(!(fabs(a) < eps) && !(fabs(b) < eps) && (fabs(c) < eps)){
        result[0] = 0;
        result[1] = (-b / a);
        return 2;
    } else if(!(fabs(a) < eps) && (fabs(b) < eps) && !(fabs(c) < eps)){
        float res = -c / a;
        if(res < 0){
            return 0; // no one
        }
        result[0] = -sqrt(res);
        result[1] = sqrt(res);
        return 2;
    } else if(!(fabs(a) < eps) && (fabs(b) < eps) && (fabs(c) < eps)){
        result[0] = 0;
        return 1; 
    } else if((fabs(a) < eps) && !(fabs(b) < eps) && !(fabs(c) < eps)){
        result[0] = (-c / b);
        return 1;
    } else if((fabs(a) < eps) && !(fabs(b) < eps) && (fabs(c) < eps)){
        result[0] = 0;
        return 1; 
    } else if((fabs(a) < eps) && (fabs(b) < eps) && !(fabs(c) < eps)){
        return 0; // no one
    } else if((fabs(a) < eps) && (fabs(b) < eps) && (fabs(c) < eps)){
        return -1; // inf
    }
}

void printSolutions(float a, float b, float c, int count, float* sol){
    if(count == 2){
        printf("Solutions for [%f]x^2 + [%f]x + [%f] = 0:\n", a, b, c);
        printf("x1=%f; x2=%f\n", sol[0], sol[1]);
    } else if(count == 1){
        printf("Solutions for [%f]x^2 + [%f]x + [%f] = 0:\n", a, b, c);
        printf("x1=%f\n", sol[0]);
    } else if(count == 0){
        printf("Quantity: [%f]x^2 + [%f]x + [%f] = 0 don't have any solutions\n", a, b, c);
    } else if(count == -1){
        printf("Quantity: [%f]x^2 + [%f]x + [%f] = 0 have infinity solutions\n", a, b, c);
    }
}

void func_a(float a, float b, float c, float eps){
    float solutions[2];
    int res;
    if(fabs(a - b) > eps && fabs(a - c) > eps && fabs(b - c) > eps){
        res = solutionsOfEquation(a, b, c, eps, solutions);
        printSolutions(a, b, c, res, solutions);

        res = solutionsOfEquation(a, c, b, eps, solutions);
        printSolutions(a, c, b, res, solutions);

        res = solutionsOfEquation(b, a, c, eps, solutions);
        printSolutions(b, a, c, res, solutions);
        
        res = solutionsOfEquation(b, c, a, eps, solutions);
        printSolutions(b, c, a, res, solutions);

        res = solutionsOfEquation(c, a, b, eps, solutions);
        printSolutions(c, a, b, res, solutions);
        
        res = solutionsOfEquation(c, b, a, eps, solutions);
        printSolutions(c, b, a, res, solutions);
    } else if ( (fabs(a - b) < eps && fabs(c - a) > eps) ||
                (fabs(a - c) < eps && fabs(b - a) > eps) || 
                (fabs(b - c) < eps && fabs(a - b) > eps)){
        res = solutionsOfEquation(a, b, c, eps, solutions);
        printSolutions(a, b, c, res, solutions);

        res = solutionsOfEquation(a, c, b, eps, solutions);
        printSolutions(a, c, b, res, solutions);

        res = solutionsOfEquation(c, a, b, eps, solutions);
        printSolutions(c, a, b, res, solutions);
    } else if(fabs(a - c) < eps && fabs(b - a) < eps){
        res = solutionsOfEquation(a, b, c, eps, solutions);
        printSolutions(a, b, c, res, solutions);
    }
}

bool func_b(int a, int b){
    if(a % b == 0){
        return true;
    }
    return false;
}

bool func_c(float a, float b, float c, float eps){
    float sum1 = powf(a, 2) + powf(b, 2);
    float sum2 = powf(a, 2) + powf(c, 2);
    float sum3 = powf(b, 2) + powf(c, 2);

    if (fabs(sum1 - powf(c, 2)) < eps ||
        fabs(sum2 - powf(b, 2)) < eps ||
        fabs(sum3 - powf(a, 2)) < eps){
            return true;
    }
    return false;
}