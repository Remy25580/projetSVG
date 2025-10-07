#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "path.h"


// Définitions d'unions


// Définitions d'énumérations



//Définitions de fonctions

rectangle_t createRectangle(void){
    rectangle_t r;
    printf("You are now creating a rectangle.\n");
    printf("Where does your rectangle start ?\n");
    printf("\n");
    int x;
    int y;
    printf("x position : ");
    scanf("%d", &x);
    printf("y position : ");
    scanf("%d", &y);

    printf("And now, what will be the height of your rectangle ?\n");
    int h;
    scanf("%d", &h);
    printf("And what will be the width of your rectangle ?\n");
    int w;
    scanf("%d", &w);

    printf("Now let's make the corners of your rectangle.\n");
    int rx = 0;
    int ry = 0;

    printf("So, what's the x radius of the corners ?\n");
    scanf("%d", &rx);
    printf("And to finish, what is the y radius of the corners ?\n");
    scanf("%d", &ry);
    
    printf("Your rectangle is now made! \n");
    r.xpos = x;
    r.ypos = y;
    r.height = h;
    r.width = w;
    r.xradius = rx;
    r.yradius = ry;
    
    return r;

}

void getRectangle(rectangle_t r){
    printf("Here's your rectangle: \n");
    printf("\n");
    printf("\t Start postition : %d;%d\n", r.xpos, r.ypos);
    printf("\t Height : %d  Width : %d\n", r.height, r.width);
    printf("\t Radius of the corners : %dx and %dy \n", r.xradius,r.yradius);
    printf("\n");
}

square_t createSquare(void){
    square_t c;
    printf("You are now creating a square.\n");
    printf("Where does your square start ?\n");
    printf("\n");
    int x;
    int y;
    printf("x position : ");
    scanf("%d", &x);
    printf("y position : ");
    scanf("%d", &y);

    printf("Now, what will be the dimensions of your square's borders ?\n");
    int d;
    scanf("%d", &d);

    printf("Now let's make the corners of your square.\n");
    int rx = 0;
    int ry = 0;

    printf("So, what's the x radius of the corners ?\n");
    scanf("%d", &rx);
    printf("And to finish, what is the y radius of the corners ?\n");
    scanf("%d", &ry);

    printf("Your square is now made! \n");
    c.xpos = x;
    c.ypos = y;
    c.dimension = d;
    c.xradius = rx;
    c.yradius = ry;
    return c;
}

void getSquare(square_t c){
    printf("Here's your square: \n");
    printf("\n");
    printf("\t Start postition : %d;%d\n", c.xpos, c.ypos);
    printf("\t Size : %dx%d", c.dimension, c.dimension);
    printf("\n");
}

circle_t createCicrcle(void){
    circle_t c;
    printf("You are now creating a circle.\n");
    printf("Where's the center of your circle ?\n");
    printf("\n");
    int x;
    int y;
    printf("x position : ");
    scanf("%d", &x);
    printf("y position : ");
    scanf("%d", &y);

    printf("And to finsh, what's the radius of your circle ?\n");
    int r;
    scanf("%d", &r);
    printf("Your circle is now made !\n");
    c.xpos = x;
    c.ypos = y;
    c.radius = r;
    return c;
}

void getCircle(circle_t c){
    printf("Here's your circle : \n");
    printf("\n");
    printf("\t Position of your circle : %d;%d \n", c.xpos, c.ypos);
    printf("\t Radius of the circle : %d \n", c.radius);
    printf("\n");
}

ellipse_t createEllipse(void){
    ellipse_t e;
    printf("You are now creating an ellipse.\n");
    printf("Where's the center of your ellipse ?\n");
    printf("\n");
    int x;
    int y;
    printf("x position : ");
    scanf("%d", &x);
    printf("y position : ");    
    scanf("%d", &y);

    printf("Now, what's the x radius of your ellipse ?\n");
    int xr;
    scanf("%d", &xr);
    printf("And to finish, what is the y radius of your ellipse ?\n");
    int yr;
    scanf("%d", &yr);
    printf("Your ellipse is now made !\n");
    e.xpos = x;
    e.ypos = y;
    e.xradius = xr;
    e.yradius = yr;
    return e;
}

void getEllipse(ellipse_t e){
    printf("Here's your ellipse : \n");
    printf("\n");
    printf("\t Position of your ellipse : %d;%d \n", e.xpos, e.ypos);
    printf("\t Lenght of your ellipse(x radius) : %d \n", e.xradius);
    printf("\t Height of your ellipse(y radius) : %d \n", e.yradius);
    printf("\n");
}

line_t createLine(void){
    line_t l;
    printf("You are now creating a line.\n");
    printf("What is the position of the begining of your line ?\n");
    printf("\n");
    int xs;
    int ys;
    printf("x position : ");
    scanf("%d", &xs);
    printf("\n");
    printf("y position : ");
    scanf("%d", &ys);
    printf("\n");
    printf("Good! Now what's the position of the ending of your line ?\n");
    printf("\n");
    int xe;
    int ye;
    printf("x position : ");
    scanf("%d", &xe);
    printf("\n");
    printf("y position : ");
    scanf("%d", &ye);
    printf("\n");
    printf("Your line is now made !\n");
    l.xstart = xs;
    l.ystart = ys;
    l.xend = xe;
    l.yend = ye;
    return l;
}

void getLine(line_t l){
    printf("Here's your line : \n");
    printf("\n");
    printf("\t Begining point : %d;%d \n", l.xstart, l.ystart);
    printf("\t Ending point : %d;%d \n", l.xend,l.yend);
    printf("\n");
}

polyline_t createPolyline(void){
    polyline_t pl;
    printf("You are now creating a polyline.\n");
    int nb;
    printf("First of all, how many lines do you want to connect ? \n");
    scanf("%d", &nb);

    printf("Great! Now let's create your lines.\n");
    pl.nbLines = nb;
    pl.lines = malloc(nb * sizeof(polyline_t));
    printf("What's the begining point of your polyline ?\n");
    int xs;
    int ys;
    printf("x position : ");
    scanf("%d", &xs);
    printf("y position : ");
    scanf("%d", &ys);
    int x;
    int y;
    line_t currentLine;
    currentLine.xstart = xs;
    currentLine.ystart = ys;
    for (int i = 0; i < nb; i++){
        printf("What's the point n %d of your polyline ?\n", i+2);
        printf("x position : ");
        scanf("%d", &x);
        printf("y position : ");
        scanf("%d", &y);

        currentLine.xend = x;
        currentLine.yend = y;

        pl.lines[i] = currentLine;

        currentLine.xstart = x;
        currentLine.ystart = y;
        printf("Line added to your polyline! \n");

    }
    printf("Your polyline is now made ! \n");
    return pl;
}

void getPolyline(polyline_t pl){
    printf("Here's your polyline : \n");
    printf("\n");
    for (int i = 0; i < pl.nbLines; i++){
        printf("\t Line n %d :  Start: %d;%d  End: %d;%d \n", i+1, pl.lines[i].xstart,
        pl.lines[i].ystart, pl.lines[i].xend, pl.lines[i].yend);

    }
    printf("\n");
}

polygon_t createPolygon(void){
    polygon_t pg;
    printf("You are now creating a polygon.\n");
    int nb;
    printf("First of all, how many sides will your polygon have ? \n");
    scanf("%d", &nb);
    
    printf("Great! Now let's create the sides.\n");
    pg.nbSides = nb;
    pg.lines = malloc(nb * sizeof(polyline_t));
    printf("What's the begining point of your polygon ?\n");
    int xs;
    int ys;
    printf("x position : ");
    scanf("%d", &xs);
    printf("y position : ");
    scanf("%d", &ys);
    int x;
    int y;
    line_t currentLine;
    currentLine.xstart = xs;
    currentLine.ystart = ys;
    for (int i = 0; i < nb-1; i++){
        printf("What's the point n %d of your polylgon ?\n", i+2);
        printf("x position : ");
        scanf("%d", &x);
        printf("y position : ");
        scanf("%d", &y);

        currentLine.xend = x;
        currentLine.yend = y;

        pg.lines[i] = currentLine;

        currentLine.xstart = x;
        currentLine.ystart = y;
        printf("Point added to your polygon! \n");

    }
    currentLine.xend = pg.lines[0].xstart;
    currentLine.yend = pg.lines[0].ystart;
    pg.lines[nb-1] = currentLine;

    printf("Your polylgon is now made ! \n");
    
    return pg;
}

void getPolygon(polygon_t pg){
    printf("Here's your polygon : \n");
    printf("\n");
    for (int i = 0; i < pg.nbSides; i++){
        printf("\t Point n %d: %d;%d \n", i+1, pg.lines[i].xstart, pg.lines[i].ystart);
    }
    printf("\n");
}