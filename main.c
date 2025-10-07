#include <stdio.h>
#include <stdlib.h>
#include "creation/creation.h"

int main(void){
    polyline_t test = createPolyline();
    getPolyline(test);
    return EXIT_SUCCESS;
}