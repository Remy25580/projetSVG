#ifndef PROJETSVG
#define PROJETSVG

//Prototypes structures
typedef struct rectangle_s{

    int height,width,xpos,ypos;
    
} rectangle_t;
//Prototypes unions

//Protoypes enumérations

//Prototypes fonctions

rectangle_t createRectangle(void);
void getRectangle(rectangle_t r);
#endif