/**
 * \file traitementtest.h
 * \brief Fichier qui contient tout les prototypes de traitementtest.c
 * \author BOUVET Rémi & PRADERE-NIQUET Alexandre
 * \version 1.0
 * \date 15 novembre 2015
 */

#ifndef TRAITEMENT
#define TRAITEMENT

#define N 4
void test_max(void);
int trouverchemin(t_case grille[N][N],char motdico[40],int i,int j, int chemin[N][N], char cheminMot[N][N]);
int motpresent(t_case grille[N][N], char motdico[40], int chemin[N][N], char cheminMot[N][N]);
int trouverListe(t_case grille[N][N]);
void tri(t_score T[1000], int * tailleListe);

#endif
