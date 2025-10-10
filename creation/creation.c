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
    float x;
    float y;
    printf("x position : ");
    scanf("%f", &x);
    printf("y position : ");
    scanf("%f", &y);

    printf("And now, what will be the height of your rectangle ?\n");
    float h;
    scanf("%f", &h);
    printf("And what will be the width of your rectangle ?\n");
    float w;
    scanf("%f", &w);

    printf("Now let's make the corners of your rectangle.\n");
    float rx = 0;
    float ry = 0;

    printf("So, what's the x radius of the corners ?\n");
    scanf("%f", &rx);
    printf("And to finish, what is the y radius of the corners ?\n");
    scanf("%f", &ry);
    
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
    printf("\t Start postition : %.2f;%.2f\n", r.xpos, r.ypos);
    printf("\t Height : %.2f  Width : %.2f\n", r.height, r.width);
    printf("\t Radius of the corners : %.2fx and %.2fy \n", r.xradius,r.yradius);
    printf("\n");
}

square_t createSquare(void){
    square_t c;
    printf("You are now creating a square.\n");
    printf("Where does your square start ?\n");
    printf("\n");
    float x;
    float y;
    printf("x position : ");
    scanf("%f", &x);
    printf("y position : ");
    scanf("%f", &y);

    printf("Now, what will be the dimensions of your square's borders ?\n");
    float d;
    scanf("%f", &d);

    printf("Now let's make the corners of your square.\n");
    float rx = 0;
    float ry = 0;

    printf("So, what's the x radius of the corners ?\n");
    scanf("%f", &rx);
    printf("And to finish, what is the y radius of the corners ?\n");
    scanf("%f", &ry);

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
    printf("\t Start postition : %.2f;%.2f\n", c.xpos, c.ypos);
    printf("\t Size : %.2f x %.2f", c.dimension, c.dimension);
    printf("\t Radius of the corners : %.2fx and %.2fy \n", c.xradius,c.yradius);
    printf("\n");
}

circle_t createCicrcle(void){
    circle_t c;
    printf("You are now creating a circle.\n");
    printf("Where's the center of your circle ?\n");
    printf("\n");
    float x;
    float y;
    printf("x position : ");
    scanf("%f", &x);
    printf("y position : ");
    scanf("%f", &y);

    printf("And to finsh, what's the radius of your circle ?\n");
    float r;
    scanf("%f", &r);
    printf("Your circle is now made !\n");
    c.xpos = x;
    c.ypos = y;
    c.radius = r;
    return c;
}

void getCircle(circle_t c){
    printf("Here's your circle : \n");
    printf("\n");
    printf("\t Position of your circle : %.2f;%.2f \n", c.xpos, c.ypos);
    printf("\t Radius of the circle : %.2f \n", c.radius);
    printf("\n");
}

ellipse_t createEllipse(void){
    ellipse_t e;
    printf("You are now creating an ellipse.\n");
    printf("Where's the center of your ellipse ?\n");
    printf("\n");
    float x;
    float y;
    printf("x position : ");
    scanf("%f", &x);
    printf("y position : ");    
    scanf("%f", &y);

    printf("Now, what's the x radius of your ellipse ?\n");
    float xr;
    scanf("%f", &xr);
    printf("And to finish, what is the y radius of your ellipse ?\n");
    float yr;
    scanf("%f", &yr);
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
    printf("\t Position of your ellipse : %.2f;%.2f \n", e.xpos, e.ypos);
    printf("\t Lenght of your ellipse(x radius) : %.2f \n", e.xradius);
    printf("\t Height of your ellipse(y radius) : %.2f \n", e.yradius);
    printf("\n");
}

line_t createLine(void){
    line_t l;
    printf("You are now creating a line.\n");
    printf("What is the position of the begining of your line ?\n");
    printf("\n");
    float xs;
    float ys;
    printf("x position : ");
    scanf("%f", &xs);
    printf("\n");
    printf("y position : ");
    scanf("%f", &ys);
    printf("\n");
    printf("Good! Now what's the position of the ending of your line ?\n");
    printf("\n");
    float xe;
    float ye;
    printf("x position : ");
    scanf("%f", &xe);
    printf("\n");
    printf("y position : ");
    scanf("%f", &ye);
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
    printf("\t Begining point : %.2f;%.2f \n", l.xstart, l.ystart);
    printf("\t Ending point : %.2f;%.2f \n", l.xend,l.yend);
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
    float xs;
    float ys;
    printf("x position : ");
    scanf("%f", &xs);
    printf("y position : ");
    scanf("%f", &ys);
    float x;
    float y;
    line_t currentLine;
    currentLine.xstart = xs;
    currentLine.ystart = ys;
    for (int i = 0; i < nb; i++){
        printf("What's the point n %d of your polyline ?\n", i+2);
        printf("x position : ");
        scanf("%f", &x);
        printf("y position : ");
        scanf("%f", &y);

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
        printf("\t Line n %d :  Start: %.2f;%.2f\n", i+1, pl.lines[i].xstart,pl.lines[i].ystart);
        printf("\t            End: %.2f;%.2f\n",pl.lines[i].xend, pl.lines[i].yend);

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
    float xs;
    float ys;
    printf("x position : ");
    scanf("%f", &xs);
    printf("y position : ");
    scanf("%f", &ys);
    float x;
    float y;
    line_t currentLine;
    currentLine.xstart = xs;
    currentLine.ystart = ys;
    for (int i = 0; i < nb-1; i++){
        printf("What's the point n %d of your polylgon ?\n", i+2);
        printf("x position : ");
        scanf("%f", &x);
        printf("y position : ");
        scanf("%f", &y);

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
        printf("\t Point n %d: %.2f;%.2f \n", i+1, pg.lines[i].xstart, pg.lines[i].ystart);
    }
    printf("\n");
}