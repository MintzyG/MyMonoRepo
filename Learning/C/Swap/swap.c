#include <stdio.h>
#include <time.h>

void SwapXor(int* a, int* b) {
    if (a != b) {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

void SwapTmp(int* a, int* b) {
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void SwapOne(int* a, int* b) {
    *a = *a + *b - (*b = *a);
}

void SwapMlt(int* a, int* b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

int main() { 
    int a = 2, b = 7;
    clock_t Clock;
    

    //printf("Before Swap: A -> %d, B -> %d\n", a, b);

    Clock = clock();

    for (int i = 0; i < 1000000; i++){
    #ifdef XOR
        SwapXor(&a, &b);
    #endif
    #ifdef TMP
        SwapTmp(&a, &b);
    #endif
    #ifdef ONE
        SwapOne(&a, &b);
    #endif   
    #ifdef MLT
        SwapMlt(&a, &b);
    #endif
    }

    Clock = clock() - Clock;

    //printf("After Swap: A -> %d, B -> %d\n", a, b);
    //printf("Time taken to swap: %f", ((double)Clock/CLOCKS_PER_SEC));
    printf("%d", (int)(((double)Clock/CLOCKS_PER_SEC)*1000000));
    return 0;

}
