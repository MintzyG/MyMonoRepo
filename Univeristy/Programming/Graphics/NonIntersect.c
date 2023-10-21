#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// ProdVet
// VecRes = <A, B>
// A = (x, y, z)
// B = (a, b, c)
// VecRes(yc-zb, xc-za, xb-ya)

// ProdEsca
// Som i>n (XiAi)

// CosTheta = Esc(A,B)/|A|*|B|

#define RAND 200

typedef struct Ponto {
    float x, y;
    float ang, dir, dist;
} Ponto;

void ShowPoints(Ponto* ponto, int size){
    for (int i = 0; i < size; i++){
        printf("X:%7.2f\t", ponto[i].x);
        printf("Y:%7.2f\t", ponto[i].y);
        printf("A:%7.2f\t", ponto[i].ang);
        printf("DR:%7.2f\t", ponto[i].dir);
        printf("DS:%7.2f\n", ponto[i].dist);
    }
    printf("\n");
}

Ponto CreatePoint(Ponto ponto){
    int sign1 = 0, sign2 = 0;
    while(1){
        sign1 = rand() % 2;
        if (sign1 == 0) 
            sign1 = -1;
        sign2 = rand() % 2;
        if (sign2 == 0) 
            sign2 = -1;
        ponto.x = sign1 * (float)(((double)rand()/(double)(RAND_MAX)) * RAND); 
        ponto.y = sign2 * (float)(((double)rand()/(double)(RAND_MAX)) * RAND); 
        if (ponto.x == 0 && ponto.y == 0){
            continue;
        }
        break;
    }
    return ponto;
}

void CreatePoints(Ponto* ponto, int size){
    for (int i = 0; i < size; i++) ponto[i] = CreatePoint(ponto[i]);
}

void Init(Ponto* ponto){
    ponto->x = 1;
    ponto->y = 1;
    ponto->ang = 1;
    ponto->dir = 1;
}

void PrintPonto(Ponto ponto){
    printf("X: %f\tY: %f\tAng: %f\tDir: %f\n", 
            ponto.x,
            ponto.y,
            ponto.ang,
            ponto.dir);
}

void CalcularDirecao(Ponto* ponto, int size){
    for (int i = 1; i < size; i++) {
        float dir = ponto[0].x * ponto[i].y - ponto[0].y * ponto[i].x;
        if (dir != 0){
            dir = dir / fabs(dir);
            ponto[i].dir = dir;
        } else
            ponto[i].dir = 0;
    }
}

void CalcularAngulos(Ponto* ponto, int size){
    for (int i = 1; i < size; i++) {
        float produto_escalar = ponto[0].x * ponto[i].x + ponto[0].y * ponto[i].y;
        float distancia_um = sqrt(pow(ponto[0].x, 2) + pow(ponto[0].y, 2));
        float distancia_dois = sqrt(pow(ponto[i].x, 2) + pow(ponto[i].y, 2));
        float proj = produto_escalar / (distancia_um * distancia_dois);
        //printf("\n%f", proj);
        if (proj < -1) proj = 0;
        if (proj > 1) proj = 1;
        float cosseno_radianos = acos((proj));
        float ang = cosseno_radianos * 180.0 / M_PI;
        ponto[i].ang = ang;
        //printf("\nPonto (%f,%f): PE:%f D1:%f d2:%f PJ:%f CR:%f A:%f", ponto[i].x, ponto[i].y, produto_escalar, distancia_um, distancia_dois, proj, cosseno_radianos, ang);
    }
}

void ConsertaSimilar(Ponto* ponto, int size) {
    int fabs1, fabs2, fabr1, fabr2;
    fabr1 = fabs(ponto[0].x);
    fabr2 = fabs(ponto[0].y);
    for (int i = 1; i < size; i++){
        fabs1 = fabs(ponto[i].x);
        fabs2 = fabs(ponto[i].y);
        if (fabr1 == fabs1 && fabr2 == fabs2){
            if((ponto[0].x == ponto[i].x) && (ponto[0].y == ponto[i].y))
                printf("\nWas: ");
            PrintPonto(ponto[i]);
            if((ponto[0].x == ponto[i].x) && (ponto[0].y == ponto[i].y)){
                printf("Now: ");
                ponto[i] = CreatePoint(ponto[i]);
                PrintPonto(ponto[i]);
                printf("\n");
            }
        }
    }
}

void AdjustDirection(Ponto* ponto, int size) {
    for (int i = 0; i < size; i++)
        if (ponto[i].dir == -1){
            ponto[i].dir = 1;
            ponto[i].ang = 360 - ponto[i].ang;
        }
}

void SortByAngle(Ponto* ponto, int size) {
    Ponto tmp;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++){
            if (ponto[j].ang > ponto[j + 1].ang){
                tmp = ponto[j + 1];
                ponto[j + 1] = ponto[j];
                ponto[j] = tmp;
            }
        }
}

void CalcularDistancia(Ponto* ponto, int size){
    for (int i = 0; i < size; i++) {
        ponto[i].dist = sqrt(pow(ponto[i].x, 2) + pow(ponto[i].y, 2));
    }
}

int main() {
    srand(time(NULL));

    Ponto ponto;
    Init(&ponto);

    int size;

    printf("How many points: ");
    scanf("%d", &size);
    Ponto* vetor_pontos = (Ponto*)malloc(size * sizeof(Ponto));

    CreatePoints(vetor_pontos, size);
    printf("Your points: \n");
    ShowPoints(vetor_pontos, size);
    ConsertaSimilar(vetor_pontos, size);
    CalcularDistancia(vetor_pontos, size);
    CalcularAngulos(vetor_pontos, size);
    CalcularDirecao(vetor_pontos, size);
    AdjustDirection(vetor_pontos, size);
    SortByAngle(vetor_pontos, size);
    ShowPoints(vetor_pontos, size);
    return 0;
}
