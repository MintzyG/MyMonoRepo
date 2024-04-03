#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ponto.h"

struct Ponto {
  float x, y;
};

void FreePoint(Ponto* p) {
  free(p);
}

int GetPoint(Ponto* p, float* x, float* y) {
  if (p != NULL) {
    *x = p->x;
    *y = p->y;
    return 1;
  }
  return 0;
}

int SetPoint(Ponto* p, float x, float y) {
  if (p != NULL) {
    p->x = x;
    p->y = y;
    return 1;
  }
  return 0;
}

float DistanceAB(Ponto* pa, Ponto* pb) {
  if (pa == NULL || pb == NULL) return -1;
  return sqrt(pow(pa->x - pb->x, 2) + pow(pa->y - pb->y, 2));
}

Ponto* CreatePoint(float x, float y) {
  Ponto* p = (Ponto*)calloc(1, sizeof(Ponto));
  if (p != NULL) {
    p->x = x;
    p->y = y;
    return p;
  }
  printf("Could not create point\n");
  return p;
}
