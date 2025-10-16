#ifndef USER
#define USER

//-----------------STRUCTURES----------------//

/**
 * Structure that defines a shape in its globality
 * => Contains what shape it is, its type, name and stylization
 * => Is linked to the other shapes to make a list
 * @author Rémy Martinot
 */
typedef struct shapesElt_s shapesElt;

/**
 * Structure that defines the list of shapes
 * @author Rémy Martinot
 */
typedef struct shapeGroup_s shapeGroup_t;

/**
 * Structure that defines the stylization of a shape
 * => Contains the contour and filling color, the transltion point, the rotation, and if it is inverted
 * @author Rémy Martinot
 */
typedef struct style shapeStyle;

struct shapeGroup_s{
    int nb;
    shapesElt *head;
};

/**
 * Union that contains all of the shapes type
 * @author Rémy Martinot
 */
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

/**
 * Enumeration that defines the shapes type
 * @author Rémy Martinot
 */
typedef enum{
    RECTANGLETYPE,
    SQUARETYPE,
    CIRCLETYPE,
    ELLIPSETYPE,
    LINETYPE,
    POLYLINETYPE,
    POLYGONTYPE,
    PATHTYPE,
} shapesType;

struct shapesElt_s{
    char *name;
    shapes shp;
    shapesType shpType;
    shapesElt *next;
    shapesElt *previous;
    shapeStyle *style;
    
};

struct style{
    char *color;
    char *fillColor;
    float xtranslate;
    float ytranslate;
    float rotate;
    int xinvert;
    int yinvert;

};

//-----------------FUNCTIONS----------------//

/**
 * Manages the creation of all the shapes
 * @param s The list in which all of the shapes are going to be added
 * @return The list filled with the shapes created
 * @author Rémy Martinot
 */
shapeGroup_t *shapeCreation(shapeGroup_t *s);

/**
 * Writes the informations of all the shapes created
 * @param s The list that contains the shapes that are going to be gotten
 * @author Rémy Martinot
 */
void getShapes(shapeGroup_t *s);

/**
 * Adds a shape from the shapesElt stucture in the list
 * @param list The list in which the shape is going to be added
 * @param elt The shape that is going to be added in the list
 * @author Rémy Martinot
 */
void addInList(shapeGroup_t *list, shapesElt *elt);

/**
 * Deletes any kind of shape
 * @param s The list from which a shape is going to be removed
 * @author Rémy Martinot
 */
void deleteShape(shapeGroup_t *s);

/**
 * Adds the stylization of a shape
 * @param s The list from which a shape is going to be stylished
 * @author Rémy Martinot
 */
void stylishShapes(shapeGroup_t *s);

/**
 * Edits a shape
 * @param s The list from which a shape is going to be editted
 * @author Rémy Martinot
 */
void editShapes(shapeGroup_t *s);


#endif