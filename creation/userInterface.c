#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"
#include "deletion.h"

void addInList(shapeGroup_t *list, shapesElt *elt){
    if(list->nb == 0){
        list->head = elt;
        list->head->next = NULL;
        list->head->previous = NULL;
    }
    else{
        shapesElt *current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = elt;
        elt->previous = current;
        elt->next = NULL;
    }
    list->nb = list->nb + 1;
}


shapeGroup_t *shapeCreation(shapeGroup_t *g){
    int end = 0;
    int err;
    int creation = 0;
    char *name = malloc(sizeof(char) * 20);
    shapesElt *current;

    
    while(end == 0){
        current = malloc(1*sizeof(shapesElt));
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
                current->shpType = RECTANGLETYPE;
                current->shp.rectangle = createRectangle();
                printf("How do you want to name your rectangle ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                printf("\n");
                break;
            case(2):
                current->shpType = SQUARETYPE;
                current->shp.square = createSquare();
                printf("How do you want to name your square ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                printf("\n");
                break;
            case(3):
                current->shpType = CIRCLETYPE;
                current->shp.circle = createCicrcle();
                printf("How do you want to name your circle ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                printf("\n");
                break;
            case(4):
                current->shpType = ELLIPSETYPE;
                current->shp.ellipse = createEllipse();
                printf("How do you want to name your ellipse ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                printf("\n");
                break;
            case(5):
                current->shpType = LINETYPE;
                current->shp.line = createLine();
                printf("How do you want to name your line ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                printf("\n");
                break;
            case(6):
                current->shpType = POLYLINETYPE;
                current->shp.polyline = createPolyline();
                printf("How do you want to name your polyline ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                printf("\n");
                break;
            case(7):
                current->shpType = POLYGONTYPE;
                current->shp.polygon = createPolygon();
                printf("How do you want to name your polygon ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                printf("\n");
                break;
            case(8):
                current->shpType = PATHTYPE;
                current->shp.path = createPath();
                printf("How do you want to name your path ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                printf("\n");
                break;
            case(9):
                current->shpType = GROUPTYPE;
                current->shp.group = shapeCreation(g);
                printf("How do you want to name your group ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
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
            addInList(g, current);
        }

    }
    
    return g;
}

void getShapes(shapeGroup_t *s){
    printf("There are your shapes : \n");
    shapesElt *current = s->head;
    while(current != NULL){
        printf("%s : \n", current->name);
        switch(current->shpType){
            case(RECTANGLETYPE):
                getRectangle(current->shp.rectangle);
                break;
            case(SQUARETYPE):
                getSquare(current->shp.square);
                break;
            case(CIRCLETYPE):
                getCircle(current->shp.circle);
                break;
            case(ELLIPSETYPE):
                getEllipse(current->shp.ellipse);
                break;
            case(LINETYPE):
                getLine(current->shp.line);
                break;
            case(POLYLINETYPE):
                getPolyline(current->shp.polyline);
                break;
            case(POLYGONTYPE):
                getPolygon(current->shp.polygon);
                break;
            case(PATHTYPE):
                getPath(current->shp.path);
                break;
            case(GROUPTYPE):
                printf("Here's your shape group : \n");
                getShapes(current->shp.group);
                break;
            default:
                break;
        }
        current = current->next;
    }

}