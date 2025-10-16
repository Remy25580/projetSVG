#ifndef CREATION
#define CREATION

/**
 * Class that defines the rectangle shape
 */
typedef struct rectangle_s{
    float height;
    float width;
    float xpos;
    float ypos;
    float xradius;
    float yradius;
} rectangle_t;

/**
 * Class that defines the square shape
 */
typedef struct square_s{
    float dimension;
    float xpos;
    float ypos;
    float xradius;
    float yradius;
} square_t;

/**
 * Class that defines the circle shape
 */
typedef struct circle_s{
    float radius;
    float xpos;
    float ypos;
} circle_t;

/**
 * Class that defines the ellipse shape
 */
typedef struct ellipse_s{
    float xradius;
    float yradius;
    float xpos;
    float ypos;
} ellipse_t;

/**
 * Class that defines the line shape
 */
typedef struct line_s{
    float xstart;
    float xend;
    float ystart;
    float yend;
} line_t;

/**
 * Class that defines the polyline shape
 */
typedef struct polyline_s{
    int nbLines;
    line_t *lines;
} polyline_t;

/**
 * Class that defines the polygon shape
 */
typedef struct polygon_s{
    int nbSides;
    line_t *lines;
} polygon_t;

/**
 * Creates a rectangle
 * @param r the rectangle_t object in which the informations are put, to create or edit a rectangle
 * @param editing defines if the rectangle is created (0) or edited (1)
 */
rectangle_t *createRectangle(rectangle_t *r, int editing);

/**
 * Writes the informations about a rectangle
 * @param r rectangle from which you get the informations
 */
void getRectangle(rectangle_t *r);

/**
 * Creates a square
 * @param c the square_t object in which the informations are put, to create or edit a square
 * @param editing defines if the square is created (0) or edited (1)
 */
square_t *createSquare(square_t *c, int editing);

/**
 * Writes the informations about a square
 * @param c square from which you get the informations
 */
void getSquare(square_t *c);

/**
 * Creates a circle
 * @param c the circle_t object in which the informations are put, to create or edit a circle
 * @param editing defines if the circle is created (0) or edited (1)
 */
circle_t *createCicrcle(circle_t *c, int editing);

/**
 * Writes the informations about a circle
 * @param c circle from which you get the informations
 */
void getCircle(circle_t *c);

/**
 * Creates an ellipse
 * @param e the ellipse_t object in which the informations are put, to create or edit an ellipse
 * @param editing defines if the ellipse is created (0) or edited (1)
 */
ellipse_t *createEllipse(ellipse_t *e, int editing);

/**
 * Writes the informations about an ellipse
 * @param e ellipse from which you get the informations
 */
void getEllipse(ellipse_t *e);

/**
 * Creates a line
 * @param l the line_t object in which the informations are put, to create or edit a line
 * @param editing defines if the line is created (0) or edited (1)
 */
line_t *createLine(line_t *l, int editing);

/**
 * Writes the informations about a line
 * @param l line from which you get the informations
 */
void getLine(line_t *l);

/**
 * Creates a polyline
 * @param pl the polyline_t object in which the informations are put, to create or edit a polyline
 * @param editing defines if the polyline is created (0) or edited (1)
 */
polyline_t *createPolyline(polyline_t *pl, int editing);

/**
 * Writes the informations about a polyline
 * @param pl polyline from which you get the informations
 */
void getPolyline(polyline_t *pl);

/**
 * Creates a polygon
 * @param pg the polygon_t object in which the informations are put, to create or edit a polygon
 * @param editing defines if the polygon is created (0) or edited (1)
 */
polygon_t *createPolygon(polygon_t *pg, int editing);

/**
 * Writes the informations about a polygon
 * @param pg polyline from which you get the informations
 */
void getPolygon(polygon_t *pg);

#endif