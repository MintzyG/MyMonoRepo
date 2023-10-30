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
    int is_vector;
    float s_x, s_y, e_x, e_y;
} Ponto;

void ShowPoints(Ponto* ponto, int size){
    for (int i = 0; i < size; i++){
        printf("%d = (%7.2f, ", i, ponto[i].x);
        printf("%7.2f)\t", ponto[i].y);
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

Ponto* ConectarPontos(Ponto* ponto, int size) {
    Ponto* vetores = (Ponto*)malloc(size * sizeof(Ponto));
    for (int i = 1; i <= size; i++) {
	vetores[i-1].x = ponto[i%size].x - ponto[i-1].x; 
	vetores[i-1].y = ponto[i%size].y - ponto[i-1].y; 
    	vetores[i-1].s_x = ponto[i-1].x;
    	vetores[i-1].s_y = ponto[i-1].y;
    	vetores[i-1].e_x = ponto[i%size].x;
    	vetores[i-1].e_y = ponto[i%size].y;
	vetores[i-1].is_vector = 1;
    }
    return vetores;
}

int VerificarInterseccao(Ponto ponto_a, Ponto ponto_b, float *i_x, float *i_y){
    
    if (ponto_a.is_vector != 1 || ponto_b.is_vector != 1){
	return -1;
    }

    float v1_x, v1_y, v2_x, v2_y;
    v1_x = ponto_a.e_x - ponto_a.s_x;	v1_y = ponto_a.e_y - ponto_a.s_y;
    v2_x = ponto_b.e_x - ponto_b.s_x;	v2_y = ponto_b.e_y - ponto_b.s_y;

    float s, t;
    s = (-v1_y * (ponto_a.s_x - ponto_b.s_x) + v1_x * (ponto_a.s_y - ponto_b.s_y)) / (-v2_x * v1_y + v1_x * v2_y);
    t = (v2_x * (ponto_a.s_y - ponto_b.s_y) - v2_y * (ponto_a.s_x - ponto_b.s_x)) / (-v2_x * v1_y + v1_x * v2_y);

    float r_x, r_y;
    if (s >= 0 && s <= 1 && t >= 0 && t <= 1){
        r_x = ponto_a.s_x + (t * v1_x);
        r_y = ponto_a.s_y + (t * v1_y);
	*i_x = r_x;
	*i_y = r_y;

        if (r_x != ponto_a.e_x && r_y != ponto_a.e_x && r_x != ponto_b.s_x && r_y != ponto_b.s_y){
            return 1;  
        }
    }
    return 0;
}

void VerificarColisao(Ponto* vetores, int size){

    int colisao, CNC = 0, CC = 0;
    float p_x, p_y;

    for (int i = 0; i < size; i++)
	for (int j = i; j < size; j++){
	    if (i != j && (i != 0 && j != size) && (j != i + 1))
		colisao = VerificarInterseccao(vetores[i], vetores[j], &p_x, &p_y);
	    if (colisao == 1){
		printf("Os vetores %d e %d tiveram intersecao em %f e %f\n", i, j, p_x, p_y);
	    	CC += 1;
	    }else
		CNC += 1;
	    colisao = 0;
	}
    printf("\n%d pares de vetores colidiram, %d pares de vetores nao colidiram\n\n", CC, CNC);

}

int main() {
    srand(time(NULL));

    Ponto ponto;
    Init(&ponto);

    int size;

    printf("How many points: ");
    scanf("%d", &size);
    Ponto* vetor_pontos = (Ponto*)malloc(size * sizeof(Ponto));
    Ponto* vetores = (Ponto*)malloc(size * sizeof(Ponto));

    // Gera os pontos iniciais
    CreatePoints(vetor_pontos, size);
    printf("Your points: \n");
    ShowPoints(vetor_pontos, size);

    // Remove duplicatas e múltiplos
    // Realiza cálculos e padroniza os vetores
    ConsertaSimilar(vetor_pontos, size);
    CalcularDistancia(vetor_pontos, size);
    CalcularAngulos(vetor_pontos, size);
    CalcularDirecao(vetor_pontos, size);
    AdjustDirection(vetor_pontos, size);
   
    // Cria os vetores a partir dos postos desorganizados
    vetores = ConectarPontos(vetor_pontos, size);
    printf("Vetores:\n");
    ShowPoints(vetores, size);
    VerificarColisao(vetores, size);

    // Organiza os vetores
    SortByAngle(vetor_pontos, size);
    ShowPoints(vetor_pontos, size);
    vetores = ConectarPontos(vetor_pontos, size);
    printf("Vetores: vet X = (pX+1)%%size - (pX)%%size\n");
    ShowPoints(vetores, size);
    VerificarColisao(vetores, size);

    return 0;
}
