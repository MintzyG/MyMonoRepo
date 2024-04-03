#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

int main() {
  Rectangle* rect = ConstructRectFull(3, 6);
  printf("%f", rect->computeArea(rect));
  return 0;
}
