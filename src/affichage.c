#include <stdio.h>
#include "../include/structure.h"
#define N 4

void afficher_matrice(t_case grille[N][N]){
    int i, j, k;
    for(i=0;i < N ; i++){
        printf("\t");
        for(k=0;k < N ; k++) printf("----");
        printf("\n\t|");
        for(j=0; j < N ; j++){
                printf(" %c |", grille[i][j].lettre);
        }
        printf("\n");
    }
    printf("\t");
    for(k=0;k < N ; k++) printf("----");
    printf("\n");
}

void afficher_bonus(t_case grille[N][N]){
    int i, j, k;
    for(i=0;i < N ; i++){
        printf("\t");
        for(k=0;k < N ; k++) printf("----");
        printf("\n\t|");
        for(j=0; j < N ; j++){
                printf(" %i |", grille[i][j].bonus);
        }
        printf("\n");
    }
    printf("\t");
    for(k=0;k < N ; k++) printf("----");
    printf("\n");
}

void afficher_liste(int compteur, t_score T[1000]){
    int i;
    for(i = compteur - 1; i >= 0; i--){
        printf("%s : %i points\n", T[i].mot, T[i].points);
	}
}
