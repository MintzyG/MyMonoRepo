typedef struct Rectangle Rectangle;

struct Rectangle {
  float x, y;

  float (*computeArea)(Rectangle *self);
  void (*initRect)(Rectangle* self, int x, int y);
};

float computeArea(Rectangle *self);
void initRect(Rectangle* self, int x, int y);

Rectangle* constructRectEmpty();
Rectangle* ConstructRectFull(int x, int y);
