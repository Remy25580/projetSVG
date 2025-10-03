#ifndef PROJETSVG
#define PROJETSVG

//Prototypes structures
typedef struct rectangle_s rectangle_t;
//Prototypes unions

//Protoypes enumérations

//Prototypes fonctions
FILE *creatingFile(char *name);
FILE *openingFile(char *name);
rectangle_t createRectangle(void);
void getRectangle(rectangle_t r);
#endif