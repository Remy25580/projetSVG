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
    shapesElt *current;
    int existStyle;

    while(choice != 0 || choice != 1){
        printf("Are you sure you want to save now ? 0 for no, 1 for yes\n");
        scanf("%d", &choice);
        if(choice == 0){
            break;
        }
    }

    if(choice == 1){
        while(valid == 0){
            printf("How do you want to name your save file ?\n");
            printf("The text file : ");
            scanf("%19s", fileNametext);

            if(strstr(fileNametext, ".") != NULL){
                printf("Invalid file name, you must not put a dot.\n");
            }
            else{
                valid = 1;
            }
        }
        strcat(fileNametext, ".txt");
        FILE *ft = fopen(fileNametext, "w");

        current = s->head;

        while(current != NULL){
            fprintf(ft, "%s\n", current->name);
            existStyle = 0;
            switch(current->shpType){
                case(RECTANGLETYPE):
                    fprintf(ft, "RECTANGLETYPE\n");
                    fprintf(ft, "%f\n", current->shp.rectangle->xpos);
                    fprintf(ft, "%f\n", current->shp.rectangle->ypos);
                    fprintf(ft, "%f\n", current->shp.rectangle->height);
                    fprintf(ft, "%f\n", current->shp.rectangle->width);
                    fprintf(ft, "%f\n", current->shp.rectangle->xradius);
                    fprintf(ft, "%f\n", current->shp.rectangle->yradius);
                    if(current->style != NULL){
                        fprintf(ft, "1\n");
                        existStyle = 1;
                    }
                    else{
                        fprintf(ft, "0\n");
                    }
                    break;
                case(SQUARETYPE):
                    break;
                case(CIRCLETYPE):
                    break;
                case(ELLIPSETYPE):
                    break;
                case(LINETYPE):
                    break;
                case(POLYLINETYPE):
                    break;
                case(POLYGONTYPE):
                    break;
                case(PATHTYPE):
                    break;
                case(GROUPTYPE):
                    break;
                default:
                    break;
            }
            if(existStyle == 1){
                fprintf(ft, "%s\n", current->style->color);
                fprintf(ft, "%s\n", current->style->fillColor);
                fprintf(ft, "%f\n", current->style->rotate);
            }
            fprintf(ft, "\n");
            current = current->next;
        }
    }
}