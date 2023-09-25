#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

int main(void) {

	int matriz[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matriz[i][j] = rand() % 99;
			printf("%d", matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}
