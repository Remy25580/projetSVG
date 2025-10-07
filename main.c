#include <stdio.h>
#include <stdlib.h>
#include "creation/creation.h"

int main(void){
    ellipse_t test = createEllipse();
    getEllipse(test);
    return EXIT_SUCCESS;
}