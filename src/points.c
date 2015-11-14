#include <stdio.h>
#include <string.h>
#include "../include/structure.h"
#define N 4


int points_lettre(char lettre){
    int points = 0;
    if(lettre == 'a') points =  1;
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

int calculPoint(t_case grille[N][N], char motdico[40], char chemin[N][N]){
    int nbPoints = 0;
    int length = strlen(motdico);
    if (length == 5){
        nbPoints += 5;
    }
    else if (length == 6){
        nbPoints += 10;
    }
    else if (length == 7){
        nbPoints += 15;
    }
    else if (length == 8){
        nbPoints += 20;
    }
    else if (length > 8){
        nbPoints += 25;
    }
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(grille[i][j].bonus == LettreDouble && chemin[i][j] != '0'){
                nbPoints += points_lettre(chemin[i][j])*2;
            }
            else if(grille[i][j].bonus == LettreTriple && chemin[i][j] != '0'){
                nbPoints += points_lettre(chemin[i][j])*3;
            }
            else{
                nbPoints += points_lettre(chemin[i][j]);
            }
        }
    }
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
                    if(grille[i][j].bonus == MotDouble && chemin[i][j] != '0'){
                        nbPoints = nbPoints * 2;
                    }
                    else if(grille[i][j].bonus == MotTriple && chemin[i][j] != '0'){
                        nbPoints = nbPoints * 3;
                    }
        }
    }
    return nbPoints;
}
