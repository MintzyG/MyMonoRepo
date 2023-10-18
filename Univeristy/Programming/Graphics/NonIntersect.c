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

typedef struct Ponto {
    float x, y;
    float ang, dir;
} Ponto;

void ShowPoints(Ponto* ponto, int size){
    for (int i = 0; i < size; i++){
        printf("%7.2f\t", ponto[i].x);
        printf("%7.2f\t", ponto[i].y);
        printf("%7.2f\t", ponto[i].ang);
        printf("%7.2f\n", ponto[i].dir);
    }
}

void CreatePoints(Ponto* ponto, int size){
    int sign1, sign2;
    for (int i = 0; i < size; i++){ 
        sign1 = rand() % 2;
        if (sign1 == 0) sign1 = -1;
        sign2 = rand() % 2;
        if (sign2 == 0) sign2 = -1;
        ponto[i].x = sign1 * rand() % 200; 
        ponto[i].y = sign2 * rand() % 200; 
    }
}

void Init(Ponto* ponto){
    ponto->x = 1;
    ponto->y = 1;
    ponto->ang = 1;
    ponto->dir = 1;
}

/*
void PrintPonto(Ponto ponto){
    printf("X: %f\nY: %f\nAng: %f\nDir: %f", 
            ponto.x,
            ponto.y,
            ponto.ang,
            ponto.dir);
}
*/

int main() {
    srand(time(NULL));

    Ponto ponto;
    Init(&ponto);
    //PrintPonto(ponto);

    int size;

    printf("How many points: ");
    scanf("%d", &size);
    Ponto* vetor_pontos = (Ponto*)malloc(size * sizeof(Ponto));

    CreatePoints(vetor_pontos, size);
    printf("Your points: \n");
    ShowPoints(vetor_pontos, size);
    
    return 0;
}
