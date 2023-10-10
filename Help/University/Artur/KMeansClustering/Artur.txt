#include <stdio.h>   // ler, mostrar
#include <stdlib.h>  // random
#include <time.h>


void defMatEntrada(int mat[10][10]) {
	int i, j;
	srand(time(0)); // serve pro rand()%100 dar valores aleatorios
	for(i=0; i<10; i++) // Gera matriz
		for(j=0; j<10; j++)
			mat[i][j] = rand()%100; // define valores aleatorios para a matriz
}

void mostrar(int mat[10][10]) {
	int i, j;
	printf("\n Matriz \n"); 
	for(i=0; i<10; i++) // ler as ler as linhas
	{
		printf("\n");
		for(j=0; j<10; j++) // ler as colunas
			printf(" %3d", mat[i][j]); // escreve a matriz
	}
	printf("\n\n");
}

void defVk(int k, int vK[10], int mat[10][10]) {
	int r, i, j;
	i = 0;
	j = 0;
	srand(time(0));
	for(r=0; r<k; r++) { //define o vetor
		i = rand()%10; // valores aleatorios das linhas
		j = rand()%10; // valores aleatorios das colunas
		vK[r] = mat[i][j]; // o vetor pega um valor da posição da matriz ex [1][2]
	}
	printf("\n Vetor vK: \n"); // escreve o vetor
	for(r=0; r<k; r++) { // pega os valores do vetor 
		printf(" %d", vK[r]); // escreve os valores do vetor na tela
	}
}

void procGeraMatS(int k, int vK[10], int matE[10][10], int matS[10][10],int MatI[10][10]) {
	int i, j, r, rMin, d, dMin;
	for(i=0; i<10; i++) // pegando os valores de matE
		for(j=0; j<10; j++){ //  pegando os valores de matE
			dMin = 100; // valor alto pra não falhar, creio que o minimo seja 100
			for(r=0; r<k; r++){ // pegando os valores de vK
				d = abs(matE[i][j]-vK[r]); // compara os valores de vK e da matE, escolhendo o valor de vK mais proximo da posição da matE
				if(dMin > d) { // troquinha classica
					dMin = d;
					rMin = r;
				}
			}
			matS[i][j] = vK[rMin]; //pega os valores do vetor mais proximos a posição da matE
			MatI[i][j] = rMin; // pega os indices do vetor e taca na matriz
		}
}

void mostrarv(int vk[10], int k){
	int j;
		for(j=0; j<k; j++){
			printf(" %2d",vk[j]);
		
	}
	printf("\n\n"); //so mostra o vetor
}


int geravkmedio(int k, int vk[10],int matE[10][10],int matS[10][10],int matI[10][10],int vkm[10]){
	int i,j, melhor = 0, valoresvk[10], Vetcont[10];

	for (int i = 0; i < k; i++) {
		valoresvk[i] = 0;
		Vetcont[i] = 0;
	}
	
	for (i=0;i<10;i++){ // gera
		for (j=0;j<10;j++){ // matriz
				valoresvk[matI[i][j]] = valoresvk[matI[i][j]] + matE[i][j]; // somador dos valores de matE correspondentes ao indice 
				Vetcont[matI[i][j]]++; 
		}
	}
	
	for (i=0;i<k;i++){ // gera vkm
		if (Vetcont[i] != 0)
			valoresvk[i] = valoresvk[i]/Vetcont[i]; // preenche vkm
	        vkm[i] = valoresvk[i];
	}

	for (i=0; i<k; i++){
		if (abs(vkm[i] - vk[i]) > 1){
			melhor = 1;
			break;
		}
	}

	if (melhor){
		for (i=0; i<k; i++){
			vk[i] = vkm[i];
		}
		return melhor;	
	}

	return melhor;
		
}

int main(void) {
	int matE[10][10], matS[10][10], vK[10], k, MatI[10][10],vkm[10];
	printf("\n Digite valor de k (inteiro): ");
	scanf("%d", &k);
	defMatEntrada(matE); 
	defVk(k, vK, matE);
	printf("\n");
	mostrar(matE);
	procGeraMatS(k, vK, matE, matS,MatI);
	while(1){
		printf("\n");
		if (geravkmedio(k,vK,matE,matS,MatI,vkm)) {
			printf("%d", geravkmedio(k,vK,matE,matS,MatI,vkm));
			procGeraMatS(k, vK, matE, matS,MatI);
			mostrar(matS);
		}
		else 
			break;
	}
	return 0;
}
