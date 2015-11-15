/**
 * \file traitement.c
 * \brief Fichier qui contient toutes les fonctions qui traitent la grille.
 * \author BOUVET Rémi & PRADERE-NIQUET Alexandre
 * \version 1.0
 * \date 15 novembre 2015
 */
#include <stdio.h>
#include <string.h>
#include "../include/structure.h"
#include "../include/pile_ptr.h"
#include "../include/points.h"

#define N 4

/**
 * \fn int trouverchemin(t_case grille[N][N],char motdico[40],int i,int j, char chemin[N][N])
 * \brief Fonction qui permet de parcourir tous les chemins de la matrice à partir d'une case et qui calcul le chemin associé si le mot est présent.
 *
 * \param Prend en paramètre la grille, le mot à trouver, les coordonnées i,j à partir desquels il faut trouver un chemin et la matrice chemin.
 * \return Retourne 1 si le mot est présent sinon retourne 0.
 */
int trouverchemin(t_case grille[N][N],char motdico[40],int i,int j, int chemin[N][N], char cheminMot[N][N]){
    char chaine[40];
    int k, l;
    int n = 1;
    int x, y, xPrec, yPrec;
    for(k=0; k<N; k++){
            for(l=0; l<N; l++){
                chemin[k][l] = 0;
                cheminMot[k][l] = '0';
            }
        }
        initpile();
        x = i;
        y = j;
        xPrec = x;
        yPrec = y;
        chemin[x][y] = 1;
        empiler(i, j, chemin, cheminMot);
        while(n > 0){
            if((y + 1) <= 3 && (chemin[x][y + 1] == 0)&& motdico[n] == grille[x][y + 1].lettre){
                y = y + 1;
                chemin[x][y] = 1;
                cheminMot[xPrec][yPrec] = grille[x][y].lettre;
                empiler(i, j, chemin, cheminMot);
                strcpy(chaine,motdico);
                n++;
                chaine[n] = '\0';
            }
            else if((x + 1) <= 3 && (y + 1) <= 3 && (chemin[x + 1][y + 1] == 0) && motdico[n] == grille[x + 1][y + 1].lettre){
                x = x + 1;
                y = y + 1;
                chemin[x][y] = 1;
                cheminMot[xPrec][yPrec] = grille[x][y].lettre;
                empiler(i, j, chemin, cheminMot);
                strcpy(chaine,motdico);
                n++;
                chaine[n] = '\0';
            }
            else if((x + 1) <= 3 && (chemin[x + 1][y] == 0) && motdico[n] == grille[x + 1][y].lettre){
                x = x + 1;
                chemin[x][y] = 1;
                cheminMot[xPrec][yPrec] = grille[x][y].lettre;
                empiler(i, j, chemin, cheminMot);
                strcpy(chaine,motdico);
                n++;
                chaine[n] = '\0';
            }
            else if((x + 1) <= 3 && (y - 1) >= 0 && (chemin[x + 1][y - 1] == 0) && motdico[n] == grille[x + 1][y - 1].lettre){
                x = x + 1;
                y = y - 1;
                chemin[x][y] = 1;
                cheminMot[xPrec][yPrec] = grille[x][y].lettre;
                empiler(i, j, chemin, cheminMot);
                strcpy(chaine,motdico);
                n++;
                chaine[n] = '\0';
            }
            else if((y - 1) >= 0 && (chemin[x][y - 1] == 0)&& motdico[n] == grille[x][y - 1].lettre){
                y = y - 1;
                chemin[x][y] = 1;
                cheminMot[xPrec][yPrec] = grille[x][y].lettre;
                empiler(i, j, chemin, cheminMot);
                strcpy(chaine,motdico);
                n++;
                chaine[n] = '\0';
            }
            else if((x - 1) >= 0 && (y - 1) >= 0 && (chemin[x - 1][y - 1] == 0) && motdico[n] == grille[x - 1][y - 1].lettre){
                x = x - 1;
                y = y - 1;
                chemin[x][y] = 1;
                cheminMot[xPrec][yPrec] = grille[x][y].lettre;
                empiler(i, j, chemin, cheminMot);
                strcpy(chaine,motdico);
                n++;
                chaine[n] = '\0';
            }
            else if((x - 1) >= 0 && (chemin[x - 1][y] == 0) && motdico[n] == grille[x - 1][y].lettre){
                x = x - 1;
                chemin[x][y] = 1;
                cheminMot[xPrec][yPrec] = grille[x][y].lettre;
                empiler(i, j, chemin, cheminMot);
                strcpy(chaine,motdico);
                n++;
                chaine[n] = '\0';
            }
            else if((x - 1) >= 0 && (y + 1) <= 3 && (chemin[x - 1][y + 1] == 0) && motdico[n] == grille[x - 1][y + 1].lettre){
                x = x - 1;
                y = y + 1;
                chemin[x][y] = 1;
                cheminMot[xPrec][yPrec] = grille[x][y].lettre;
                empiler(i, j, chemin, cheminMot);
                strcpy(chaine,motdico);
                n++;
                chaine[n] = '\0';
            }
            else {
                depiler(&x, &y, chemin, cheminMot);
                n--;
            }
            if(strcmp(motdico,chaine) == 0 && strlen(motdico) > 2){
                cheminMot[x][y] = grille[x][y].lettre;
                return 1;
            }
        xPrec = x;
        yPrec = y;
        }
    return 0;
}

/**
 * \fn int motpresent(t_case grille[N][N], char motdico[40], char chemin[N][N])
 * \brief Fonction qui permet de determiner si un mot est présent dans la matrice et de calculer son chemin.
 *
 * \param Prend en paramètre la grille, le mot à trouver et la matrice chemin.
 * \return Retourne 1 si le mot est présent sinon retourne 0.
 *
 * Avec cette fonction nous allons parcourir toute les cases de la grille ce qui aura pour conséquence de changer le point du départ du chemin.
 *
 */
int motpresent(t_case grille[N][N], char motdico[40], int chemin[N][N], char cheminMot[N][N]){
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(motdico[0] == grille[i][j].lettre){
                if(trouverchemin(grille, motdico, i, j, chemin, cheminMot)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

/**
 * \fn void trouverListe(t_case grille[N][N])
 * \brief Fonction qui enregistre dans un fichier temporaire tous les mots présents dans la matrice ainsi que leurs points associés.
 *
 * \param Prend en paramètre la grille.
 * \return Ne retourne rien.
 */
void trouverListe(t_case grille[N][N]){
    char motdico[40];
    int chemin[N][N];
    char cheminMot[N][N];
    int nbPoints;
    FILE * dico = NULL;
    dico = fopen("dico.txt","r");
    FILE * liste = NULL;
    liste = fopen("liste.txt","w");
    if(dico == NULL){   //Permet d'executer notre programme depuis le répertoire précédent sinon le dictionnaire n'est pas trouvé à l'execution.
        dico = fopen("bin/dico.txt","r");
    }
    while(!feof(dico)){     //Pour chaque mot du dictionnaire nous regardons si il se trouve dans la grille dans le cas où il est présent nous récupérons sa matrice chemin qui contient uniquement les lettres du mot dans la matrice.
        fscanf(dico,"%s", motdico);
        if (motpresent(grille, motdico, chemin, cheminMot)){
            nbPoints = calculPoint(grille, motdico, cheminMot);    //Calcul du nombre de point associé au mot.
            printf("%s %i\n", motdico, nbPoints);
            fprintf(liste, "%s %i\n", motdico, nbPoints);   //Nous sauvegardons tous les mots et leur points correspondant dans un fichier qui n'est pas encore trié.
        }
    }
    fclose(dico);
    fclose(liste);
}

/**
 * void tri(t_score T[1000], int * tailleListe)
 * \brief Fonction qui récupère tous les mots et leurs points correspondant pour les trier.
 *
 * \param Prend en paramètre le tableau qui stocke les mots et leurs points associés ainsi que un pointeur sur le nombre de mot.
 * \return Ne retourne rien.
 */
void tri(t_score T[1000], int * tailleListe){
    char mot[20];
    int nbPoints, compteur = 0;
    FILE * liste;
    liste = fopen("liste.txt","r");
    while(!feof(liste)){    //Nous récupèrons les mots et nombre de points non trié dans le fichier pour le stocker dans un tableau que l'on pourra lui, trier.
        fscanf(liste,"%s %i", mot, &nbPoints);
        strcpy(T[compteur].mot, mot);
        T[compteur].points = nbPoints;
        compteur++;
    }
	int i, j;
	for(i=0; i < compteur ; i++){  //Nous utilisons un tri bulle pour trier nos données.
		for(j = compteur-1; j > i ; j--){
			if (T[j-1].points > T[j].points){
				nbPoints = T[j].points;
				strcpy(mot, T[j].mot);
				T[j].points = T[j - 1].points;
				strcpy(T[j].mot, T[j - 1].mot);
				T[j - 1].points = nbPoints;
				strcpy(T[j - 1].mot, mot);
			}
		}
	}
	*tailleListe = compteur;
	fclose(liste);
	remove("liste.txt");   //Nous avons fait le choix de supprimer le fichier à la fin du tri.
}