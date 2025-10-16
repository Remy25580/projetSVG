#ifndef CREATION
#define CREATION

//-----------------STRUCTURES------------------//

/**
 * Structure that defines the rectangle shape
 * @author Rémy Martinot
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
 * Structure that defines the square shape
 * @author Rémy Martinot
 */
typedef struct square_s{
    float dimension;
    float xpos;
    float ypos;
    float xradius;
    float yradius;
} square_t;

/**
 * Structure that defines the circle shape
 * @author Rémy Martinot
 */
typedef struct circle_s{
    float radius;
    float xpos;
    float ypos;
} circle_t;

/**
 * Structure that defines the ellipse shape
 * @author Rémy Martinot
 */
typedef struct ellipse_s{
    float xradius;
    float yradius;
    float xpos;
    float ypos;
} ellipse_t;

/**
 * Structure that defines the line shape
 * @author Rémy Martinot
 */
typedef struct line_s{
    float xstart;
    float xend;
    float ystart;
    float yend;
} line_t;

/**
 * Structure that defines the polyline shape
 * => Uses a list of lines
 * @author Rémy Martinot
 */
typedef struct polyline_s{
    int nbLines;
    line_t *lines;
} polyline_t;

/**
 * Structure that defines the polygon shape
 * Uses a list of lines
 * @author Rémy Martinot
 */
typedef struct polygon_s{
    int nbSides;
    line_t *lines;
} polygon_t;


//-------------------FUNCTIONS--------------------//

/**
 * Creates a rectangle
 * @param r The rectangle_t object in which the informations are put, to create or edit a rectangle
 * @param editing Defines if the rectangle is created (0) or edited (1)
 * @return The rectangle filled with the informations given by the user
 * @author Rémy Martinot
 */
rectangle_t *createRectangle(rectangle_t *r, int editing);

/**
 * Writes the informations about a rectangle
 * @param r Rectangle from which you get the informations
 * @author Rémy Martinot
 */
void getRectangle(rectangle_t *r);

/**
 * Creates a square
 * @param c The square_t object in which the informations are put, to create or edit a square
 * @param editing Defines if the square is created (0) or edited (1)
 * @return The square filled with the informations given by the user
 * @author Rémy Martinot
 */
square_t *createSquare(square_t *c, int editing);

/**
 * Writes the informations about a square
 * @param c Square from which you get the informations
 * @author Rémy Martinot
 */
void getSquare(square_t *c);

/**
 * Creates a circle
 * @param c The circle_t object in which the informations are put, to create or edit a circle
 * @param editing Defines if the circle is created (0) or edited (1)
 * @return The circle filled with the informations given by the user
 * @author Rémy Martinot
 */
circle_t *createCicrcle(circle_t *c, int editing);

/**
 * Writes the informations about a circle
 * @param c Circle from which you get the informations
 * @author Rémy Martinot
 */
void getCircle(circle_t *c);

/**
 * Creates an ellipse
 * @param e The ellipse_t object in which the informations are put, to create or edit an ellipse
 * @param editing Defines if the ellipse is created (0) or edited (1)
 * @return The ellipse filled with the informations given by the user
 * @author Rémy Martinot
 */
ellipse_t *createEllipse(ellipse_t *e, int editing);

/**
 * Writes the informations about an ellipse
 * @param e Ellipse from which you get the informations
 * @author Rémy Martinot
 */
void getEllipse(ellipse_t *e);

/**
 * Creates a line
 * @param l The line_t object in which the informations are put, to create or edit a line
 * @param editing Tefines if the line is created (0) or edited (1)
 * @return The line filled with the informations given by the user
 * @author Rémy Martinot
 */
line_t *createLine(line_t *l, int editing);

/**
 * Writes the informations about a line
 * @param l Line from which you get the informations
 * @author Rémy Martinot
 */
void getLine(line_t *l);

/**
 * Creates a polyline
 * @param pl The polyline_t object in which the informations are put, to create or edit a polyline
 * @param editing Defines if the polyline is created (0) or edited (1)
 * @return The polyline filled with the informations given by the user
 * @author Rémy Martinot
 */
polyline_t *createPolyline(polyline_t *pl, int editing);

/**
 * Writes the informations about a polyline
 * @param pl Polyline from which you get the informations
 * @author Rémy Martinot
 */
void getPolyline(polyline_t *pl);

/**
 * Creates a polygon
 * @param pg The polygon_t object in which the informations are put, to create or edit a polygon
 * @param editing Defines if the polygon is created (0) or edited (1)
 * @return The polygon filled with the informations given by the user
 * @author Rémy Martinot
 */
polygon_t *createPolygon(polygon_t *pg, int editing);

/**
 * Writes the informations about a polygon
 * @param pg Polyline from which you get the informations
 * @author Rémy Martinot
 */
void getPolygon(polygon_t *pg);

#endif