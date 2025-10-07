#include <stdio.h>
#include <stdlib.h>
#include "creation.h"


// Définitions d'unions


// Définitions d'énumérations



//Définitions de fonctions

rectangle_t createRectangle(void){
    rectangle_t r;
    printf("You are now creating a rectangle.\n");
    printf("What's the x position where starts your rectangle ?\n");
    int x;
    scanf("%d", &x);
    printf("Great! Now what's the y postition where starts your rectangle ?\n");
    int y;
    scanf("%d", &y);
    printf("And now, what will be the height of your rectangle ?\n");
    int h;
    scanf("%d", &h);
    printf("And what will be the width of your rectangle ?\n");
    int w;
    scanf("%d", &w);
    printf("Your rectangle is now made! \n");
    r.xpos = x;
    r.ypos = y;
    r.height = h;
    r.width = w;
    
    return r;

}

void getRectangle(rectangle_t r){
    printf("Here's your rectangle: \n");
    printf("\n");
    printf("\t Start postition : %d;%d\n", r.xpos, r.ypos);
    printf("\t Height : %d  Width : %d\n", r.height, r.width);
    printf("\n");
}

square_t createSquare(void){
    square_t c;
    printf("You are now creating a square.\n");
    printf("What's the x position where starts your square ?\n");
    int x;
    scanf("%d", &x);
    printf("Great! Now what's the y postition where starts your square ?\n");
    int y;
    scanf("%d", &y);
    printf("And now, what will be the dimensions of your square's borders ?\n");
    int d;
    scanf("%d", &d);
    printf("Your square is now made! \n");
    c.xpos = x;
    c.ypos = y;
    c.dimension = d;
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
    printf("What's the x position of your circle's center ?\n");
    int x;
    scanf("%d", &x);
    printf("Great! Now, what's the y position of your circle's center ?\n");
    int y;
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
    printf("What's the x position of your ellipse's center ?\n");
    int x;
    scanf("%d", &x);
    printf("Great! Now, what's the y position of your ellipse's center ?\n");
    int y;
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
    printf("\t Height of yout ellipse(y radius) : %d \n", e.yradius);
    printf("\n");
}