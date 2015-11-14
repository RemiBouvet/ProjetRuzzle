#include <stdio.h>
#include "../include/structure.h"
#include "../include/couleur.h"
#define N 4

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

void afficher_liste(int compteur, t_score T[1000]){
    int i;
    for(i = compteur - 1; i >= 0; i--){
        printf("%s : %i points\n", T[i].mot, T[i].points);
	}
}
