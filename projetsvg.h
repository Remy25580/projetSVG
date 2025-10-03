#ifndef PROJETSVG
#define PROJETSVG

//Prototypes structures

//Prototypes unions
typedef union oon openedOrNot;

//Protoypes enumérations
typedef enum oont openedOrNotType;


//Prototypes fonctions
FILE *creatingFile(char *name);

FILE *openingFile(char *name);

int help(openedOrNotType s);

void closeFile(FILE *name);


#endif