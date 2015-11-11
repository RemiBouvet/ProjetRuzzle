#ifndef PILE_PTR_H_INCLUDED
#define PILE_PTR_H_INCLUDED

#define N 4

#endif // PILE_PTR_H_INCLUDED

void initpile(void);

void CopierMatrice(int T1[N][N], int T2[N][N]);

//int pilevide(void);

void empiler(int x2, int y2, int chemin2[4][4]);

void depiler(int *x2, int *y2, int chemin2[4][4]);

