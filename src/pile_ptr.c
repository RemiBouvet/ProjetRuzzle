#include <stdlib.h>
#include <string.h>
#include "../include/structure.h"
#define N 4

t_element *pile;

void initpile(void){
	pile = 	NULL;
}

/*int pilevide(void){
	return (pile == NULL);
}*/

void CopierMatrice(int T1[N][N], int T2[N][N]){
	int i, j;
	for(i=0; i < N; i++){
		for(j=0; j < N; j++){
			T1[i][j] = T2[i][j];		
		}
	}
}

void empiler(int x2, int y2, int chemin2[N][N]){
	t_element* nouv;

	nouv = (t_element*)malloc(sizeof(t_element));
	nouv->x = x2;
	nouv->y = y2;
	CopierMatrice(nouv->chemin, chemin2);
	nouv->suivant = pile;
	pile = nouv;
}

void depiler(int *x2, int *y2, int chemin2[N][N]){
	t_element* sommet;

	if(pile!=NULL){
		*x2 = pile->x;
		*y2 = pile->y;
		CopierMatrice(chemin2,pile->chemin);
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
