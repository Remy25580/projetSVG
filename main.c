#include <stdio.h>
#include <stdlib.h>
#include "creation/creation.h"
#include "creation/path.h"

int main(void){
    path_t test = createPath();
    getPath(test);
    return EXIT_SUCCESS;
}