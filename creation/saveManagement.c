#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"
#include "deletion.h"
#include "color.h"
#include "saveManagement.h"

void saveShapes(shapeGroup_t *s){
    char fileNametext[20];
    char fileNameSvg[20];
    int choice = 2;
    int valid = 0;

    while(choice != 0 || choice != 1){
        printf("Are you sure you want to save now ? 0 for no, 1 for yes\n");
        scanf("%d", &choice);
        if(choice == 0){
            break;
        }
    }

    if(choice == 1){
        while(valid == 0){
            printf("How do you want to name your save files ?\n");
            printf("The text file : ");
            scanf("%19s", fileNametext);
            printf("The svg file : ");
            scanf("%19s", fileNameSvg);

            if(strstr(fileNametext, ".") != NULL || strstr(fileNameSvg, ".") != NULL){
                printf("Invalid file name, you must not put a dot.\n");
            }
            else{
                valid = 1;
            }
        }
        strcat(fileNametext, ".txt");
        strcar(fileNameSvg, ".svg");

        FILE *ft = fopen(fileNametext, "w");
        FILE *fs = fopen(fileNameSvg, "w");

    }
}