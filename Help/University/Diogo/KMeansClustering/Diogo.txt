#include <stdio.h>   // ler, mostrar
#include <stdlib.h>  // random
#include <time.h>

#define nL 10  // num de linhas
#define nC 10  // num de colunas
#define Limiar 3 // limite de erros
#define MaxRandom 300 // valor máximo pra geração de numeros aleatorios

//preenche a matriz com valores aleatorios

void DefMat(int n, int m, int Mat[nL][nC]) {
	int i, j;
	srand(time(NULL));
	for(i=0; i<n; i++)
		for(j=0; j<m; j++) 
			Mat[i][j] = rand()%100;
}

//exibe os elementos da matriz

void MostraMat(int n, int m, int Mat[nL][nC]) {
	int i, j;
	printf("\n ---> Matriz %dx%d <--- \n", n, m);
	for(i=0; i<n; i++){
		for(j=0; j<m; j++)
			printf("%d  ", Mat[i][j]);
		printf("\n");
	}	
}

// exibe os elementos do vetor

void MostraVet(int n, int v[10]){
	int i;
	printf("\n ---. Vetor(%d) .... \n", n);
	for(i=0; i<n; i++)
		printf("%d  ", v[i]);
	printf("\n");
}

// calcula a média dos valores agrupados de acordo com a matriz MatI

void CalcMed(int n, int m, int k, int MatE[nL][nC],int MatI[nL][nC], int VetMed[10]) {
	int i, j , r, vCont[10];
	// Zera os novos acumuladores
	for(i=0; i<nL; i++) {
		vCont[i] = 0;
		VetMed[i] = 0;
	} 
	//Acumula
	for(i=0; i<nL; i++) {
		for(j=0; j<nC; j++){
			r = MatI[i][j];
			VetMed[r]  += MatE[i][j];
			vCont[r] += 1;					
		}
	}
	//calcula a média dos vetores
	for(i=0; i<k; i++){
		if (vCont[i] != 0)
			VetMed[i] /= vCont[i];
	
	}		
}
 // gera uma matriz de índices de agrupamento com base nos valores da matriz MatE e no vetor Vk
void GeraMatI(int n, int m,int k, int MatE[nL][nC], int MatI[nL][nC], int Vk[10]) {
	int i, j, r, rMin, d, dMin;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			dMin = MaxRandom;
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
// gera uma matriz resultante com os indices de agrupamento de MatI e o vetor Vk
void GeraMatS(int MatI[nL][nC], int MatS[nL][nC], int Vk[10]) {
	int i, j, r;
	for(i=0; i<nL; i++){
		for(j=0; j<nC; j++){
			r = MatI[i][j];
			MatS[i][j]= Vk[r];
		}
	}
}
// calcula a distância entre os dois vetores
int CalcDist(int k, int VetR[10], int VetMed[10]){
	int i, d;
	d = 0;
	for (i=0; i<k; i++){
		d += abs(VetR[i] - VetMed[i]);
	}
	return d;
}

// copia os valores de um vetor para o outro
void Copiar(int k, int VetR[10], int VetMed[10]){
	int i;
	for (i=0; i<k; i++){
		VetR[i] = VetMed[i];
	} 		
}

int main(void) {
	int MatE[nL][nC];   //Matriz Entrada
	int MatS[nL][nC]; 	//Matriz Solução
	int MatI[nL][nC];   //Matriz de indices (trabalho)
	int VetR[10]; 	    //Vetor centro de referência 
	int VetMed[10];     //Vetor de novos centros
	int r, i, j, k, d;

    // K relevantes

	DefMat(nL, nC, MatE);
	MostraMat(nL, nC, MatE);
	printf("\n Digite o valor de K... ");
	scanf("%d", &k);
	srand(time(NULL));
	for(r=0; r<k; r++){
		i = rand()%nL;
		j = rand()%nC;
		VetR[r] = MatE[i][j];
	}	
	
	MostraVet(k, VetR);
	
	// agrupamento
	
	do{
		GeraMatI(nL, nC, k ,MatE, MatI, VetR);
		CalcMed(nL, nC, k ,MatE, MatI, VetMed);
		MostraVet(k, VetMed);
		d = CalcDist(k, VetR, VetMed);
		Copiar( k, VetR, VetMed);	
	} while (d > Limiar);
	
	printf("\n Matriz de indices de agrupacao \n");
	
	MostraMat(nL, nC, MatI);
	
	GeraMatS(MatI, MatS, VetR);	
	
	printf("\n Matriz resultante \n");
	
	MostraMat(nL, nC, MatS);
	
	return 0;
}
