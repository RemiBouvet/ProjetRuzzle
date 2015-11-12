#include <stdio.h>
#include <string.h>
#include "../include/structure.h"
#define N 4


int points_lettre(char lettre){
    if(lettre == 'a') return 1;
    if(lettre == 'b') return 3;
    if(lettre == 'c') return 3;
    if(lettre == 'd') return 2;
    if(lettre == 'e') return 1;
    if(lettre == 'f') return 4;
    if(lettre == 'g') return 2;
    if(lettre == 'h') return 4;
    if(lettre == 'i') return 1;
    if(lettre == 'j') return 8;
    if(lettre == 'k') return 5;
    if(lettre == 'l') return 1;
    if(lettre == 'm') return 3;
    if(lettre == 'n') return 1;
    if(lettre == 'o') return 1;
    if(lettre == 'p') return 3;
    if(lettre == 'q') return 10;
    if(lettre == 'r') return 1;
    if(lettre == 's') return 1;
    if(lettre == 't') return 1;
    if(lettre == 'u') return 1;
    if(lettre == 'v') return 4;
    if(lettre == 'w') return 4;
    if(lettre == 'x') return 8;
    if(lettre == 'y') return 4;
    if(lettre == 'z') return 10; // A surveiller
}

int calculPoint(t_case grille[N][N], char motdico[40], int chemin[N][N]){
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
            if(grille[i][j].bonus == LettreDouble && chemin[i][j] != 0){
                nbPoints += points_lettre(chemin[i][j])*2;
            }
            else if(grille[i][j].bonus == LettreTriple && chemin[i][j] != 0){
                nbPoints += points_lettre(chemin[i][j])*3;
            }
            else{
                nbPoints += points_lettre(chemin[i][j]);
            }
        }
    }
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
                    if(grille[i][j].bonus == MotDouble && chemin[i][j] != 0){
                        nbPoints = nbPoints * 2;
                    }
                    else if(grille[i][j].bonus == MotTriple && chemin[i][j] != 0){
                        nbPoints = nbPoints * 3;
                    }
        }
    }
    return nbPoints;
}
