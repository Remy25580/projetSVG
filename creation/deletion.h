#ifndef DELETION
#define DELETION


/**
 * Deletes a rectangle by applying free() on it
 * @param rectangle the rectangle that is going to be deleted
 */
void freeRectangle(rectangle_t *rectangle);

/**
 * Deletes a square by applying free() on it
 * @param square the square that is going to be deleted
 */
void freeSquare(square_t *square);

/**
 * Deletes a circle by applying free() on it
 * @param circle the cirlce that is going to be deleted
 */
void freeCircle(circle_t *circle);

/**
 * Deletes an ellipse by applying free() on it
 * @param ellipse the ellipse that is going to be deleted
 */
void freeEllipse(ellipse_t *ellipse);

/**
 * Deletes a line by applying free() on it
 * @param line the line that is going to be deleted
 */
void freeLine(line_t *line);

/**
 * Deletes a polyline by applying free() on it
 * @param polyline the polyline that is going to be deleted
 */
void freePolyline(polyline_t *polyline);

/**
 * Deletes a polygon by applying free() on it
 * @param polygon the polygon that is going to be deleted
 */
void freePolygon(polygon_t *polygon);

/**
 * Deletes a path by applying free() on it
 * @param path the path that is going to be deleted
 */
void freePath(path_t *path);

/**
 * Deletes any shape using the previous functions
 * @param shape the shape that is going to be deleted
 */
void freeShape(shapesElt *shape);
#endif