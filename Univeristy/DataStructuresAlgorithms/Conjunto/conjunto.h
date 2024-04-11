typedef struct Conjunto Conjunto;

struct Conjunto {
  int* numeros;

  int size, capacity;

  int smallest, biggest;

  void (*InsertElement)(Conjunto*, int);
  void (*RemoveElement)(Conjunto*, int);
  void (*ContainsElement)(Conjunto*, int);

  Conjunto* (*Union)(Conjunto*, Conjunto*);
  Conjunto* (*Intersection)(Conjunto*, Conjunto*);
  Conjunto* (*Difference)(Conjunto*, Conjunto*);

  int (*GetBiggest)(Conjunto*);
  int (*GetSmallest)(Conjunto*);
  void (*SetBiggest)(Conjunto*, int);
  void (*SetSmallest)(Conjunto*, int);

  int (*AssertEquals)(Conjunto*, Conjunto*);

  void (*Sort)(Conjunto*);
  void (*ShowElements)(Conjunto*);
};

void FreeConjunto(Conjunto*);
Conjunto* CreateConjunto();


