#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "VectorUtility.h"

void Swap(int* vector, int index_a, int index_b){
    *(vector+index_a) = *(vector+index_a) + *(vector+index_b) - (*(vector+index_b) = *(vector+index_a));
}

void QuickSort(int* vector, int first, int last) {
    
    if (last - first < 2)
        return;

    int pivot = vector[first];
    int pointer_a = first, pointer_b = last - 1;
    int tmp = 0, swap_marker = last;

    for (int i = pointer_b; i >= first; i--) {
        
        if (vector[i] >= pivot) {
            swap_marker--;
            
            if (i < swap_marker) {
                Swap(vector, i, swap_marker);
            }
        } 
    }

    QuickSort(vector, first, swap_marker);
    QuickSort(vector, swap_marker+1, last);

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
    QuickSort(vector, 0, size);
    ShowVector(vector, size);
    return 0;
}
