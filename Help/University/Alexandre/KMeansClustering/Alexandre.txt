#include <stdio.h>   // ler, mostrar
#include <stdlib.h>  // random
#include <time.h>

void matrizInicial(int mat[10][10]) {
	int i, j;
	srand(time(0));
	for(i=0; i<10; i++)
		for(j=0; j<10; j++) 
			mat[i][j] = rand()%100;
}

void exibir(int mat[10][10]) {
	int i, j;
	printf("\n Matriz \n");
	for(i=0; i<10; i++)
	{
		printf("\n");
		for(j=0; j<10; j++) {
			printf(" %3d", mat[i][j]);	
		}
	}
}

void vetorK(int k, int vK[10], int mat[10][10]) {
	int r, i, j;
	srand(time(0));
	for(r=0; r<k; r++) {
		i = rand()%10;
		j = rand()%10;
		vK[r] = mat[i][j];
	}
	printf("\n Vetor aleatorio K: \n");
	for(r=0; r<k; r++) {
		printf(" %3d", vK[r]);
	}	
}

void matrizSaida(int k, int vK[10], int matI[10][10], int matS[10][10]) {
	int i, j, r, rMin, d, dMin;
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			dMin = 300;
			for(r=0; r<k; r++){
				d = abs(matI[i][j]-vK[r]);
				if(dMin > d) {
					dMin = d;
					rMin = r;
				}
			}
			matS[i][j] = rMin;
		}
	}
}

void calmedia(int k,int vMedia[10],int matrizInicialr[10][10],int matrizSaidar[10][10])
{
    int i,j,t,r,vcont[10];

       for(t=0;t<k;t++) 
       {
           vcont[t]=0;
           vMedia[t]=0;  }

           for(i=0;i<10;i++)
           {
               for(j=0;j<10;j++)
            {
                   r=matrizSaidar[i][j];
                   vMedia[r]+= matrizInicialr[i][j];
                   vcont[r]+=1;

            }
        }
        for(i=0;i<k;i++){
            vMedia[i]/=(float)vcont[i];
        }


}


    void exibirV(int vMedia[10],int n)
{
    int t;
    printf("\n-----------------");
    printf("\n  NOVO  VETOR DAS MEDIAS   \n");
    printf("-----------------\n");
    for(t=0; t<n; t++) {
        printf(" %d", vMedia[t]);
    }
}
    
int dist(int k,int vetorKr[10],int vMedia[10])
{
   int i,distancia=0;

   for(i=0;i<k;i++){
       distancia+=abs(vMedia[i]-vetorKr[i]);
   }
       return distancia;
}


void copia(int k,int vetorKr[10], int vMedia[10]) 
{
    int i;

     for(i=0;i<k;i++){
         vetorKr[i]=vMedia[i];
     }


}

void matrizFimm(int vetorKr[10], int k, int matrizInicialr[10][10], int matrizFim[10][10]) 
{
    int i, j;

    for ( i = 0; i < 10; i++) {
        for ( j = 0; j < 10; j++) {
            int indice = matrizFim[i][j];
            matrizFim[i][j] = vetorKr[indice];
        }
    }

}



int main(void) {
	int matrizInicialr[10][10], matrizSaidar[10][10], vetorKr[10], k, vMedia[10], d, erro=5, matrizFim[10][10];
	
	matrizInicial(matrizInicialr);
	
    exibir(matrizInicialr);

	printf("\n Digite um valor para o tamanho do vetor: ");
	scanf("%d", &k);
	
	vetorK(k, vetorKr, matrizInicialr);

	while (1)
    {
    
	matrizSaida(k, vetorKr, matrizInicialr, matrizSaidar);
	exibir(matrizSaidar);

    calmedia(k, vMedia, matrizInicialr, matrizSaidar);

    exibirV(vMedia, k);
	
    d = dist(k, vetorKr, vMedia);
if (d<erro)
    break;
else

    copia(k, vetorKr, vMedia);
    
    }

  	printf("UHUL");	
    matrizFimm(vetorKr, k, matrizInicialr, matrizFim);

    exibir(matrizFim);

    return 0;
}
