#ifndef USER
#define USER

typedef struct shapesElt_s shapesElt;
typedef struct shapeGroup_s shapeGroup_t;

struct shapeGroup_s{
    int nb;
    shapesElt *head;
};

typedef union{
    rectangle_t *rectangle;
    square_t *square;
    circle_t *circle;
    ellipse_t *ellipse;
    line_t *line;
    polyline_t *polyline;
    polygon_t *polygon;
    path_t *path;
    shapeGroup_t *group;
} shapes;

typedef enum{
    RECTANGLETYPE,
    SQUARETYPE,
    CIRCLETYPE,
    ELLIPSETYPE,
    LINETYPE,
    POLYLINETYPE,
    POLYGONTYPE,
    PATHTYPE,
    GROUPTYPE
} shapesType;

struct shapesElt_s{
    char *name;
    shapes shp;
    shapesType shpType;
    shapesElt *next;
    shapesElt *previous;
    
};

shapeGroup_t *shapeCreation(shapeGroup_t *s);
void getShapes(shapeGroup_t *s);
void addInList(shapeGroup_t *list, shapesElt *elt);


#endif