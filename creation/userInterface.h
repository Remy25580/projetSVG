#ifndef USER
#define USER

typedef struct shapesElt_s shapesElt;
typedef struct shapeGroup_s shapeGroup_t;


typedef union{
    rectangle_t rectangle;
    square_t square;
    circle_t circle;
    ellipse_t ellipse;
    line_t line;
    polyline_t polyline;
    polygon_t polygon;
    path_t path;
    shapeGroup_t group;
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

typedef struct{
    char *name;
    shapes shp;
    shapesType shpType;
} shapeElt;

typedef struct{
    shapeElt *list;
}shapeGroup_t;



shapeGroup_t shapeCreation(void);

#endif