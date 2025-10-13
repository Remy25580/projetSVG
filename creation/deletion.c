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
    
}