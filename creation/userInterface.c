#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"

shapeGroup_t *shapeCreation(shapeGroup_t *g){
    int end = 0;
    int err;
    int creation = 0;
    shapesElt temp;
    char *name = malloc(sizeof(char) * 20);

    
    while(end == 0){
        err = 0;
        printf("What shape do you want to make ?\n");
        printf("1 - rectangle\n");
        printf("2 - square\n");
        printf("3 - circle\n");
        printf("4 - ellipse\n");
        printf("5 - line\n");
        printf("6 - polyline\n");
        printf("7 - polygon\n");
        printf("8 - path\n");
        printf("9 - group of shapes\n");
        printf("0 - exit the shapes creation\n");
        printf("\n");
        scanf("%d", &creation);
        switch (creation){
            case(1):
                temp.shpType = RECTANGLETYPE;
                temp.shp.rectangle = createRectangle();
                printf("How do you want to name your rectangle ?(20 characters maximum)\n");
                scanf("%19s", name);
                temp.name = name;
                printf("\n");
                break;
            case(2):
                temp.shpType = SQUARETYPE;
                temp.shp.square = createSquare();
                printf("How do you want to name your square ?(20 characters maximum)\n");
                scanf("%19s", name);
                temp.name = name;
                printf("\n");
                break;
            case(3):
                temp.shpType = CIRCLETYPE;
                temp.shp.circle = createCicrcle();
                printf("How do you want to name your circle ?(20 characters maximum)\n");
                scanf("%19s", name);
                temp.name = name;
                printf("\n");
                break;
            case(4):
                temp.shpType = ELLIPSETYPE;
                temp.shp.ellipse = createEllipse();
                printf("How do you want to name your ellipse ?(20 characters maximum)\n");
                scanf("%19s", name);
                temp.name = name;
                printf("\n");
                break;
            case(5):
                temp.shpType = LINETYPE;
                temp.shp.line = createLine();
                printf("How do you want to name your line ?(20 characters maximum)\n");
                scanf("%19s", name);
                temp.name = name;
                printf("\n");
                break;
            case(6):
                temp.shpType = POLYLINETYPE;
                temp.shp.polyline = createPolyline();
                printf("How do you want to name your polyline ?(20 characters maximum)\n");
                scanf("%19s", name);
                temp.name = name;
                printf("\n");
                break;
            case(7):
                temp.shpType = POLYGONTYPE;
                temp.shp.polygon = createPolygon();
                printf("How do you want to name your polygon ?(20 characters maximum)\n");
                scanf("%19s", name);
                temp.name = name;
                printf("\n");
                break;
            case(8):
                temp.shpType = PATHTYPE;
                temp.shp.path = createPath();
                printf("How do you want to name your path ?(20 characters maximum)\n");
                scanf("%19s", name);
                temp.name = name;
                printf("\n");
                break;
            case(9):
                temp.shpType = GROUPTYPE;
                temp.shp.group = shapeCreation(g);
                printf("How do you want to name your group ?(20 characters maximum)\n");
                scanf("%19s", name);
                temp.name = name;
                printf("\n");
                break;
            case(0):
                end = 1;
                break;
            default:
                err = 1;
                printf("That shape can't be created, please type again.\n");
                break;
            

        }
        if (end ==0 && err == 0){
            g->nb = g->nb + 1;
            printf("nb de formes incremente\n");
            if (g->nb == 1){
                g->list = malloc(1 * sizeof(shapesElt));
                g->list[0] = temp;
                printf("premier ajout");
            }
        
            else{
                g->list = realloc(g->list, g->nb * sizeof(shapesElt));
                g->list[g->nb - 1] = temp;
                printf("nouvel ajout");
            }
        }

        for(int i = 0; i < g->nb; i++){
            printf("%d\n", i);
            printf("\t %s\n", g->list[i].name);
        }
        
        
    }
    
    return g;
}

