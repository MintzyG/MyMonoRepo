#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preenche_ale_vet(int *v, int k,int max){
	int i,j;
	srand(time(0));
	for (i=0;i<k;i++){
		v[i]= rand()%max;
		if (i>0){
            for(j=i;j>0;j--){
                while(v[i] == v[j-1]){
                    v[i]= rand()%max;
                }
            }
        }
	}
}

void preenche_manu_vet(int *v, int k){
	int i;
	for (i=0;i<k;i++){
		printf("\nDigite o valor para a posição %d:  ",i+1);
		scanf("%d", &v[i]);

	}
}

void mostrar_vet(int *v,int k){
	int i;
	printf("\n");
	for (i=0;i<k;i++){
		printf(" %d",v[i]);
	}
}

int quick_sort_first(int *v, int inicio, int fim){
	int i,temp=0,t, c=1,pos_troca=1,parar =0;
    int new_inicio=0;
    
    if (fim - inicio < 2){
    return 0;
    }

    while (c!=0){
        c=0;
        t=0;
        for (i=inicio;i<fim;i++){
            if (fim-t < i && parar ==0){
               // printf("\n fim - t e %d, a posicao i e %d: ", fim-t, i);
                temp = v[inicio];
                v[inicio] = v[fim-t-1];
                v[fim-t-1] = temp;
                new_inicio = fim-t-1;
               // printf("\nO novo inicio ou fim sera %d", new_inicio);
                parar = 1;
            }
            else {
                if (v[inicio] > v[fim-t]&& parar ==0){
                    temp = v[fim-t];
                    v[fim-t]= v[pos_troca];
                    v[pos_troca] = temp;
                    c++;
                    pos_troca++;
                    //printf("\n troquei, está assim: ");
                   // mostrar_vet(v,fim);
                }
            }
            t++;
        }
    }


        quick_sort_first(v, inicio, new_inicio-1);
        quick_sort_first(v,new_inicio,fim);
    return 0;

}

int main(void){
	int i,j=0;
	printf("Qual tamanho do vetor que vc quer ordenar ?");
	scanf("%d", &i);
	int *vet = (int*)malloc(i*sizeof(int));
	if (!vet){
		printf("erro ao alocar memória");
	}
	printf("Escolha:\n Digite (1) para preencher o vetor aleatoriamente. \n Digite (2) para preencher o vetor manualmente. \n");
	scanf("%d", &j);
	if (!((j==1) ||(j==2))){
		while (!((j==1) ||(j==2))){
			printf(" Você digitou algo diferente de (1) ou (2). Escolha novamente por favor.");
			scanf("%d",&j);
		}
	}
	if (j==1){
		int m;
		printf("\n Qual o maior número que vc quer que apareça no vetor");
		scanf("%d", &m);
		preenche_ale_vet(vet,i,m);
	}
	else{
		preenche_manu_vet(vet,i);
	}
	mostrar_vet(vet,i);
	j = quick_sort_first(vet, 0,i);
	mostrar_vet(vet,i);
	return 0;
}
