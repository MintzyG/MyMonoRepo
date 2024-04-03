#include "ponto.h"
#include <stdio.h>

int main() {
  Ponto *pa, *pb;

  pa = CreatePoint(10,21);
  pb = CreatePoint(7,25);

  // pb->x = 7;

  printf("%f", DistanceAB(pa, pb));

  FreePoint(pa);
  FreePoint(pb);

  return 0;
}
