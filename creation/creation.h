#ifndef PROJETSVG
#define PROJETSVG

//Prototypes structures
typedef struct rectangle_s{
    int height;
    int width;
    int xpos;
    int ypos;
} rectangle_t;

typedef struct square_s{
    int dimension;
    int xpos;
    int ypos;
} square_t;

typedef struct circle_s{
    int radius;
    int xpos;
    int ypos;
} circle_t;

typedef struct ellipse_s{
    int xradius;
    int yradius;
    int xpos;
    int ypos;
} ellipse_t;
//Prototypes unions

//Protoypes enumérations

//Prototypes fonctions

rectangle_t createRectangle(void);
void getRectangle(rectangle_t r);
square_t createSquare(void);
void getSquare(square_t c);
circle_t createCicrcle(void);
void getCircle(circle_t c);
ellipse_t createEllipse(void);
void getEllipse(ellipse_t e);
#endif