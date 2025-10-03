#include <stdio.h>
#include <stdlib.h>
#include "creation/creation.h"

int main(void){
    carre_t test = createSquare();
    getSquare(test);
    return EXIT_SUCCESS;
}