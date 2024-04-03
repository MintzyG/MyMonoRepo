typedef struct Ponto Ponto;



void FreePoint(Ponto* p);
int SetPoint(Ponto* p, float x, float y);
int GetPoint(Ponto* p, float* x, float* y);
Ponto* CreatePoint(float x, float y);
float DistanceAB(Ponto* pa, Ponto* pb);
