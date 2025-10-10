#ifndef USER
#define USER

typedef union{
    rectangle_t rectangle;
    square_t square;
    circle_t circle;
    ellipse_t ellipse;
    line_t line;
    polyline_t polyline;
    polygon_t polygon;
    path_t path;
} shapes;
#endif