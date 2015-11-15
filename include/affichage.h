/**
 * \file affichage.h
 * \brief Fichier qui contient tout les prototypes de affichage.c
 * \author BOUVET Rémi & PRADERE-NIQUET Alexandre
 * \version 1.0
 * \date 15 novembre 2015
 */

#ifndef AFFICHAGE
#define AFFICHAGE

#define N 4
void afficher_matrice(t_case grille[N][N]);
void afficher_bonus(t_case grille[N][N]);
void afficher_liste(int compteur, t_score T[1000]);

#endif