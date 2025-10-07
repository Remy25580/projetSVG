#include <stdio.h>
#include <stdlib.h>
#include "creation/creation.h"

int main(void){
    circle_t test = createCicrcle();
    getCircle(test);
    return EXIT_SUCCESS;
}