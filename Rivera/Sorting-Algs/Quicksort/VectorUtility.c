#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG

void PopulateVectorDebug(int* Vector, int Size, int Line) {
    int Amount = 0;
    for (int i = 0; i < Size; i++) {
        Vector[i] = rand() % 56;  
        Amount++;
    }  
    printf("\nDEBUG -- PopulateVector | [INSERTED %d VALUES AT LINE %d] -- DEBUG\n", Amount, Line);
}

int* CreateVectorDebug(int Size, int Line) {
    int* Vector;
    Vector = (int*)malloc(Size * sizeof(int));
    printf("\nDEBUG -- [VECTOR ALLOCATED AT LINE %d] -- DEBUG\n", Line);
    return Vector;
}

#endif

void ShowVector(int* Vector, int Size, int width, int block_size) {
    printf("\n");

    printf(" %*s", (block_size + 1)/2, " ");
    for (int i = 0; i < Size; i++) {
        printf("%d%*s", Vector[i], block_size-1, " ");
    }
}

void PopulateVector(int* Vector, int Size) {
    for (int i = 0; i < Size; i++)
        Vector[i] = rand() % 56;  
}

int* CreateVector(int Size) {
    int* Vector;
    Vector = (int*)malloc(Size * sizeof(int));
    return Vector;
}

#ifdef DEBUG
    #define PopulateVector(A, B) PopulateVectorDebug(A, B, __LINE__)
    #define CreateVector(A) CreateVectorDebug(A, __LINE__)
#endif

