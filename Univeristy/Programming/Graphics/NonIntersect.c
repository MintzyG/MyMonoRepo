#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ProdVet
// VecRes = <A, B>
// A = (x, y, z)
// B = (a, b, c)
// VecRes(yc-zb, xc-za, xb-ya)

// ProdEsca
// Som i>n (XiAi)

// CosTheta = Esc(A,B)/|A|*|B|

void ShowPoints(float** mat, int size, int ponto_size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < ponto_size -1; j++) printf("%7.2f\t", mat[i][j]);
        printf("\n");
    }
}

void ShowVectors(float** mat, int size, int ponto_size){
    for (int i = 0; i < size; i++){
        printf("(%f,%f)", mat[i][0], mat[i][1]);
        printf("\n");
    }
}

void CreatePoints(float** mat, int size){
    int sign1, sign2;
    for (int i = 0; i < size; i++){ 
        sign1 = rand() % 2;
        if (sign1 == 0) sign1 = -1;
        sign2 = rand() % 2;
        if (sign2 == 0) sign2 = -1;
        mat[i][0] = sign1 * rand() % 200; 
        mat[i][1] = sign2 * rand() % 200; 
    }
}

float** ConnectPoints(float** mat, int size, float ponto_size){

    float** result_vectors = (float**)malloc(size * sizeof(float*));
    for (int i = 0; i < size; i++) result_vectors[i] = (float*)malloc(ponto_size * sizeof(float));

    for(int i = 0; i < size; i++){
        result_vectors[i][0] = mat[(i + 1) % size][0] - mat[i][0];
        result_vectors[i][1] = mat[(i + 1) % size][1] - mat[i][1];
    }
    return result_vectors;
}

// Calcula a direção entre o vetor dado e o vetor (0,1)
float DirecaoVetor(float* vetor){
    return vetor[0] * 1;
}
    
int main() {
    srand(time(NULL));

    int size, ponto_size = 3;

    printf("How many points: ");
    scanf("%d", &size);
    float** matriz_pontos = (float**)malloc(size * sizeof(float*));
    for (int i = 0; i < size; i++) matriz_pontos[i] = (float*)malloc(ponto_size * sizeof(float)); 

    CreatePoints(matriz_pontos, size);
    printf("Your points: \n");
    ShowPoints(matriz_pontos, size, ponto_size);
    
    float** vetores = ConnectPoints(matriz_pontos, size, ponto_size);

    printf("\nResulting vectors from connection: \n");
    ShowVectors(vetores, size, ponto_size);

    for (int i = 0; i < size; i++)
        printf("Direção do vetor %d: %f\n", i+1, DirecaoVetor(matriz_pontos[i]));

    return 0;
}
