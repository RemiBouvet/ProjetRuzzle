/**
 * \file pile_ptr.h
 * \brief Fichier qui contient tout les prototypes de pile_ptr.c
 * \author BOUVET Rémi & PRADERE-NIQUET Alexandre
 * \version 1.0
 * \date 15 novembre 2015
 */

#ifndef PILE_PTR
#define PILE_PTR

#define N 4

void initpile(void);

void CopierMatrice(char T1[N][N], char T2[N][N]);

//int pilevide(void);

void empiler(int x2, int y2, char chemin2[N][N]);

void depiler(int *x2, int *y2, char chemin2[N][N]);

#endif