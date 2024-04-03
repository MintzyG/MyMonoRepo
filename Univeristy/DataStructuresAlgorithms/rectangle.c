#include "rectangle.h"

float computeArea(Rectangle *self) {
  return self->x * self->y;
}

void initRect(Rectangle* self, int x, int y){
  self->x = x;
  self->y = y;
}

Rectangle* constructRectEmpty() {
  Rectangle* rect = &(Rectangle) {
    .computeArea = computeArea,
    .initRect = initRect,
    .x = 0,
    .y = 0
  };
  return rect;
}

int MyX() {
  return 4;
}

Rectangle* ConstructRectFull(int x, int y) {
  Rectangle* rect = &(Rectangle) {
    .computeArea = computeArea,
    .initRect = initRect,
    .x = MyX(),
    .y = y
  };
  return rect;
}

