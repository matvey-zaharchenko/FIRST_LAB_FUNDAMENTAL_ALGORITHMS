#include "funcs.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error: No flag provided\n");
        printf("Valid flags: q m t\n");
        return INCORRECT_FLAG;
    }

    if (strcmp(argv[1], "-q") == 0 || strcmp(argv[1], "/q") == 0) {
        return QuadraticFlag(argc, argv);
    } else if (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "/m") == 0) {
        return MultipleFlag(argc, argv);
    } else if (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "/t") == 0) {
        return TriangleFlag(argc, argv);
    } else {
        printf("Error. Flag must be: -flag or /flag\n");
        printf("Valid flags: q m t\n");
        return INCORRECT_FLAG;
    }
    return SUCCESS;
}   