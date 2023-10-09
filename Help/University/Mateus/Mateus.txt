#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>

#define MaximoAleatorio 300
#define linha 10  
#define coluna 10  
#define Limite 1 
 



void Matriz(int n, int m, int Mat[linha][coluna]) {
	int i, j;
	srand(time(0));
	for(i=0; i<n; i++)
		for(j=0; j<m; j++) 
			Mat[i][j] = rand()%100;
}



void MostrarMatriz(int n, int m, int Mat[linha][coluna]) {        // exibição de elementos
	int i, j;
	printf("\n - Matriz %dx%d - \n", n, m);
	for(i=0; i<n; i++){
		for(j=0; j<m; j++)
			printf("%d  ", Mat[i][j]);
		printf("\n");
	}	
}



void MostrarVetor(int n, int v[10]){        
	int i;
	printf("\n - Vetor(%d) - \n", n);
	for(i=0; i<n; i++)
		printf("%d  ", v[i]);
	printf("\n");
}

// média dos valores agrupados MatrizI

void CMedia(int n, int m, int k, int MatE[linha][coluna],int MatI[linha][coluna], int VetorMedia[10]) {
	int i, j , r, vCont[10];
	for(i=0; i<linha; i++) {
		vCont[i] = 0;
		VetorMedia[i] = 0;
	} 
	for(i=0; i<linha; i++) {              // laço 
		for(j=0; j<coluna; j++){
			r = MatI[i][j];
			VetorMedia[r]  += MatE[i][j];
			vCont[r] += 1;					
		}
	}
	// média dos vetores
	for(i=0; i<k; i++){
		if (vCont[i]!= 0){
		VetorMedia[i] /= vCont[i];
		}
	}		
}

//  matrizI com base na MatE e no vetor Vk

void MatrizI(int n, int m,int k, int MatE[linha][coluna], int MatI[linha][coluna], int Vk[10]) {
	int i, j, r, rMin, d, dMin;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			dMin = MaximoAleatorio;
			for(r=0; r<k; r++){
				d = abs( MatE[i][j] - Vk[r]);
				if(d < dMin) {
					dMin = d;
					rMin = r;
				}
			}
			MatI[i][j] = rMin;
		}	
	}
}
//  matriz resultante com os indices de agrupamento de MatI e o vetor Vk
void MatrizResultante(int MatI[linha][coluna], int MatS[linha][coluna], int Vk[10]) {
	int i, j, r;
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			r = MatI[i][j];
			MatS[i][j]= Vk[r];
		}
	}
}

int Distancia(int k, int VetR[10], int VetorMedia[10]){    
	int i, dist;
	dist = 0;
	for (i=0; i<k; i++){
		dist += abs(VetR[i] - VetorMedia[i]);             // distância absoluta entre dois vetores
	}
	return dist;
}


void CopiarValor(int k, int VetR[10], int VetorMedia[10]){          // valores de um vetor copiados para o outro
	int i;
	for (i=0; i<k; i++){
		VetR[i] = VetorMedia[i];
	} 		
}

int main(void) {
	int MatE[linha][coluna];   
	int MatS[linha][coluna]; 	
	int MatI[linha][coluna];   
	int VetR[10]; 	      // Referência 
	int VetorMedia[10];       //Vetor de novos centros
	int r, i, j, k, dist;

    

	Matriz(linha, coluna, MatE);
	MostrarMatriz(linha, coluna, MatE);
	printf("\n Digite o valor de K : ");
	scanf("%d", &k);
	srand(time(0));
	for(r=0; r<k; r++){
		i = rand()%linha;
		j = rand()%coluna;
		VetR[r] = MatE[i][j];
	}	
	
	MostrarVetor(k, VetR);
	
	
	
	do{                                                                  // chama funções para cálculos e atribuições
		MatrizI(linha, coluna, k ,MatE, MatI, VetR);
		CMedia(linha, coluna, k ,MatE, MatI, VetorMedia);
		MostrarVetor(k, VetorMedia);
		dist = Distancia(k, VetR, VetorMedia);
		CopiarValor( k, VetR, VetorMedia);
	    MatrizResultante(MatI, MatS, VetR);	
        MostrarMatriz(linha, coluna, MatS);
	} while (dist > Limite);
	
	printf("\n Matriz de indices agrupacao : \n");
	
	MostrarMatriz(linha, coluna, MatI);
	
	MatrizResultante(MatI, MatS, VetR);	
	
	printf("\n Matriz resultante : \n");
	
	MostrarMatriz(linha, coluna, MatS);
	
	return 0;
}
