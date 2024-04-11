#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conjunto.h"

void ReallocConjunto(Conjunto* C) {
  if (C->size == 0) {
    C->numeros = (int*)calloc(1, sizeof(int));
    C->size = 1;
    C->capacity = 1;
    return;
  }

  int* tmp = (int*)calloc(C->size * 2, sizeof *tmp);
  memcpy(tmp, C->numeros, C->size * sizeof *tmp);
  C->numeros = tmp;
  C->size *= 2;
  C->capacity = C->size / 2;
}

void ShowElements(Conjunto* C) {
  if (C->size == C->capacity) {
    printf("Array is empty");
    return;
  }
  for(int i = 0; i < C->size; i++) {
    printf("%d ", C->numeros[i]);
  }
  printf("\n");
}

void InsertElement(Conjunto* C, int element) {
  if (C->capacity == 0) { ReallocConjunto(C); }
  int index = C->size - C->capacity;
  C->numeros[index] = element;
  C->capacity -= 1;
}

void RemoveElement(Conjunto* C, int element) {
  int index = 0;
  while (C->numeros[index] != element) { index++; }
  C->numeros[index] = C->numeros[C->size - C->capacity - 1];
  C->numeros[C->size - C->capacity - 1] = 0;
  C->capacity += 1;
}

void ContainsElement(Conjunto* C, int element) {
  printf("%d, %d", C->size, element);
}

Conjunto* Union(Conjunto* CA, Conjunto* CB) {
  printf("%d, %d", CA->size, CB->size);
  return NULL;
}

Conjunto* Intersection(Conjunto* CA, Conjunto* CB) {
  printf("%d, %d", CA->size, CB->size);
  return NULL;
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
    .Sort = Sort
  };
  return C;
}
