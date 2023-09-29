#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "VectorUtility.h"

int main(int argc, char** argv) {
    if (atoi(argv[1]) < 1 || atoi(argv[1]) > 30) {
        printf("Invalid Argument");   
        exit(1);
    }

    srand(time(NULL));
    int Size = atoi(argv[1]);
    int* Vector = CreateVector(Size);    
    PopulateVector(Vector, Size);
    ShowVector(Vector, Size);
    return 0;
}
