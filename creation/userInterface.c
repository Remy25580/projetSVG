#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"

shapeGroup_t shapeCreation(shapeGroup_t s){
    shapeGroup_t g;
    int end = 0;
    int creation = 0;
    int i = 0;
    char name[20];
    while(end == 0){
        printf("What shape do you want to make ?\n");
        printf("1 - rectangle\n");
        printf("2 - square\n");
        printf("3 - circle\n");
        printf("4 - ellipse\n");
        printf("5 - line\n");
        printf("6 - polyline\n");
        printf("7 - polygon\n");
        printf("8 - path\n");
        printf("9 - group of shapes");
        printf("0 - exit the shapes creation\n");
        printf("\n");
        scanf("%d", &creation);
        switch (creation){
            if (i == 0){
                g.list = malloc(1 * sizeof(shapesElt));
            }
            else{
                shapesElt *temp = realloc(g.list, i+1 * sizeof(shapesElt));
                g.list = temp;
            }

            case(1):
                g.list[i].shpType = RECTANGLETYPE;
                g.list[i].shp.rectangle = createRectangle();
                printf("How do you want to name your rectangle ?(20 characters maximum)\n");
                scanf("%19s", &name);
                g.list[i].name = name;
                printf("\n");
                break;
            case(2):
                break;
            case(3):
                break;
            case(4):
                break;
            case(5):
                break;
            case(6):
                break;
            case(7):
                break;
            case(8):
                break;
            case(9):
                break;
            case(0):
                end = 1;
                break;
            default:
                printf("That shape can't be created, please type again.\n");
                break;

        }
        
    }
}