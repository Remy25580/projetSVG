#ifndef DELETION
#define DELETION



void freeRectangle(rectangle_t *rectangle);
void freeSquare(square_t *square);
void freeCircle(circle_t *circle);
void freeEllipse(ellipse_t *ellipse);
void freeLine(line_t *line);
void freePolyline(polyline_t *polyline);
void freePolygon(polygon_t *polygon);
void freePath(path_t *path);
void freeGroup(shapeGroup_t *group);

void freeShape(shapesElt *shape);
#endif