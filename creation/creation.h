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
    int rayon;
    int xpos;
    int ypos;
} circle_t;
//Prototypes unions

//Protoypes enumérations

//Prototypes fonctions

rectangle_t createRectangle(void);
void getRectangle(rectangle_t r);
square_t createSquare(void);
void getSquare(square_t c);
circle_t createCicrcle(void);
void getCircle(circle_t c);
#endif