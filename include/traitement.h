/**
 * \file traitement.h
 * \brief Fichier qui contient tout les prototypes de traitement.c
 * \author BOUVET Rémi & PRADERE-NIQUET Alexandre
 * \version 1.0
 * \date 15 novembre 2015
 */

#ifndef TRAITEMENT
#define TRAITEMENT

#define N 4

int trouverchemin(t_case grille[N][N],char motdico[40],int i,int j, char chemin[N][N]);
int motpresent(t_case grille[N][N], char motdico[40], char chemin[N][N]);
void trouverListe(t_case grille[N][N]);
void tri(t_score T[1000], int * tailleListe);

#endif