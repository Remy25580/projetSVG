#ifndef PATH
#define PATH

//-------------------STRUCTURES-------------------//

/**
 * Structure that defines the M operation of a path
 * => Moving to a point without drawing
 */
typedef struct{
    float xpos;
    float ypos;
} Mtype;

/**
 * Structure that defines the L operation of a path
 * => Drawing a line to a point
 */
typedef struct{
    float xpos;
    float ypos;
} Ltype;

/**
 * Structure that defines the H operation of a path
 * => Drawing an horizontal line to an x-axis
 */
typedef struct{
    float xpos;
} Htype;

/**
 * Structure that defines the V operation of a path
 * => Drawing a vertical line to a y-axis
 */
typedef struct{
    float ypos;
} Vtype;

/**
 * Structure that defines the Z operation of a path
 * => Drawing a line to the last unclosed point
 */
typedef struct{
    int verif;
} Ztype;

/**
 * Structure that defines the C operation of a path
 * => Drawing a cubic curve to a point, using two control points
 */
typedef struct{
    float xpent1;
    float ypent1;
    float xpent2;
    float ypent2;
    float xend;
    float yend;
} Ctype;

/**
 * Structure that defines the S operation of a path
 * => Drawing a mirror cubic curve to the precedent, to a point, using a control point
 */
typedef struct{
    float xpent2;
    float ypent2;
    float xend;
    float yend;
} Stype;

/**
 * Structure that defines the Q operation of a path
 * => Drawing a quadratic curve to a point using a control point
 */
typedef struct{
    float xpent1;
    float ypent1;
    float xend;
    float yend;
} Qtype;

/**
 * Structure that defines the T operation of a path
 * => Drawing a mirror quadratic curve to the precedent, to a point
 */
typedef struct{
    float xend;
    float yend;
} Ttype;

/**
 * Structure that defines the A operation of a path
 * => Drawing an arc to a point using an ellipse
 */
typedef struct{
    float xradius;
    float yradius;
    float rotation;
    int side;
    int drawingWay;
    float xend;
    float yend;
} Atype;

/**
 * Union including all of the shape types
 */
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

/**
 * Enumeration representing all of the shape types to use them
 */
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

/**
 * Structure that represents a path operation
 * Includes the operation from the union and its type from the enumeration
 */
typedef struct{
    operation op;
    operationType opt;

} operationComplete;

/**
 * Structure that defines the path shape
 * => Uses a list of the path operations
 */
typedef struct{
    int size;
    operationComplete *list;
} path_t;

//-------------------FUNCTIONS-------------------//

/**
 * Creates a path
 * @param t the path_t object in which the informations are put, to create or edit a path
 * @param editing defines if the path is created (0) or edited (1)
 */
path_t *createPath(path_t *t, int editing);

/**
 * Writes the informations about a path
 * @param p path from which you get the informations
 */
void getPath(path_t *p);
#endif