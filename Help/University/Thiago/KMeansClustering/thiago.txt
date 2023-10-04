#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
int matriz1[10][10], matrizf[10][10];
int k;
int vetk[10], vetx[10];
  

srand(time(NULL));
 for (int i=0 ; i < 10; i++){
  for (int j=0 ; j < 10; j++){
   matriz1[i][j] = rand()%100 + 1;
  }
 }
  printf("\n");
  for(int i = 0; i<10; i++){
   for(int j = 0; j<10; j++){
    printf("%d ", matriz1[i][j]);
   }
    printf("\n");
  }
 printf("Coloque o tamanho do vetor:");
 scanf("%d", &k);
 for (int i=0 ; i<k; i++){
    vetk[i] = matriz1[rand()%10][rand()%10];
   
  
}

  printf("\n");
  for(int i=0; i<k; i++){
  printf("%d\n", vetk[i]);
    
  }
  for(int i=0 ; i<10; i++){
   for(int j=0 ; j<10; i++){
    for(int l=0 ; l<k; l++){
     vetx[l] = abs(matriz1[i][j] - vetk[l]);
     if(l==k-1){
      int menor=0;
      for(int m=0 ; m < k; m++){
       if(vetx[m] < vetx[menor]){
	 menor = m;
        matrizf[i][j] = vetx[menor];
        
      }    
    }

    
    }
  
    }
    }
  }
  
  return 0;
}
