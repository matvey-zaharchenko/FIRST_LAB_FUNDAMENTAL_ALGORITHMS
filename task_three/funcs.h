#ifndef FUNCS_HPP_
#define FUNCS_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

enum ERRORS{
    SUCCESS,
    INCORRECT_INPUT,
    INCORRECT_NUMBER_OF_ARGUMENTS, 
    INCORRECT_FLAG
};

int getThreeFloatNumbers(int argc, char* argv[], float* a, float* b, float* c);
int validatePositiveNumbers(float a, float b, float c, float epsilon);
int QuadraticFlag(int argc, char* argv[]);
int MultipleFlag(int argc, char* argv[]);
int TriangleFlag(int argc, char* argv[]);
int flagParsing(char* flag);
int flagParsing(char* flag);
bool validIntNumber(char* number);
bool validFloatNumber(char* number);
float strToFloat(char* number);
int strToInt(char* number);
int solutionsOfEquation(float a, float b, float c, float eps, float* result);
void printSolutions(float a, float b, float c, int count, float* sol);
void func_a(float a, float b, float c, float eps);
bool func_b(int a, int b);
bool func_c(float a, float b, float c, float eps);


#endif 