#include <stdio.h>
#include <stdlib.h>
#include "creation/creation.h"
#include "creation/path.h"

int main(void){
    rectangle_t test = createRectangle();
    getRectangle(test);
    return EXIT_SUCCESS;
}