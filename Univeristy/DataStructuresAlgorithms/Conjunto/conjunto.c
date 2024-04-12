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

void FindAndSetExtremes(Conjunto* C) {
  C->Sort(C);
  int s = C->numeros[0];
  int b = C->numeros[C->size - C->capacity - 1];

  C->SetSmallest(C, s);
  C->SetBiggest(C, b);
}

void ShowElements(Conjunto* C) {
  if (IsEmpty(C)) { return; }
  C->Sort(C);
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

  if (C->GetSmallest(C) > element) {
    C->SetSmallest(C, element);
  } else if (C->GetBiggest(C) < element) {
    C->SetBiggest(C, element);
  }
  // printf("Added element to %d: S->%d and C->%d\n", C->id, C->size, C->capacity);
}

void RemoveElement(Conjunto* C, int element) {
  int index = 0;
  while (C->numeros[index] != element) { index++; }
  C->numeros[index] = C->numeros[C->size - C->capacity - 1];
  C->numeros[C->size - C->capacity - 1] = 0;
  C->capacity += 1;
  C->FindAndSetExtremes(C);
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

Conjunto* RemoveDuplicates(Conjunto* C) {
  for (int i = 0; i < C->size - C->capacity; i++){
    for (int j = 0; j < C->size - C->capacity; j++){
      if (C->numeros[i] == C->numeros[j] && i != j) {
        C->RemoveElement(C, C->numeros[i]);
      }
    }
  }
  return C;
}

Conjunto* Union(Conjunto* CA, Conjunto* CB) {
  Conjunto* tmp = CreateConjunto();
  tmp->numeros = calloc(CA->size + CB->size, sizeof *tmp);
  memcpy(tmp->numeros, CA->numeros, (CA->size - CA->capacity) * sizeof *(tmp->numeros));
  memcpy(tmp->numeros + (CA->size - CA->capacity), CB->numeros, (CB->size - CB->capacity) * sizeof *(tmp->numeros));
  tmp->size = CA->size + CB->size;
  tmp->capacity = CA->capacity + CB->capacity;
  RemoveDuplicates(tmp);
  tmp->FindAndSetExtremes(tmp);
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
  tmp->FindAndSetExtremes(tmp);
  return tmp;
}

Conjunto* Difference(Conjunto* CA, Conjunto* CB) {
  Conjunto* A = Union(CA, CB);
  Conjunto* B = Intersection(CA, CB);

  for (int i = 0; i < B->size - B->capacity; i++){
    RemoveElement(A, B->numeros[i]);
  }

  A->FindAndSetExtremes(A);
  free(B);
  return A;
}

int GetBiggest(Conjunto* C) {
  C->FindAndSetExtremes(C);
  return C->biggest;
}

int GetSmallest(Conjunto* C) {
  C->FindAndSetExtremes(C);
  return C->smallest;
}

void SetBiggest(Conjunto* C, int number) {
  C->biggest = number;
}

void SetSmallest(Conjunto* C, int number) {
  C->smallest = number;
}

int AssertEquals(Conjunto* CA, Conjunto* CB) {
  printf("%d, %d", CA->size, CB->size);
  return 0;
}

int Compare(const void *a, const void *b){
  int A = *((int*)a);
  int B = *((int*)b);

  if (A < B) {return -1;}
  else if (A > B) {return 1;}
  else {return 0;}
}

void Sort(Conjunto* C) {
  qsort(C->numeros, (C->size - C->capacity), sizeof(int), Compare);
}

void Info(Conjunto* C) {
  printf("Size: %d\n", C->size);
  printf("Capacity: %d\n", C->capacity);
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
    .RemoveDuplicates = RemoveDuplicates,
    .FindAndSetExtremes = FindAndSetExtremes,
    .Info = Info,
    .Sort = Sort,
    .id = 0,
  };
  return C;
}
