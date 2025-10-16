#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"
#include "deletion.h"
#include "color.h"
#include "saveManagement.h"

void freeRectangle(rectangle_t *rectangle){
    free(rectangle);
}

void freeSquare(square_t *square){
    free(square);
}

void freeCircle(circle_t *circle){
    free(circle);
}

void freeEllipse(ellipse_t *ellipse){
    free(ellipse);
}

void freeLine(line_t *line){
    free(line);
}

void freePolyline(polyline_t *polyline){
    free(polyline->lines);
    free(polyline);
}

void freePolygon(polygon_t *polygon){
    free(polygon->lines);
    free(polygon);
}

void freePath(path_t *path){
    free(path->list);
    free(path);
}


void freeShape(shapesElt *shape){
    printf("initializing deletion\n");
    if(shape->style != NULL){
        free(shape->style);
    }
    switch(shape->shpType){
        case(RECTANGLETYPE):
            printf("Deleting %s . . .\n", shape->name);
            freeRectangle(shape->shp.rectangle);
            break;
        case(SQUARETYPE):
            printf("Deleting %s . . .\n", shape->name);
            freeSquare(shape->shp.square);
            break;
        case(CIRCLETYPE):
            printf("Deleting %s . . .\n", shape->name);
            freeCircle(shape->shp.circle);
            break;
        case(ELLIPSETYPE):
            printf("Deleting %s . . .\n", shape->name);
            freeEllipse(shape->shp.ellipse);
            break;
        case(LINETYPE):
            printf("Deleting %s . . .\n", shape->name);
            freeLine(shape->shp.line);
            break;
        case(POLYLINETYPE):
            printf("Deleting %s . . .\n", shape->name);
            freePolyline(shape->shp.polyline);
            break;
        case(POLYGONTYPE):
            printf("Deleting %s . . .\n", shape->name);
            freePolygon(shape->shp.polygon);
            break;
        case(PATHTYPE):
            printf("Deleting %s . . .\n", shape->name);
            freePath(shape->shp.path);
            break;
        default:
            break;
    }
}