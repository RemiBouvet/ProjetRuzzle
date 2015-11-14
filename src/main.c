#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "../include/pile_ptr.h"
#include "../include/structure.h"
#include "../include/affichage.h"
#include "../include/points.h"
#include "../include/generer.h"
#include "../include/traitement.h"


#define N 4


int main(void){
    t_case grille[N][N];
    t_score Liste[1000];
    int tailleListe;
    generation(grille);
    printf("\n\n\t  RUZZLE SOLVER\n");
    afficher_matrice(grille);
    trouverListe(grille);
    tri(Liste, &tailleListe);
    printf("Voici la liste des mots trouve dans la grille et leur nombre de points :\n");
    afficher_liste(tailleListe, Liste);
    return 0;
}
