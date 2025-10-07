#include <stdio.h>
#include <stdlib.h>
#include "creation/creation.h"

int main(void){
    polygon_t test = createPolygon();
    getPolygon(test);
    return EXIT_SUCCESS;
}