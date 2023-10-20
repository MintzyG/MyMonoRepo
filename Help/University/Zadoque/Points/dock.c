#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define RAND 10

struct points{
	float x;
	float y;
	float angle;
};

float random1(float i){
	if(i==0){
		return rand()%RAND;
	}
	else{
		return rand()%RAND * (-1);
	}
}

void fill_vector(struct points *Vet, int vector_size){
	int i,sign;
	srand(time(0));
	for (i=0;i<vector_size;i++){
		sign = rand()%2;
		Vet[i].x = random1(sign);
		sign = rand()%2;
		Vet[i].y = random1(sign);
		Vet[i].angle = 0;
	}	
}

void show_vector(struct points *Vet, int vector_size){
	int i;
	printf("valor em x    valor em y     angle\n");
	for (i=0;i<vector_size;i++){
		printf("   %f         %f        %f\n", Vet[i].x, Vet[i].y, Vet[i].angle);
	}
}

float get_angle(struct points vet, struct points vet2){
	//float product,magnitude1,magnitude2, cosseno_rad;

    float product = (vet.x * vet2.x) + (vet.y * vet2.y);
    float mag1 = (float)sqrt(pow(vet.x, 2) + pow(vet.y, 2));
    float mag2 = (float)sqrt(pow(vet2.x, 2) + pow(vet2.y, 2));
    float cosseno = acos(product/ sqrt((pow(vet.x, 2) + pow(vet.y, 2))*(pow(vet2.x, 2) + pow(vet2.y, 2))));
    float acos = (cosseno * 180.0) / M_PI;

    printf("\n\nprod:%f\nmag1:%f\nmag2:%f\ncos:%f\nacos:%f\n", product, mag1, mag2, cosseno, acos);
    printf("prodMag:%f\n\n", mag1*mag2);

    return acos;


    /*
	product = ((x1 * x2) + (y1 * y2)); // product scalar
	magnitude1 = (float)sqrt(pow((double)x1, 2) + pow((double)y1,2)); //
	magnitude2 = (float)sqrt(pow((double)x2, 2) + pow((double)y2,2));
    cosseno_rad = acos(product/(magnitude1*magnitude2));
	return cosseno_rad * 180.0 / M_PI;
    */    
}

void fill_angle(struct points *Vet,int vector_size){
	int i;
	srand(time(0));
	int vet_r = rand()%vector_size; //vet_reference will be used for caluculating angle
	printf("vet_r is %d\n",vet_r);
	for (i=0;i<vector_size;i++){
		Vet[i].angle = get_angle(Vet[i], Vet[vet_r]);
	}
}

int main(void){
	int vector_size; // quantidade de pontos para formar o poligono
	printf("how many points do you want to create?");
	scanf("%d",&vector_size);
	while (vector_size <=1){
		printf("\n Voce digitou um valor incoerente, digite novamente por favor");
		scanf("%d",&vector_size);
	}
	struct points *Vet = NULL;  // Declare a pointer to the struct
	Vet = (struct points*)malloc(vector_size * sizeof(struct points));
	if (!Vet) {  // Check for allocation failure
    		printf("there was an error in memory allocation");
	}
	fill_vector(Vet,vector_size);
	show_vector(Vet,vector_size);
	fill_angle(Vet,vector_size);
	show_vector(Vet,vector_size);
	return 0;
}





