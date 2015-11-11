#ifndef PILE_PTR_H_INCLUDED
#define PILE_PTR_H_INCLUDED



#endif // PILE_PTR_H_INCLUDED

typedef struct element{int x; int y; int chemin[4][4]; struct element* suivant;} t_element;

void initpile(void);

//int pilevide(void);

void empiler(int x2, int y2, int chemin2[4][4]);

void depiler(int *x2, int *y2, int chemin2[4][4]);

