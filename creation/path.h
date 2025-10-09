#ifndef PATH
#define PATH

typedef struct{
    float xpos;
    float ypos;
} Mtype;

typedef struct{
    float xpos;
    float ypos;
} Ltype;

typedef struct{
    float xpos;
} Htype;

typedef struct{
    float ypos;
} Vtype;

typedef struct{
    int verif;

} Ztype;

typedef struct{
    float xpent1;
    float ypent1;
    float xpent2;
    float ypent2;
    float xend;
    float yend;
} Ctype;

typedef struct{
    float xpent2;
    float ypent2;
    float xend;
    float yend;
} Stype;

typedef struct{
    float xpent1;
    float ypent1;
    float xend;
    float yend;
} Qtype;

typedef struct{
    float xend;
    float yend;
} Ttype;

typedef struct{
    float xradius;
    float yradius;
    float rotation;
    int side;
    int drawingWay;
    float xend;
    float yend;
} Atype;

typedef union{
    Mtype m;
    Ltype l;
    Htype h;
    Vtype v;
    Ztype z;
    Ctype c;
    Stype s;
    Qtype q;
    Ttype t;
    Atype a;
} operation;

typedef enum{
    M,
    L,
    H,
    V,
    Z,
    C,
    S,
    Q,
    T,
    A,
    D
} operationType;


typedef struct{
    int size;
    operation *opListe;
    operationType *opTypeListe;
} path_t;

path_t createPath(void);
void getPath(path_t p);
#endif