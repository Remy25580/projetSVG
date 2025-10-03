#include <stdio.h>
#include <stdlib.h>
#include "projetsvg.h"


// Définitions de structures


// Définitions d'unions

typedef union{

} openedOrNot;

// Définitions d'énumérations

typedef enum oont{
    TYPEOPENED,
    TYPECLOSED
} openedOrNotType;


//Définitions de fonctions

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

int help(openedOrNotType s){
    switch(s){
        case TYPECLOSED:
        //fct exécutables quand un fichier est ouvert
        break;
        case TYPEOPENED:
        //fct exécutables quand un fichier n'est pas encore ouvert
        break;
    
    }

    return EXIT_SUCCESS;
}

void closeFile(FILE *name){
    fclose(name);
}

