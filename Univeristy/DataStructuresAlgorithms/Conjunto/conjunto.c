#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conjunto.h"

int ContainsElement(Conjunto*, int);
Conjunto* CreateConjunto();

void ReallocConjunto(Conjunto* C) {
  if (C->size == 0) {
    C->numeros = (int*)calloc(1, sizeof(int));
    C->size = 1;
    C->capacity = 1;
    // printf("Resized %d to: S->%d and C->%d\n", C->id, C->size, C->capacity);
    return;
  }

  int* tmp = (int*)calloc(C->size * 2, sizeof *tmp);
  memcpy(tmp, C->numeros, C->size * sizeof *tmp);
  C->numeros = tmp;
  C->size *= 2;
  C->capacity = C->size / 2;
  // printf("Resized %d to: S->%d and C->%d\n", C->id, C->size, C->capacity);
}

int IsEmpty(Conjunto* C) {
  if (C->size == C->capacity) {
    // printf("{%d:%d} - Array is empty\n", C->size, C->capacity);
    return 1;
  }
  return 0;
}

void ShowElements(Conjunto* C) {
  if (IsEmpty(C)) { return; }
  for(int i = 0; i < C->size - C->capacity; i++) {
    printf("%d ", C->numeros[i]);
  }
  printf("\n");
}

void InsertElement(Conjunto* C, int element) {
  if (!IsEmpty(C) && C->ContainsElement(C, element)) { 
    printf("Already in set\n"); 
    return; 
  }
  if (C->capacity == 0 || IsEmpty(C)) { ReallocConjunto(C); }
  int index = C->size - C->capacity;
  C->numeros[index] = element;
  C->capacity -= 1;
  // printf("Added element to %d: S->%d and C->%d\n", C->id, C->size, C->capacity);
}

void RemoveElement(Conjunto* C, int element) {
  int index = 0;
  while (C->numeros[index] != element) { index++; }
  C->numeros[index] = C->numeros[C->size - C->capacity - 1];
  C->numeros[C->size - C->capacity - 1] = 0;
  C->capacity += 1;
  // printf("Removed element from %d: S->%d and C->%d\n", C->id, C->size, C->capacity);
}

int ContainsElement(Conjunto* C, int element) {
  int index = 0;

  if (IsEmpty(C)) { return -1; }
  for(; index <= C->size; index++) {
    if (index == C->size) { break; }
    if (C->numeros[index] == element) { break; }
  }

  if (index == C->size) { 
    // printf("Couldn't locate element\n"); 
    return 0; 
  } else { 
    printf("Located element %d at position %d\n", C->numeros[index], index + 1); 
    return 1; 
  }
}

Conjunto* Union(Conjunto* CA, Conjunto* CB) {
  Conjunto* tmp = CreateConjunto();
  tmp->numeros = calloc(CA->size + CB->size, sizeof *tmp);
  memcpy(tmp->numeros, CA->numeros, (CA->size - CA->capacity) * sizeof *(tmp->numeros));
  memcpy(tmp->numeros + (CA->size - CA->capacity), CB->numeros, (CB->size - CB->capacity) * sizeof *(tmp->numeros));
  tmp->size = CA->size + CB->size;
  tmp->capacity = CA->capacity + CB->capacity;
  return tmp;
}

Conjunto* Intersection(Conjunto* CA, Conjunto* CB) {
  Conjunto* tmp = CreateConjunto();
  for (int i = 0; i < CA->size - CA->capacity; i++){
    for (int j = 0; j < CB->size - CB->capacity; j++){
      if (CA->numeros[i] == CB->numeros[j]) {
        InsertElement(tmp, CA->numeros[i]);
      }
    }
  }
  return tmp;
}

Conjunto* Difference(Conjunto* CA, Conjunto* CB) {
  printf("%d, %d", CA->size, CB->size);
  return NULL;
}

int GetBiggest(Conjunto* C) {
  printf("%d", C->size);
  return 0;
}

int GetSmallest(Conjunto* C) {
  printf("%d", C->size);
  return 0;
}

void SetBiggest(Conjunto* C, int number) {
  printf("%d, %d", C->size, number);
}

void SetSmallest(Conjunto* C, int number) {
  printf("%d, %d", C->size, number);
}

int AssertEquals(Conjunto* CA, Conjunto* CB) {
  printf("%d, %d", CA->size, CB->size);
  return 0;
}

void Sort(Conjunto* C) {
  printf("%d", C->size);
}

void Info(Conjunto* C) {
  printf("Size: %d\n", C->size);
  printf("Capacity: %d\n", C->size);
}

void FreeConjunto(Conjunto* C) {
  printf("%d", C->size);
}

Conjunto* CreateConjunto() {
  Conjunto* C = calloc(1, sizeof *C);
  *C = (Conjunto) {
    .numeros = NULL,
    .size = 0,
    .capacity = 0,
    .smallest = 0,
    .biggest = 0,
    .InsertElement = InsertElement,
    .RemoveElement = RemoveElement,
    .ContainsElement = ContainsElement,
    .Union = Union,
    .Intersection = Intersection,
    .Difference = Difference,
    .GetBiggest = GetBiggest,
    .GetSmallest = GetSmallest,
    .SetBiggest = SetBiggest,
    .SetSmallest = SetSmallest,
    .AssertEquals = AssertEquals,
    .ShowElements = ShowElements,
    .Info = Info,
    .Sort = Sort,
    .id = 0,
  };
  return C;
}
