#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Media(int numeros, float* valores) {
	float tmp;
	for (int i = 0; i < numeros; i++) {
		tmp += *(valores + i);
	}
	return tmp / numeros;
}

float Variancia(int numeros, float* valores, float media) {
	float tmp;

	for (int i = 0; i < numeros; i++) {
		tmp += (float)pow((double)(valores[i] - media), 2);
	}

	tmp = tmp / (numeros - 1);

	return (float)sqrt((double)tmp);
}

int main () {
	
	float* valores;
	int numeros;
	float media, variancia;

	while (1) {

		printf("Quantos valores: ");
		scanf("%d", &numeros);
		if (numeros <= 0 || numeros > 20) {
			printf("Valor invalido \n");
			continue;
		}

		valores = (float*)malloc(numeros * sizeof(float));

		for (int i = 0; i < numeros; i++) {
			scanf("%f", &valores[i]);
		}
		break;
	}
	
	media = Media(numeros, valores);
	variancia = Variancia(numeros, valores, media);

	printf("Media: %f \nVariancia: %f", media, variancia);

	return 0;
}
