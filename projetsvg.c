#include <stdio.h>
#include <stdlib.h>
#include "projetsvg.h"


// Définitions de structures
typedef struct rectangle_s{
    int height;
    int width;
    int xpos;
    int ypos;
} renctange_t;

// Définitions d'unions


// Définitions d'énumérations



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

renctange_t createRectangle(void){
    renctange_t r;
    printf("You are now creating a rectangle.\n");
    printf("What's the x position where starts your rectangle ?\n");
    int x;
    scanf("%d", x);
    print("Great! Now what's the y postition where starts your rectangle ?\n");
    int y;
    scanf("%d", y);
    printf("And now, what will be the height of your rectangle ?\n");
    int h;
    scanf("%d", h);
    printf("And what will be the width of your rectangle ?\n");
    int w;
    scanf("%d", w);
    printf("Your rectangle is now made! \n");
    return r;

}

void getRectangle(renctange_t r){
    printf("Here's your rectangle: \n");
    printf("\n");
    printf("\t Start postition : %d,%d\n", r.xpos, r.ypos);
    printf("\t Height : %d  Width : %d\n", r.height, r.width);
    printf("\n");
}