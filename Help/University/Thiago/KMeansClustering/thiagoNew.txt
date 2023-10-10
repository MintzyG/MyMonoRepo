#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher_matriz(int matriz1[10][10]){
  srand(time(NULL));
 for (int i=0 ; i < 10; i++){
  for (int j=0 ; j < 10; j++){
   matriz1[i][j] = rand()%100;
  }
 }
  printf("\n");
  for(int i = 0; i<10; i++){
   for(int j = 0; j<10; j++){
    printf("%d ", matriz1[i][j]);
   }
    printf("\n");
  }  
}

void preencher_vetor(int vetk[10] , int k,int matriz1[10][10]){
 for(int i=0 ; i<k; i++){
    vetk[i] = matriz1[rand()%10][rand()%10];
}
  printf("\n");
  for(int i=0; i<k; i++){
  printf("%d\n", vetk[i]);   
  } 
}

void fazer_matriz_indice(int matriz_indice[10][10],int k, int vetk[10], int matriz1[10][10]){
for(int i=0 ; i<10; i++){
    for(int j=0 ; j<10; j++){
     int menor=101;
     int indice=0;
     for(int l=0 ; l<k; l++){
       if (menor > abs(matriz1[i][j] - vetk[l])){
       menor = abs(matriz1[i][j] - vetk[l]);
       indice =  l;   
       }
     }
    matriz_indice[i][j] =  indice ;
    }
  }  
    printf("\n");
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      printf("%d ", matriz_indice[i][j]);  
} 
   printf("\n"); 
}
}

void compilamento(int k, int matriz_indice[10][10], int matriz1[10][10], int vetn[10]){
int vetc[10];
for(int i=0; i<10; i++){  
 for(int j=0; j<10; j++){  
  vetn[matriz_indice[i][j]] =  vetn[matriz_indice[i][j]] + matriz1[i][j];
  vetc[matriz_indice[i][j]] = vetc[matriz_indice[i][j]] + 1;
 }
} 
for(int l=0; l<k; l++){
vetn[l]= vetn[l] / vetc[l];
  printf("\n");
  printf("%d ", vetn[l]);
}
 }

int distanc(int d, int k, int vetk[10], int vetn[10]){
  for(int i=0; i<k; i++){
    if(abs(vetk[i] - vetn[i]) > 2){
      vetk[i] = vetn[i];
    }
    else{
      d += 1;
    }
  }
  return d;
}

void fazer_matriz_saida(int vetk[10], int matriz_indice[10][10], int matriz_fim[10][10]){
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      matriz_fim[i][j] = vetk[matriz_indice[i][j]];
    }
  }
  printf("\n");
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      printf("%d ", matriz_fim[i][j]);
        }
    printf("\n");
  }
}
  

int main(void){
int matriz1[10][10], matriz_indice[10][10], matriz_fim[10][10];
int k, d = 0;
int vetk[10], vetn[10];

preencher_matriz(matriz1);
 printf("Coloque o tamanho do vetor:");
 scanf("%d", &k);
preencher_vetor(vetk, k, matriz1);
while(d!=k){
fazer_matriz_indice(matriz_indice, k, vetk, matriz1);
compilamento(k, matriz_indice, matriz1, vetk);
d = distanc(d, k, vetk, vetn);
if (d == 0) {
	break;
}
}
fazer_matriz_saida(vetk, matriz_indice, matriz_fim);

  
  return 0;
}
