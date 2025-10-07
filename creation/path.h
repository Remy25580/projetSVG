#ifndef PATH
#define PATH

typedef struct{
    float xpos;
    float ypos;
} M;

typedef struct{
    float xpos;
    float ypos;
} L;

typedef struct{
    float xpos
} H;

typedef struct{
    float ypos;
} V;

typedef struct{

} Z;

typedef struct{
    float xpent1;
    float ypent1;
    float xpent2;
    float ypent2;
    float xend;
    float yend;
} C;

typedef struct{
    float xpent2;
    float ypent2;
    float xend;
    float yend;
} S;

typedef struct{
    float xpent1;
    float ypent1;
    float xend;
    float yend;
} Q;

typedef struct{
    float xend;
    float yend;
} T;

typedef struct{
    float xradius;
    float yradius;
    float rotation;
    int side;
    int drawingWay;
    float xend;
    float yend;
} A;

typedef union{
    M m;
    L l;
    H h;
    V v;
    Z z;
    C c;
    S s;
    Q q;
    T t;
    A a;
} operation;

typedef enum{
    TYPEM,
    TYPEL,
    TYPEH,
    TYPEV,
    TYPEZ,
    TYPEC,
    TYPES,
    TYPEQ,
    TYPET,
    TYPEA
} operationType;

#endif