#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

void SetBlockSize(int* block_size, int cols, int keys) {
    *block_size = (cols / keys) - 1;
}

void DrawLine(int keys, int block_size) { 
    for (int j = 0; j < keys; j++) {
        printf(" "); 
        for (int i = 0; i < block_size; i++)
            printf("█");
    }
    printf("\n");
}

int main (int argc, char **argv)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
   
    int counter = 0;
    int keys = 1;
    int block_size = 0;
    SetBlockSize(&block_size, w.ws_col, keys);
    long int time_step_usec = 200;
    //long int time_step_sec = 1;
    
    //time_t last_sec;
    struct timeval tval_before, tval_after, tval_result, tval_acc, tval_running, tval_last, tval_tmp;
    gettimeofday(&tval_before, NULL);
    tval_last = tval_before;

    
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);
    printf("Time before loop %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

    while(counter < 100){
        
        DrawLine(keys, block_size);
        counter++;
        keys++;
        SetBlockSize(&block_size, w.ws_col, keys);
        sleep(1);

    }

    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);
    printf("Running for %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

    return 0;  // make sure your main returns int
}
