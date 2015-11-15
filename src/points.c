/**
 * \file points.c
 * \brief Fichier qui contient toutes les fonctions qui comptent le nombre de point d'un mot.
 * \author BOUVET Rémi & PRADERE-NIQUET Alexandre
 * \version 1.0
 * \date 15 novembre 2015
 */

#include <stdio.h>
#include <string.h>
#include "../include/structure.h"
#define N 4

/**
 * \fn int points_lettre(char lettre)
 * \brief Fonction qui permet de connaitre le nombre de point initial d'une lettre.
 *
 * \param Prend un caractère en paramètre.
 * \return Retourne le nombre de point associé à la lettre.
 */
int points_lettre(char lettre){
    int points = 0;
    if(lettre == 'a') points = 1;
    if(lettre == 'b') points = 3;
    if(lettre == 'c') points = 3;
    if(lettre == 'd') points = 2;
    if(lettre == 'e') points = 1;
    if(lettre == 'f') points = 4;
    if(lettre == 'g') points = 2;
    if(lettre == 'h') points = 4;
    if(lettre == 'i') points = 1;
    if(lettre == 'j') points = 8;
    if(lettre == 'k') points = 5;
    if(lettre == 'l') points = 1;
    if(lettre == 'm') points = 3;
    if(lettre == 'n') points = 1;
    if(lettre == 'o') points = 1;
    if(lettre == 'p') points = 3;
    if(lettre == 'q') points = 10;
    if(lettre == 'r') points = 1;
    if(lettre == 's') points = 1;
    if(lettre == 't') points = 1;
    if(lettre == 'u') points = 1;
    if(lettre == 'v') points = 4;
    if(lettre == 'w') points = 4;
    if(lettre == 'x') points = 8;
    if(lettre == 'y') points = 4;
    if(lettre == 'z') points = 10;
    return points;
}

/**
 * \fn int points_lettre_bonus(t_case grille[N][N], char cheminMot[N][N])
 * \brief Fonction qui permet de calculer le nombre de point de chaque lettre et de leur bonus associé.
 *
 * \param Prend en paramètre la grille et le chemin associé.
 * \return Retourne le nombre de point associé aux lettres du mot.
 *
 * La fonction parcour le chemin affin d'attribuer les points adaptés quand nous rencontrons une lettre dans chemin mais nous vérifions également si il n'y a pas un bonus lié à la lettre.
 *
 */
int points_lettre_bonus(t_case grille[N][N], char cheminMot[N][N]){
    int points = 0;
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(grille[i][j].bonus == LettreDouble && cheminMot[i][j] != '0'){
                points += points_lettre(cheminMot[i][j])*2;
                printf("LettreDouble");
            }
            else if(grille[i][j].bonus == LettreTriple && cheminMot[i][j] != '0'){
                points += points_lettre(cheminMot[i][j])*3;
                printf("LettreTriple");
            }
            else{
                points += points_lettre(cheminMot[i][j]);
            }
        }
    }
    return points;
}

/**
 * \fn int points_longueur(char mot[40])
 * \brief Fonction qui permet de calculer nombre de points associé à la longueur du mot.
 *
 * \param Prend en paramètre un mot.
 * \return Retourne le nombre de point de la longueur du mot.
 */
int points_longueur(char mot[40]){
    int points = 0;
    int length = strlen(mot);
    if (length == 5){
        points += 5;
    }
    else if (length == 6){
        points += 10;
    }
    else if (length == 7){
        points += 15;
    }
    else if (length == 8){
        points += 20;
    }
    else if (length > 8){
        points += 25;
    }
    return points;
}

/**
 * \fn void points_mot_bonus(int * nbPoints,t_case grille[N][N], char cheminMot[N][N])
 * \brief Fonction qui permet de calculer le bonus au niveau du mot.
 *
 * \param Prend en paramètre la grille du jeu, le chemin associé et un pointeur sur une varible points.
 * \return Ne retourne rien.
 *
 * La fonction est similaire à points_lettre_bonus mais elle gère les bonus lié au mot.
 *
 */
void points_mot_bonus(int * nbPoints,t_case grille[N][N], char cheminMot[N][N]){
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(grille[i][j].bonus == MotDouble && cheminMot[i][j] != '0'){
                *nbPoints = *nbPoints * 2;
                printf("Motdouble");
            }
            else if(grille[i][j].bonus == MotTriple && cheminMot[i][j] != '0'){
                printf("Mottriple");
               *nbPoints = *nbPoints * 3;
            }
        }
    }
}
/**
 * \fn int calculPoint(t_case grille[N][N], char motdico[40], char cheminMot[N][N])
 * \brief Fonction qui permet de calculer le nombre total de point d'un mot en prenant en compte sa longueur et ses bonus.
 *
 * \param Prend en paramètre la grille du jeu, le mot présent dans la grille et son chemin associé.
 * \return Retourne le nombre de point associé au mot.
 */
int calculPoint(t_case grille[N][N], char mot[40], char cheminMot[N][N]){
    int nbPoints = 0;
    nbPoints += points_longueur(mot);
    printf("\nlongueur : %i", nbPoints);
    nbPoints += points_lettre_bonus(grille, cheminMot);
    printf("\nlettre : %i\n", nbPoints);
    points_mot_bonus(&nbPoints, grille, cheminMot);
    return nbPoints;
}
