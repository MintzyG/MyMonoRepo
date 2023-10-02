#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "VectorUtility.h"

void Swap(int* vector, int index_a, int index_b, int size){

    int tmp = 0; 

    if (index_a < 0 || index_b < 0 || index_a > size || index_b > size) {
        printf("Tried accessing invalid memory index: \nindex_a -> %d  \nindex_b -> %d", index_a, index_b);
        exit(1);
    }

    tmp = vector[index_a];
    vector[index_a] = vector[index_b];
    vector[index_b] = tmp;

}

void QuickSort(int* vector, int first, int last) {
    int pivot = vector[first];
    int pointer_a = first + 1, pointer_b = last;
    int tmp = 0, changed = 0;

    if (last <= first) {
        return 0;
    }

    while (pointer_a != pointer_b) { 
        if (vector[pointer_a] )
                

    }
    
    QuickSort(vector, first, pointer_a);
    QuickSort(vector, pointer_a, last);

}

int main(int argc, char** argv) {
    if (atoi(argv[1]) < 1 || atoi(argv[1]) > 30) {
        printf("Invalid Argument");   
        exit(1);
    }

    srand(time(NULL));
    int size = atoi(argv[1]);
    int* vector = CreateVector(size);    
    PopulateVector(vector, size);
    ShowVector(vector, size);
    QuickSort(vector, 0, size - 1);
    ShowVector(vector, size);
    return 0;
}
