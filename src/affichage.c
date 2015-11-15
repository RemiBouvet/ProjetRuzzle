/**
 * \file affichage.c
 * \brief Fichier qui contient les fonctions qui permettent de réaliser de l'affichage.
 * \author BOUVET Rémi & PRADERE-NIQUET Alexandre
 * \version 1.0
 * \date 15 novembre 2015
 */
#include <stdio.h>
#include "../include/structure.h"
#include "../include/couleur.h"
#define N 4

/**
 * \fn void afficher_matrice(t_case grille[N][N])
 * \brief Fonction qui permet d'afficher la grille et sa légende.
 *
 * \param Prend en paramètre la grille.
 * \return Ne retourne rien.
 */
void afficher_matrice(t_case grille[N][N]){
    couleur(0);
    int i, j, k;
    for(i=0;i < N ; i++){
        printf("\t");
        for(k=0;k < N ; k++) printf("----");
        printf("-\n\t|");
        for(j=0; j < N ; j++){
		if(grille[i][j].bonus == LettreDouble){
			couleur(41);
		}
		else if(grille[i][j].bonus == LettreTriple){
			couleur(42);
		}
		else if(grille[i][j].bonus == MotDouble){
			couleur(43);
		}
		else if(grille[i][j].bonus == MotTriple){
			couleur(44);
		}
		printf(" %c ", grille[i][j].lettre);
		couleur(0);
		printf("|");
        }
        printf("\n");
    }
    printf("\t");
    for(k=0;k < N ; k++) printf("----");
    printf("\n\n");
    printf("Chaque couleur de case fait reference a un bonus :\n");
    couleur(41);
    printf("Lettre compte double");
    couleur(0);
    printf("\n");
    couleur(42);
    printf("Lettre compte triple");
    couleur(0);
    printf("\n");
    couleur(43);
    printf("Mot compte double");
    couleur(0);
    printf("\n");
    couleur(44);
    printf("Mot compte triple");
    couleur(0);
    printf("\n\n");
}

/**
 * \fn void afficher_liste(int compteur, t_score T[1000])
 * \brief Fonction qui permet d'afficher la liste des mots trié en fonction de leur score.
 *
 * \param Prend en paramètre le nombre de mot et le tableau des mots et des scores.
 * \return Ne retourne rien.
 */
void afficher_liste(int nbmot, t_score T[1000]){
    int i;
    for(i = nbmot - 1; i >= 0; i--){
        printf("%s : %i points\n", T[i].mot, T[i].points);
	}
}
