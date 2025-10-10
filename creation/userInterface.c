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
                g.list[i].shpType = SQUARETYPE;
                g.list[i].shp.square = createSquare();
                printf("How do you want to name your square ?(20 characters maximum)\n");
                scanf("%19s", &name);
                g.list[i].name = name;
                printf("\n");
                break;
            case(3):
                g.list[i].shpType = CIRCLETYPE;
                g.list[i].shp.circle = createCicrcle();
                printf("How do you want to name your circle ?(20 characters maximum)\n");
                scanf("%19s", &name);
                g.list[i].name = name;
                printf("\n");
                break;
            case(4):
                g.list[i].shpType = ELLIPSETYPE;
                g.list[i].shp.ellipse = createEllipse();
                printf("How do you want to name your ellipse ?(20 characters maximum)\n");
                scanf("%19s", &name);
                g.list[i].name = name;
                printf("\n");
                break;
            case(5):
                g.list[i].shpType = LINETYPE;
                g.list[i].shp.line = createLine();
                printf("How do you want to name your line ?(20 characters maximum)\n");
                scanf("%19s", &name);
                g.list[i].name = name;
                printf("\n");
                break;
            case(6):
                g.list[i].shpType = POLYLINETYPE;
                g.list[i].shp.polyline = createPolyline();
                printf("How do you want to name your polyline ?(20 characters maximum)\n");
                scanf("%19s", &name);
                g.list[i].name = name;
                printf("\n");
                break;
            case(7):
                g.list[i].shpType = POLYGONTYPE;
                g.list[i].shp.polygon = createPolygon();
                printf("How do you want to name your polygon ?(20 characters maximum)\n");
                scanf("%19s", &name);
                g.list[i].name = name;
                printf("\n");
                break;
            case(8):
                g.list[i].shpType = PATHTYPE;
                g.list[i].shp.path = createPath();
                printf("How do you want to name your path ?(20 characters maximum)\n");
                scanf("%19s", &name);
                g.list[i].name = name;
                printf("\n");
                break;
            case(9):
                g.list[i].shpType = GROUPTYPE;
                g.list[i].shp.group = shapeCreation(g);
                printf("How do you want to name your group ?(20 characters maximum)\n");
                scanf("%19s", &name);
                g.list[i].name = name;
                printf("\n");
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