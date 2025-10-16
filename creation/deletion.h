#ifndef DELETION
#define DELETION


/**
 * Deletes a rectangle by applying free() on it
 * @param rectangle The rectangle that is going to be deleted
 * @author Rémy Martinot
 */
void freeRectangle(rectangle_t *rectangle);

/**
 * Deletes a square by applying free() on it
 * @param square The square that is going to be deleted
 * @author Rémy Martinot
 */
void freeSquare(square_t *square);

/**
 * Deletes a circle by applying free() on it
 * @param circle The cirlce that is going to be deleted
 * @author Rémy Martinot
 */
void freeCircle(circle_t *circle);

/**
 * Deletes an ellipse by applying free() on it
 * @param ellipse The ellipse that is going to be deleted
 * @author Rémy Martinot
 */
void freeEllipse(ellipse_t *ellipse);

/**
 * Deletes a line by applying free() on it
 * @param line The line that is going to be deleted
 * @author Rémy Martinot
 */
void freeLine(line_t *line);

/**
 * Deletes a polyline by applying free() on it
 * @param polyline The polyline that is going to be deleted
 * @author Rémy Martinot
 */
void freePolyline(polyline_t *polyline);

/**
 * Deletes a polygon by applying free() on it
 * @param polygon The polygon that is going to be deleted
 * @author Rémy Martinot
 */
void freePolygon(polygon_t *polygon);

/**
 * Deletes a path by applying free() on it
 * @param path The path that is going to be deleted
 * @author Rémy Martinot
 */
void freePath(path_t *path);

/**
 * Deletes any shape using the previous functions
 * @param shape The shape that is going to be deleted
 * @author Rémy Martinot
 */
void freeShape(shapesElt *shape);
#endif