#ifndef PROJETSVG
#define PROJETSVG

//Prototypes structures
typedef struct rectangle_s renctangle_t;
//Prototypes unions

//Protoypes enumérations

//Prototypes fonctions
FILE *creatingFile(char *name);
FILE *openingFile(char *name);
renctangle_t createRectangle(void);
void getRectangle(renctangle_t r);
#endif