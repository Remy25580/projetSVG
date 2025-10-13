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

rectangle_t *createRectangle(void);
void getRectangle(rectangle_t *r);
square_t *createSquare(void);
void getSquare(square_t *c);
circle_t *createCicrcle(void);
void getCircle(circle_t *c);
ellipse_t *createEllipse(void);
void getEllipse(ellipse_t *e);
line_t *createLine(void);
void getLine(line_t *l);
polyline_t *createPolyline(void);
void getPolyline(polyline_t *pl);
polygon_t *createPolygon(void);
void getPolygon(polygon_t *pg);

#endif