#ifndef PROJETSVG
#define PROJETSVG

//Prototypes structures
typedef struct rectangle_s{
    int height;
    int width;
    int xpos;
    int ypos;
} rectangle_t;

typedef struct carre_s{
    int dimension;
    int xpos;
    int ypos;
} carre_t;
//Prototypes unions

//Protoypes enumérations

//Prototypes fonctions

rectangle_t createRectangle(void);
void getRectangle(rectangle_t r);
carre_t createSquare(void);
void getSquare(carre_t c);
#endif