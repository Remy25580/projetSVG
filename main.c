#include <stdio.h>
#include <stdlib.h>
#include "creation/creation.h"
#include "creation/path.h"
#include "creation/userInterface.h"

int main(void){
    path_t pafpaf = createPath();
    getPath(pafpaf);
    return EXIT_SUCCESS;
}