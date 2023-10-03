#ifdef DEBUG
void PopulateVectorDebug(int*, int, int);
int* CreateVectorDebug(int, int);
#endif

void PopulateVector(int*, int);
int* CreateVector(int);
void ShowVector(int*, int, int, int);

#ifdef DEBUG
#define PopulateVector(A, B) PopulateVectorDebug(A, B, __LINE__)
#define CreateVector(A) CreateVectorDebug(A, __LINE__)
#endif
