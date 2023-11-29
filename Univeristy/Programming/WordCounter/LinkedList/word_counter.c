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

  if (node == NULL) {
    myList->first = createNode(letra);
    myList->amount += 1;
    return;
  }

  do {
    if (node->letter == letra) {
      node->amount += 1;  
      return;
    }

    if (letra < node->letter) {
      new_node = createNode(letra);
      new_node->prox = node;
      myList->amount += 1;
      if (last == NULL) { myList->first = new_node; }
      else { last->prox = new_node; }
      break;
    }
    else {
      last = node;
      node = node->prox;
    }
  } while (node != NULL);

  if (node == NULL) {
    new_node = createNode(letra);
    new_node->prox = NULL;
    myList->amount += 1;
    if (last != NULL) { last->prox = new_node; }
  }
}

void ShowList(Node* node){
  while (node) {
    printf("%c: %d\n", node->letter, node->amount);
    node = node->prox;
  }
}

void Place(Node* node, List* myList){
  Node *sort, *last;
  sort = myList->last;
  last = NULL;
  
  if(sort == NULL){
    node->prox = NULL;
    myList->last = node;
    return;
  }

  do {
    if (sort->amount >  node->amount) {
      if (last != NULL) {
        myList->last = node;
        node->prox = sort;
      } else {
        node->prox = last->prox;
        last->prox = node;
      }
      break;
    }

    last = sort;
    sort = sort->prox;

  } while (sort != NULL);

  if (last != NULL) { last->prox = node; }

}

void SortList(List* myList){
  Node *node, *next;
  node = myList->first;
  while (node != NULL) {
    next = node->prox;
    Place(node, myList);
    node = next;
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
  while((letra = fgetc(arquivo)) != EOF) {
    adicionarElemento(letra, &myList);
  }

  fclose(arquivo);
 
  printf("Lista\n");
  ShowList(myList.first);

  printf("Ordenando lista\n");
  // SortList(&myList);
  // ShowList(myList.first);

  return 0;
}
