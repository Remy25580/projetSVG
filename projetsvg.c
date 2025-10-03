#include <stdio.h>
#include <stdlib.h>
#include "projetsvg.h"

FILE *creatingFile(char *name){
    FILE *pointeur = fopen(name, "w");

    if (pointeur == NULL){
        printf("Impossible de creer le fichier\n");
        return NULL;
    }
    else{
        printf("Fichier cree avec succes!\n");
        return pointeur;
    }
}

FILE *openingFile(char *name){
    FILE *pointeur = fopen(name, "w");

    if (pointeur == NULL){
        printf("Le fichier n'a pas ete trouve.\n");
        return NULL;
    }
    else{
        printf("Le fichier a ete ouvert avec succès! \n");
        return pointeur;
    }
    
}

void closeFile(FILE *name){
    fclose(name);
}
