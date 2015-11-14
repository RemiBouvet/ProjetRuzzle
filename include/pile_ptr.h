#ifndef PILE_PTR_H_INCLUDED
#define PILE_PTR_H_INCLUDED

#define N 4

#endif // PILE_PTR_H_INCLUDED

void initpile(void);

void CopierMatrice(char T1[N][N], char T2[N][N]);

//int pilevide(void);

void empiler(int x2, int y2, char chemin2[N][N]);

void depiler(int *x2, int *y2, char chemin2[N][N]);

