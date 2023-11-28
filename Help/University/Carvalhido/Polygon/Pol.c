#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RAND 200

typedef struct Point {
    float x;
    float y;
    float a;
}Point;

Point* IniciarVet(int size){
  Point* ponto = (Point*)malloc(size * sizeof(Point));
  for( int i = 0; i < size; i++){
      ponto[i].x = 0;
      ponto[i].y = 0;
      ponto[i].a = 0;
  }
  return ponto;
}

void Preencher(Point *ponto, int size){
  int i;
  for( i = 0; i < size; i++){
      int sinal_x = rand()%2;
      int sinal_y = rand()%2;
      if(sinal_x == 0) sinal_x = -1;
      if(sinal_y == 0) sinal_y = -1;
        ponto[i].x = sinal_x * (float)(((double)rand()/(double)(RAND_MAX) * RAND));
        ponto[i].y = sinal_y * (float)(((double)rand()/(double)(RAND_MAX) * RAND));
        ponto[i].a = 0;
  }

  float x = 0, y = 0;
  for ( i = 0; i < size ; i++) {
    x += ponto[i].x;
    y += ponto[i].y;
  }

  x = x / size;
  y = y / size; 

  for ( i = 0; i < size; i++) {     
    ponto[i].x - x;
    ponto[i].y - y;
  }

}

void Mostrar(Point *ponto, int size){
  printf("%c%8c%c%7c%c\n", 'X', ' ', 'Y', ' ', 'A');
  int i;
  for( i = 0; i < size; i++){
    printf("%07.2f  %07.2f %07.2f\n", ponto[i].x, ponto[i].y, ponto[i].a);
  }
}

void Angulo(Point *ponto, int size, float *VetRef){
  int i; 
  for( i = 0; i < size; i++){
    float dir = ponto[i].x * VetRef[1] - VetRef[0] * ponto[i].y;
    float ProdEsc = ponto[i].x * VetRef[0] + VetRef[1] * ponto[i].y;
    float Dist1 = sqrt(pow(VetRef[0],2) + pow(VetRef[1],2));
    float Dist2 = sqrt(pow(ponto[i].x,2) + pow(ponto[i].y,2));
    float cos = ProdEsc / (Dist1 * Dist2);
    float AngRad = acos(cos);
    float AngGraus = AngRad * 180.0 / M_PI;
    if(dir < 0){ponto[i].a = 360 - AngGraus;}
    else{ponto[i].a = AngGraus;}
    //printf("dir: %f prodesc: %f dist1: %f dist2: %f algo: %f AngRad: %f AngGraus: %f\n", dir, ProdEsc, Dist1, Dist2, algo, AngRad, AngGraus);
  }
}

void troca(Point *a, Point *b){
  Point temp = *a;
  *a = *b;
  *b = temp;
}


void OrgAng(Point *ponto, int size){
    int j,i;   
    for( j = 0; j< size; j++){
    for( i = 0; i < size - 1; i++){
      if (ponto[i].a > ponto[i+1].a){
        troca(&ponto[i], &ponto[i+1]);
      }
    }
  }
}


// FunÃ§Ã£o para encontrar a posiÃ§Ã£o correta do pivÃ´ no array
int partition(Point *arr, int low, int high) {
    float pivo = arr[high].a; // Escolhendo o ultimo elemento como pivÃ´
    int i = (low - 1);     // Ãndice do menor elemento
    int j;
    for ( j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivÃ´
        if (arr[j].a <= pivo) {
            i++; // Incrementa o Ã­ndice do menor elemento
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// FunÃ§Ã£o principal do Quick Sort
void quickSort(int low, int high, Point *arr) {
        if (low <= high) {
        // Encontra a posiÃ§Ã£o do pivÃ´
        int pi = partition(arr, low, high);

        // Ordena os elementos antes e depois da posiÃ§Ã£o do pivÃ´
        quickSort(low, pi - 1, arr);
        quickSort(pi + 1, high, arr);
    }
}

float Area(Point *ponto, int size){


}

void Uniao(Point *ponto, int size){
 printf("\n");
 int i;
 for( i = 0; i < size; i++){
   float v1 = ponto[(i)%size].x;
   float v2 = ponto[(i+1)%size].x;
   float v3 = ponto[(i)%size].y;
   float v4 = ponto[(i+1)%size].y;
   printf("(%f, %f)\n",v2-v1, v4-v3);
 }
}

int main(){
  float VetRef[3] = {0, 1, 0};
  int T = 0;
  srand(time(0));

  printf("Informe a quantidade de vetores: ");
  scanf("%d", &T);

  Point *ponto = IniciarVet(T);
  Preencher(ponto, T);
  // Mostrar(ponto, T);  

  printf("\nCalculando Angulo\n");
  Angulo(ponto, T, VetRef);
  // Mostrar(ponto, T);

  //OrgAng(ponto, T);
  quickSort(0, T - 1, ponto);
  printf("\nDepois de organizar angulo: \n");
  float area = Area(ponto, T);
  // Mostrar(ponto, T);



  // Uniao(ponto, T);
  return 0;
}
