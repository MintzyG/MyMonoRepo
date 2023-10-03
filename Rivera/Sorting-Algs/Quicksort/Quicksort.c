#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "VectorUtility.h"
#include <sys/ioctl.h>
#include <unistd.h>

void DrawGraph(int*, int, int, int);

void Swap(int* vector, int index_a, int index_b){
    *(vector+index_a) = *(vector+index_a) + *(vector+index_b) - (*(vector+index_b) = *(vector+index_a));
}

void QuickSort(int* vector, int first, int last, struct winsize w, int keys, int block_size) {
    
    if (last - first < 2)
        return;

    int pivot = vector[first];
    int pointer_b = last - 1 /*, pointer_a = start*/;
    int swap_marker = last;

    for (int i = pointer_b; i >= first; i--) {
        
        if (vector[i] >= pivot) {
            swap_marker--;
            
            if (i < swap_marker) {
                Swap(vector, i, swap_marker);
            }
        } 
    }
   
    DrawGraph(vector, keys, block_size, w.ws_row);
    ShowVector(vector, keys, w.ws_col, block_size);

    getchar();

    QuickSort(vector, first, swap_marker, w, keys, block_size);
    QuickSort(vector, swap_marker+1, last, w, keys, block_size);

}

void SetBlockSize(int* block_size, int cols, int keys) {
    *block_size = ((cols - (keys + 1)) / keys);
}

void DrawBlock(int block_size, int state) {

    if (state == 0)
        for (int i = 0; i < block_size; i++)
            printf("█");
    else
        for (int i = 0; i < block_size; i++)
            printf(" ");
    

}

void DrawGraph(int* vector, int keys, int block_size, int height) {
    for (int i = height; i > 0; i--){
        printf(" ");
        for (int j = 0; j < keys; j++){
            if (i < vector[j]) {
                DrawBlock(block_size, 0);
            } else {
                DrawBlock(block_size, 1);
            }
            printf(" ");
        }
        if (i > 1)
            printf("\n");
    }
}

int main(int argc, char** argv) {
    if (atoi(argv[1]) < 1 || atoi(argv[1]) > 30) {
        printf("Invalid Argument");   
        exit(1);
    }

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    printf("%d", w.ws_col);

    int keys = atoi(argv[1]);
    int block_size = 0;

    SetBlockSize(&block_size, w.ws_col, keys);

    srand(time(NULL));
    int size = atoi(argv[1]);
    int* vector = CreateVector(size);    
    PopulateVector(vector, size);
    ShowVector(vector, size, w.ws_col, block_size);
    QuickSort(vector, 0, size, w, keys, block_size);
    DrawGraph(vector, keys, block_size, w.ws_row);
    ShowVector(vector, size, w.ws_col, block_size);
    return 0;
}
