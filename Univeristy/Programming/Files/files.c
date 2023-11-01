#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
	char letra;
	int amount;
} Element;

typedef struct Vector {
	int size;
	Element* letras;
} Vector;

int main() {

	FILE *arquivo;
	Vector text;
	text.size = 1;
	arquivo = fopen("text.txt", "r");
	if(!arquivo) {
		printf("Couldn't open file");
		exit(1);
	}
	
	text.letras = (Element*)malloc(text.size * sizeof(Element));

	char letra;
	int added = 0;

	while((letra = fgetc(arquivo)) != EOF){

		Vector tmp;
			
		int found = 0;
		int position;

		if (added == 0) {
			text.letras[0].letra = letra;
			added += 1;
		} else {
			for (int i = 0; i < text.size; i++){
				if (text.letras[i].letra == letra){
					found = 1;
					position = i;
				}
			}
			if (found != 1){
				if (text.size == added){
					tmp.letras = (Element*)realloc(&text, text.size * sizeof(Element));
					tmp.letras = memcpy(&tmp.letras, &text.letras, text.size);
					text.size *= 2;
					text.letras[added+1].letra = letra;
					text.letras[position].amount += 1;
					added += 1;
				} else {
					text.letras[added+1].letra = letra;
					text.letras[position].amount += 1;
					added += 1;
				}
			} else {
				text.letras[position].letra = letra;
				text.letras[position].amount += 1;
			}
		}
	}
	
	fclose(arquivo);

	for (int i = 0; i < text.size; i++){
		printf("%c aparece %d vezes\n", text.letras[i].letra, text.letras[i].amount);
	}


	return 0;
}
