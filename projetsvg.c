#include <stdio.h>
#include <stdlib.h>
#include "projetsvg.h"


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

carre_t createSquare(void){
    carre_t c;
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

void getSquare(carre_t c){
    printf("Here's your square: \n");
    printf("\n");
    printf("\t Start postition : %d;%d\n", c.xpos, c.ypos);
    printf("\t Size : %dx%d", c.dimension, c.dimension);
    printf("\n");
}