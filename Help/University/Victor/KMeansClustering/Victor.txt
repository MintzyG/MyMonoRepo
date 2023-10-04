#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MatrizAleatoria(int matriz[10][10]) {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
}

void mostrarMat(int matriz[10][10]) {
    printf("\nMatriz:\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf(" %02d", matriz[i][j]);
        }
        printf("\n");
    }
}

void geraMatrizIndice(int c, int vetorAleatorio[10], int matrizEntrada[10][10], int matrizIndice[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int diferencaMinima = 300;
            int Melhorindice = 0;
            for (int indiceVetor = 0; indiceVetor < c; indiceVetor++) {
                int diferenca = abs(matrizEntrada[i][j] - vetorAleatorio[indiceVetor]);
                if (diferenca < diferencaMinima) {
                    diferencaMinima = diferenca;
                    Melhorindice = indiceVetor;
                }
            }
            matrizIndice[i][j] = Melhorindice;
        }
    }
}

void geraMatrizSaida(int c, int vetorAleatorio[10], int matrizIndice[10][10], int matrizSaida[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int indiceCor = matrizIndice[i][j];
            matrizSaida[i][j] = vetorAleatorio[indiceCor];
        }
    }
}

void mostrarVetor(int tamanho, int vetor[10]) {
    printf("\nVetor Aleatório:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(void) {
    int matrizEntrada[10][10], matrizSaida[10][10], vetorAleatorio[10], c, matrizIndice[10][10];

    MatrizAleatoria(matrizEntrada);
    mostrarMat(matrizEntrada);

    printf("\nDigite a quantidade de cores desejada: ");
    scanf("%d", &c);

    // Preencha vetorAleatorio com valores aleatórios entre 0 e 99, se necessário.
    for (int i = 0; i < c; i++) {
        vetorAleatorio[i] = rand() % 100;
    }

    mostrarVetor(c, vetorAleatorio);

    geraMatrizIndice(c, vetorAleatorio, matrizEntrada, matrizIndice);

    printf("\nMatriz de Índices:\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf(" %02d", matrizIndice[i][j]);
        }
        printf("\n");
    }

    geraMatrizSaida(c, vetorAleatorio, matrizIndice, matrizSaida);

    printf("\nMatriz de Saída:\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf(" %02d", matrizSaida[i][j]);
        }
        printf("\n");
    }

    return 0;
}
