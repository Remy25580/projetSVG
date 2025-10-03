#include <stdio.h>
#include <stdlib.h>
#include "projetsvg.h"

int main(void){
    printf("test de creation de fichier texte.\n");

    FILE *f = creatingFile("test.txt");
    
    return EXIT_SUCCESS;
}