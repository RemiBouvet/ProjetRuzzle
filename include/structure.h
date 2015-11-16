/**
 * \file structure.h
 * \brief Fichier qui contient toutes les structures et énumération.
 * \author BOUVET Rémi & PRADERE-NIQUET Alexandre
 * \version 1.0
 * \date 15 novembre 2015
 */

#ifndef STRUCTURE
#define STRUCTURE

#define N 4

/**
 * \enum t_bonus
 * \brief Cette enumération permet de définir plus facilement les bonus.
 */
enum t_bonus {aucun, LettreDouble, LettreTriple, MotDouble, MotTriple};

/**
 * \struct t_case structure.h Structure
 * \brief Definition d'une case qui est une lettre avec son bonus qui lui est associé.
 */
typedef struct {int lettre; enum t_bonus bonus;} t_case;

/**
 * \struct t_score structure.h Structure
 * \brief Definition d'une structure qui permet de rassembler le mot et son nombre de point.
 */
typedef struct {char mot[20]; int points;} t_score;

/**
 * \struct element structure.h Structure
 * \brief Definition de la structure de la pile qui contient des coordonnées x,y, la matrice chemin qui indique le chemin par lequel on est déjà passé, la matrice cheminMot qui contient les lettres du mot dans une matrice vide et le pointeur sur l'élement suivant.
 */
typedef struct element{int x; int y; int chemin[N][N]; char cheminMot[N][N]; struct element* suivant;} t_element;

#endif
