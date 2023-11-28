#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char letter;
  int amount;
  struct Node* prox;
} Node;  

typedef struct List {
  int amount;
  Node* first;
  Node* last;
}List;

Node* createNode(char letra){
    Node* node = (Node*)malloc(sizeof(Node));
    node->letter = letra;
    node->amount = 1;
    node->prox = NULL;
    return node;
}

void adicionarElemento(char letra, List* myList){

  Node* node, *last, *new_node;
  node = myList->first;

  if (!node) { myList->first = createNode(letra); myList->amount += 1; }

  do {
    if (node->letter == letra) {
      node->amount += 1;
      break;
    }

    if (letra < node->letter) {
      new_node = createNode(letra);
      new_node->prox = node;
      myList->amount += 1;
      if (last) {
        last->prox = new_node;
      } else {
        myList->first = new_node;
      }
    } else {
      last = node;
      node = node->prox;
    }
  } while (node);
  if (!node) {
    new_node = createNode(letra);
    new_node->prox = node;
    myList->amount += 1;
    if(last){ last->prox = new_node; }
  }
}

void ShowList(Node* node){

  while (node) {
    printf("%c: %d\n", node->letter, node->amount);
    node = node->prox;
  }

}

int main() {

	FILE *arquivo;
	arquivo = fopen("text.txt", "r");
	if(!arquivo) {
		printf("Couldn't open file");
		exit(1);
	}

  List myList;
  myList.first = NULL;
  myList.last = NULL;

  char letra;
  while(!feof(arquivo)) {
		fscanf(arquivo, "%c", &letra);	
		adicionarElemento(letra, &myList);
	}

	fclose(arquivo);
	
  ShowList(myList.first);

  return 0;
}
