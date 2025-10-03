#include <stdio.h>
#include <stdlib.h>
#include "creation.h"

int main(void){
    rectangle_t test = createRectangle();
    getRectangle(test);
    return EXIT_SUCCESS;
}