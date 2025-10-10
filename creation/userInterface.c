#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"

shapeGroup_t shapeCreation(shapeGroup_t g){
    int end = 0;
    int creation = 0;
    char *name = malloc(sizeof(char) * 20);

    if (g.nb == 0){
        g.list = malloc(1 * sizeof(shapesElt));
    }
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
        printf("9 - group of shapes\n");
        printf("0 - exit the shapes creation\n");
        printf("\n");
        scanf("%d", &creation);
        switch (creation){
            case(1):
                g.list[g.nb].shpType = RECTANGLETYPE;
                g.list[g.nb].shp.rectangle = createRectangle();
                printf("How do you want to name your rectangle ?(20 characters maximum)\n");
                scanf("%19s", name);
                g.list[g.nb].name = name;
                printf("\n");
                break;
            case(2):
                g.list[g.nb].shpType = SQUARETYPE;
                g.list[g.nb].shp.square = createSquare();
                printf("How do you want to name your square ?(20 characters maximum)\n");
                scanf("%19s", name);
                g.list[g.nb].name = name;
                printf("\n");
                break;
            case(3):
                g.list[g.nb].shpType = CIRCLETYPE;
                g.list[g.nb].shp.circle = createCicrcle();
                printf("How do you want to name your circle ?(20 characters maximum)\n");
                scanf("%19s", name);
                g.list[g.nb].name = name;
                printf("\n");
                break;
            case(4):
                g.list[g.nb].shpType = ELLIPSETYPE;
                g.list[g.nb].shp.ellipse = createEllipse();
                printf("How do you want to name your ellipse ?(20 characters maximum)\n");
                scanf("%19s", name);
                g.list[g.nb].name = name;
                printf("\n");
                break;
            case(5):
                g.list[g.nb].shpType = LINETYPE;
                g.list[g.nb].shp.line = createLine();
                printf("How do you want to name your line ?(20 characters maximum)\n");
                scanf("%19s", name);
                g.list[g.nb].name = name;
                printf("\n");
                break;
            case(6):
                g.list[g.nb].shpType = POLYLINETYPE;
                g.list[g.nb].shp.polyline = createPolyline();
                printf("How do you want to name your polyline ?(20 characters maximum)\n");
                scanf("%19s", name);
                g.list[g.nb].name = name;
                printf("\n");
                break;
            case(7):
                g.list[g.nb].shpType = POLYGONTYPE;
                g.list[g.nb].shp.polygon = createPolygon();
                printf("How do you want to name your polygon ?(20 characters maximum)\n");
                scanf("%19s", name);
                g.list[g.nb].name = name;
                printf("\n");
                break;
            case(8):
                g.list[g.nb].shpType = PATHTYPE;
                g.list[g.nb].shp.path = createPath();
                printf("How do you want to name your path ?(20 characters maximum)\n");
                scanf("%19s", name);
                g.list[g.nb].name = name;
                printf("\n");
                break;
            case(9):
                g.list[g.nb].shpType = GROUPTYPE;
                g.list[g.nb].shp.group = shapeCreation(g);
                printf("How do you want to name your group ?(20 characters maximum)\n");
                scanf("%19s", name);
                g.list[g.nb].name = name;
                printf("\n");
                break;
            case(0):
                end = 1;
                break;
            default:
                printf("That shape can't be created, please type again.\n");
                break;
            

        }
        g.nb++;
        shapesElt *temp = realloc(g.list, g.nb+1 * sizeof(shapesElt));
        g.list = temp;
        
    }
    return g;
}

shapeGroup_t shapeDeletion(shapeGroup_t s){
    printf("What shape do you want to delete ?\n");
    for(int i = 0; i < s.nb; i++){
        printf("\t %s\n", s.list[i].name);
    }

    char *name = malloc(sizeof(char) * 20);
    int chosen = 0;
    while(chosen == 0){
        scanf("%s", name);
        for(int j = 0; j < s.nb; j++){
            if (name == s.list[j].name){
                for(int k = 0; k < s.nb-j-1; k++){
                    s.list[j+k] = s.list[j+k+1];
                }
                s.list = realloc(s.list, s.nb-1 * sizeof(shapesElt));
                s.nb--;
                return s;
            }
        }
        printf("No shape of yours has this name. Please type again.\n");
    }
    return s;
}