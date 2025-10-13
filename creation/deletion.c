#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"
#include "deletion.h"

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

void freeGroup(shapeGroup_t *group){
    for (int i = 0; i<group->nb; i++){
        switch(group->head[i].shpType){
            case(RECTANGLETYPE):
                freeRectangle(group->head[i].shp.rectangle);
                break;
            case(SQUARETYPE):
                freeSquare(group->head[i].shp.square);
                break;
            case(CIRCLETYPE):
                freeCircle(group->head[i].shp.circle);
                break;
            case(ELLIPSETYPE):
                freeEllipse(group->head[i].shp.ellipse);
                break;
            case(LINETYPE):
                freeLine(group->head[i].shp.line);
                break;
            case(POLYLINETYPE):
                freePolyline(group->head[i].shp.polyline);
                break;
            case(POLYGONTYPE):
                freePolygon(group->head[i].shp.polygon);
                break;
            case(PATHTYPE):
                freePath(group->head[i].shp.path);
                break;
            case(GROUPTYPE):
                freeGroup(group->head[i].shp.group);
                break;
            default:
                break;
        }
    }
}