#include <stdio.h>
#include <stdlib.h>
#include "creation/creation.h"

int main(void){
    line_t test = createLine();
    getLine(test);
    return EXIT_SUCCESS;
}