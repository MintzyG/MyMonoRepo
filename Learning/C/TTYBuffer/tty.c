#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <wchar.h>
#include <stdlib.h>
#include <time.h>

#define height 56
#define width 211

typedef struct Circle{
    int posX, posY;
    int radius;
} Circle;

int main() {

    // Prepare screen
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int console_fd = open("/dev/tty", O_WRONLY);
    if (console_fd == -1) {
        perror("Error opening console");
        return 1;
    }
    char* screen = (char*)malloc(((height * width) + 1) * sizeof(char));
    size_t message_length = height*width;

    //Make circles
    srand(time(NULL));
    Circle c[2];
    for (int i = 0; i < 2; i++){
        c[i].radius = rand() % 10;
        c[i].posX = rand() % width;
        c[i].posY = rand() % height;
    }

    while(1) {

        // Handle Logic

        // Write to the buffer
        for (int i = 0; i < height*width + 1; i++) {
            screen[i] = 'a';
        } screen[height*width] = '\0';

        // Write to the screen
        size_t bytes_written = write(console_fd, screen, message_length);
        if (bytes_written == -1) {
            perror("Error writing to console");
            return 1;
        }

    }


    // Close console interface
    close(console_fd);
    return 0;
}

