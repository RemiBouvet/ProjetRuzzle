/**
 * \file generer.c
 * \brief Fichier qui contient les fonctions qui permettent generer la grille.
 * \author BOUVET Rémi & PRADERE-NIQUET Alexandre
 * \version 1.0
 * \date 15 novembre 2015
 */
#include <stdlib.h>
#include <time.h>
#include "../include/structure.h"

#define N 4


/**
 * \fn int rand_a_b(int a, int b)
 * \brief Fonction qui permet de générer un nombre aléatoire.
 *
 * \param Prend en paramètre deux entier qui permettent de définir les bornes du nombre aléatoire généré avec [a;b[ .
 * \return Retourne le nombre aléatoire.
 */
int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

/**
 * \fn void generation(t_case grille[N][N])
 * \brief Fonction qui permet de générer la grille de caractère ainsi que les bonus qui lui son associé.
 *
 * \param Prend en paramètre la grille.
 * \return Ne retourne rien.
 */
void generation(t_case grille[N][N]){
    int i, j;
    srand(time(NULL));
    char voyelle[6] ={'a', 'e', 'i', 'o', 'u', 'y'};
    char consonne[20] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};
    for(i=0;i < N ; i++){
        for(j=0; j < N ; j++){
            if (rand_a_b(0, 2)){
                grille[i][j].lettre= consonne[rand_a_b(0, 20)];
            }
            else {
                grille[i][j].lettre= voyelle[rand_a_b(0, 6)];
            }
            grille[i][j].bonus= aucun;
        }
    }
    grille[rand_a_b(0,4)][rand_a_b(0,4)].bonus = LettreDouble;
    grille[rand_a_b(0,4)][rand_a_b(0,4)].bonus = LettreTriple;
    grille[rand_a_b(0,4)][rand_a_b(0,4)].bonus = MotDouble;
    grille[rand_a_b(0,4)][rand_a_b(0,4)].bonus = MotTriple;
}

