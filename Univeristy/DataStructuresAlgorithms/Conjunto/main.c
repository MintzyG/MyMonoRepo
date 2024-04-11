#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "conjunto.h"

int main() {
  srand(time(NULL));

  Conjunto* C = CreateConjunto();
  
  C->InsertElement(C, 70);

  for (int i = 0; i < 6; i++) { C->InsertElement(C, i); }
  C->ShowElements(C);

  C->RemoveElement(C, 70);
  C->ShowElements(C);
  
  return 0;
}
