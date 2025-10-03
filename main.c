#include <stdio.h>
#include <stdlib.h>
#include "sources_h/creation.h"

int main(void){
    rectangle_t test = createRectangle();
    getRectangle(test);
    return EXIT_SUCCESS;
}