/**
 * \file main.c
 * \brief Fichier qui contient la fonction main et donc les appels des fonctions principales.
 * \author BOUVET Rémi & PRADERE-NIQUET Alexandre
 * \version 1.0
 * \date 15 novembre 2015
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "../../include/pile_ptr.h"
#include "../../include/structure.h"
#include "../../include/affichage.h"
#include "../../include/points.h"
#include "../../include/generer.h"
#include "../../include/traitementtest.h"
#include "../../include/CUnit/CUnit.h"
#include "../../include/CUnit/Basic.h"
#include "../../include/CUnit/Automated.h"
#include "../../include/CUnit/Console.h"

#define N 4


/**
 * \fn int main(void)
 * \brief Fonction main.
 *
 * \param Ne prend pas de paramètres.
 * \return Retourne 0;
 */
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


    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();
    pSuite = CU_add_suite("Suite_1", 0, 0);
    if (!pSuite) { 
	CU_cleanup_registry();
	return CU_get_error(); }

    if (!CU_add_test(pSuite, "test of fprintf()", test_max)){
        CU_cleanup_registry();
    	return CU_get_error();
    }
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
    return 0;
}












