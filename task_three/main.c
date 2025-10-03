#include "funcs.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error: No flag provided\n");
        printf("Valid flags: q m t\n");
        return INCORRECT_FLAG;
    }
    int flag = flagParsing(argv[1]);

    if (flag == 1) {
        return QuadraticFlag(argc, argv);
    } else if (flag == 2) {
        return MultipleFlag(argc, argv);
    } else if (flag == 3) {
        return TriangleFlag(argc, argv);
    } else {
        printf("Error. Flag must be: -flag or /flag\n");
        printf("Valid flags: q m t\n");
        return INCORRECT_FLAG;
    }
    return SUCCESS;
}   