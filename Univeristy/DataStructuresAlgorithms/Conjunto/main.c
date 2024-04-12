#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "conjunto.h"

int main() {
  srand(time(NULL));

  Conjunto* CA = CreateConjunto();
  Conjunto* CB = CreateConjunto();

  CA->id = 1;
  CB->id = 2;

  CA->InsertElement(CA, 70);
  CB->InsertElement(CB, 70);
  CB->InsertElement(CA, 0);
  CB->InsertElement(CB, 0);

  for (int i = 0; i < 9; i++) { CA->InsertElement(CA, i+1); }
  for (int i = 6; i < 12; i++) { CB->InsertElement(CB, i+1); }
  CA->InsertElement(CA, 4);
  CA->ShowElements(CA);
  CB->ShowElements(CB);

  CA->RemoveElement(CA, 70);
  CA->RemoveElement(CA, 4);
  CA->ShowElements(CA);

  CA->ContainsElement(CA, 4);
  CA->ContainsElement(CA, 29);

  CA->Info(CA);
  CB->Info(CB);
  printf("Trying Union\n");
  Conjunto* U = CA->Union(CA, CB);
  Conjunto* I = CA->Intersection(CA, CB);

  U->ShowElements(U);
  I->ShowElements(I);

  // Era pra fazer a uniao disjuntiva ou nao?
  Conjunto* R = U->Difference(U, I);
  R->ShowElements(R);
  printf("Smallest: %d\nBiggest: %d\n", R->GetSmallest(R), R->GetBiggest(R));

  return 0;
}
