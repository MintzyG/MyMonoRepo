#include <stdio.h>   // ler, mostrar
#include <stdlib.h>  // random
#include <time.h>

void defMatEntrada(int mat[10][10]) {
int i, j;
srand(time(0));
for(i=0; i<10; i++){
    for(j=0; j<10; j++){
        mat[i][j] = rand()%100;
    }
}
}

void mostrar(int mat[10][10]) {
int i, j;
printf("\n Matriz \n");
for(i=0; i<10; i++){
    printf("\n");
    for(j=0; j<10; j++){
        printf(" %d", mat[i][j]);
    }
  }
}

void defVk(int k, int vK[10], int mat[10][10]) {
int r, i, j;
srand(time(0));
for(r=0; r<k; r++) {
i = rand()%10;
j = rand()%10;
vK[r] = mat[i][j];
}
printf("\n Vetor vK: \n");
for(r=0; r<k; r++) {
printf(" %d", vK[r]);
}
}

void calVC(int k,int vNew[10],int matE[10][10],int matI[10][10]){
int vc[10],i,j,r;
for(i=0;i<k;i++){
vc[i] = 0;
vNew[i] = 0;
}

for (i=0;i<10;i++){
    for(j=0;j<10;j++){
        r = matI[i][j];
        vNew[r] += matE[i][j];
        vc[r] += 1;
    }
}

for (i=0;i<k;i++){
    vNew[i] = vNew[i] / vc[i];
}
}

void procGeraMatI(int k, int vK[10], int matE[10][10], int matI[10][10]) {
int rMin = 0, d = 0, dMin = 0;
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
		dMin = 300;
			for(int r = 0; r<k; r++){
			d = abs(matE[i][j]-vK[r]);
				if(dMin > d) {
				dMin = d;
				rMin = r;
				}
			}
		matI[i][j] = rMin;
		}
	}
}

void mostraVet(int k, int v[10]){
int i;
printf("\n Vetor \n");

for(i=0;i<k;i++){
printf(" %d",v[i]);
}



}
int calDist(int k,int vK[10],int vNew[10]) {
    int distancia;
    int i;
    for(i=0;i<k;i++){
        distancia = abs(vNew[i] - vK[i]);
    }
    return distancia;
}

void Copia(int k,int vK[10],int vNew[10]){
    int i;
    for(i=0;i<k;i++){
        vK[i] = vNew[i];
    }
}

void geraMatS(int k,int vK[10],int matI[10][10],int matS[10][10]){
    int i,j,ind;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            ind = matI[i][j];
            matS[i][j] = vK[ind];
        }
    }
}

void mostrarS(int mat[10][10]){
    int i,j;
    for(i=0;i<10;i++){
        printf("\n");
        for(j=0;j<10;j++){
            printf(" %d",mat[i][j]);
        }
    }
}

void Inicializar(int matI[10][10]){

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matI[i][j] = 0;
		}
	}
}


int main(void){
    int d;
int matE[10][10], matS[10][10],matI[10][10], vK[10], k,vNew[10],limiar = 5;

Inicializar(matI);

defMatEntrada(matE);
mostrar(matE);

printf("\n Digite valor de k (inteiro): ");
scanf("%d", &k);

defVk(k, vK, matE);
mostraVet(k, vK);


while(1){
mostrar(matI);
procGeraMatI(k, vK, matE, matI);
calVC(k, vNew ,matE,matI);
mostraVet(k,vNew);
mostrar(matI);
d = calDist(k,vK, vNew);
if(d<limiar)
break;
else{
Copia(k, vK, vNew); // vk<-- vNew
}
}
geraMatS(k,vK,matI,matS);
mostrarS(matS);
}
