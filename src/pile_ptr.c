/**
 * \file pile_ptr.c
 * \brief Fichier qui contient les primitives d'accès à la pile.
 * \author BOUVET Rémi & PRADERE-NIQUET Alexandre
 * \version 1.0
 * \date 15 novembre 2015
 */



#include <stdlib.h>
#include <string.h>
#include "../include/structure.h"
#define N 4

t_element *pile;


/**
 * \fn void initpile(void)
 * \brief Fonction qui initialise la pile.
 *
 * \param Aucun paramètre.
 * \return Ne retourne rien.
 */
void initpile(void){
	pile = 	NULL;
}

/**
 * \fn void CopierMatrice(char T1[N][N], char T2[N][N])
 * \brief Fonction qui copie une matrice de caractère dans une autre.
 *
 * \param Il y a deux mattrice de caractère en paramètre : T2 qui se copie dans T1.
 * \return Ne retourne rien.
 */
void CopierMatrice(int t1[N][N], int t2[N][N]){
	int i, j;
	for(i=0; i < N; i++){
		for(j=0; j < N; j++){
			t1[i][j] = t2[i][j];		
		}
	}
}

void CopierMatriceChar(char T1[N][N], char T2[N][N]){
	int i, j;
	for(i=0; i < N; i++){
		for(j=0; j < N; j++){
			T1[i][j] = T2[i][j];		
		}
	}
}

/**
 * \fn void empiler(int x2, int y2, char chemin2[N][N])
 * \brief Fonction qui ajoute un élément à notre pile.
 *
 * \param Prend en paramètre deux coordonnées x2 et y2 et également la matrice de caractère chemin2.
 * \return Ne retourne rien.
 */

void empiler(int x2, int y2, int chemin2[N][N], char cheminMot2[N][N]){
	t_element* nouv;

	nouv = (t_element*)malloc(sizeof(t_element));
	nouv->x = x2;
	nouv->y = y2;
	CopierMatrice(nouv->chemin, chemin2);
	CopierMatriceChar(nouv->cheminMot, cheminMot2);
	nouv->suivant = pile;
	pile = nouv;
}

/**
 * \fn void depiler(int *x2, int *y2, char chemin2[N][N])
 * \brief Fonction qui permet de retirer un élément de la pile et d'attribuer sa valeur aux élément placés en paramètre.
 *
 * \param Elle prend en paramètre les pointeurs *x2, *y2 et chemin2.
 * \return Ne retourne rien.
 */
void depiler(int *x2, int *y2, int chemin2[N][N], char cheminMot2[N][N]){
	t_element* sommet;

	if(pile!=NULL){
		*x2 = pile->x;
		*y2 = pile->y;
		CopierMatrice(chemin2,pile->chemin);
		CopierMatriceChar(cheminMot2,pile->cheminMot);
		sommet = pile;
		pile = sommet->suivant;
		free(sommet);
	}
}
