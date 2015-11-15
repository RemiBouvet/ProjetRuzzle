/**
 * \file points.h
 * \brief Fichier qui contient tout les prototypes de points.c
 * \author BOUVET Rémi & PRADERE-NIQUET Alexandre
 * \version 1.0
 * \date 15 novembre 2015
 */

#ifndef POINTS
#define POINTS

#define N 4

int points_lettre(char lettre);
int points_lettre_bonus(t_case grille[N][N], char cheminMot[N][N]);
int points_longueur(char mot[40]);
void points_mot_bonus(int * nbPoints,t_case grille[N][N], char cheminMot[N][N]);
int calculPoint(t_case grille[N][N], char mot[40], char cheminMot[N][N]);

#endif