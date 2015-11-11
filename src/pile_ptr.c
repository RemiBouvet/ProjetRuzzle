#include <stdlib.h>
#include <string.h>
#define N 4

typedef struct element{int x; int y; int chemin[N][N]; struct element* suivant;} t_element;
t_element* pile;

void initpile(void){
	pile = 	NULL;
}

/*int pilevide(void){
	return (pile == NULL);
}*/

void empiler(int x2, int y2, int chemin2[N][N]){
	t_element* nouv;

	nouv = (t_element*)malloc(sizeof(t_element));
	nouv->x = x2;
	nouv->y = y2;
	memcpy(nouv->chemin,chemin2,sizeof(int)*sizeof(&chemin2)*16);//trouver la taille d'une matrice en mémoire
	nouv->suivant = pile;
	pile = nouv;
}

void depiler(int *x2, int *y2, int chemin2[N][N]){
	t_element* sommet;

	if(pile!=NULL){
		*x2 = pile->x;
		*y2 = pile->y;
		memcpy(chemin2,pile->chemin,sizeof(int)*sizeof(&chemin2)*16);//trouver la taille d'une matrice en mémoire
		sommet = pile;
		pile = sommet->suivant;
		free(sommet);
	}
}

/*char sommetpile(void){
	if(pile!=NULL){
		return (pile->c);
	}
}*/
