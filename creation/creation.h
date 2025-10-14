#ifndef CREATION
#define CREATION

//Prototypes structures
typedef struct rectangle_s{
    float height;
    float width;
    float xpos;
    float ypos;
    float xradius;
    float yradius;
} rectangle_t;

typedef struct square_s{
    float dimension;
    float xpos;
    float ypos;
    float xradius;
    float yradius;
} square_t;

typedef struct circle_s{
    float radius;
    float xpos;
    float ypos;
} circle_t;

typedef struct ellipse_s{
    float xradius;
    float yradius;
    float xpos;
    float ypos;
} ellipse_t;

typedef struct line_s{
    float xstart;
    float xend;
    float ystart;
    float yend;
} line_t;

typedef struct polyline_s{
    int nbLines;
    line_t *lines;
} polyline_t;

typedef struct polygon_s{
    int nbSides;
    line_t *lines;
} polygon_t;
//Prototypes unions

//Protoypes enumérations

//Prototypes fonctions

rectangle_t *createRectangle(rectangle_t *r, int editing);
void getRectangle(rectangle_t *r);
square_t *createSquare(square_t *c, int editing);
void getSquare(square_t *c);
circle_t *createCicrcle(circle_t *c, int editing);
void getCircle(circle_t *c);
ellipse_t *createEllipse(ellipse_t *e, int editing);
void getEllipse(ellipse_t *e);
line_t *createLine(line_t *l, int editing);
void getLine(line_t *l);
polyline_t *createPolyline(polyline_t *pl, int editing);
void getPolyline(polyline_t *pl);
polygon_t *createPolygon(polygon_t *pg, int editing);
void getPolygon(polygon_t *pg);

#endif