#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int* valores;
	valores = (int*)malloc(10 * sizeof(int));

	int tmp = 0, again = 0;

	srand(time(0));

	for (int i = 0; i < 10; i++) {
		valores[i] = rand() % 100;
		printf("%d ", valores[i]);
	}
	printf("\n");

	while (1) {
		again = 0;
		for (int i = 0; i < 9; i++) {
			if (valores[i] < valores[i + 1]) {
				tmp = valores[i];
				valores[i] = valores[i + 1];
				valores[i + 1] = tmp;
				again += 1;
			}
		}

		for (int i = 0; i < 10; i++) {
			printf("%d ", valores[i]);
		}

		printf("\n");

		if (again) {
			continue;
		}

		break;
	}
	return 0;
}
