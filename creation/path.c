#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "path.h"

path_t createPath(void){
    float x;
    float y;
    float xpent1;
    float ypent1;
    float xpent2;
    float ypent2;
    float xr;
    float yr;
    float rotation;
    int side;
    int drawingWay;

    nodePath *prev;
    path_t t;
    nodePath currentNode;
    currentNode.next = NULL;
    currentNode.previous = NULL;
    printf("You are now creating a path.\n");
    int creating = 0;
    while(creating == 0){        
        printf("What operation do you wanna use on your path? \n");
        printf("M, L, H, V, Z, C, S, Q, T, A, or D to stop.\n");

        operationType op;
        scanf("%c", &op);
        switch (op){
            case D:
                printf("Your path is now made! \n");
                return t;
                creating = 1;
                break;
            case M:
                currentNode.eltType = M;
                printf("What is the position where you want to move in ? \n");
                printf("x position : ");
                scanf("%f", &x);
                printf("y position : ");
                scanf("%f", &y);
                printf("\n");
                currentNode.elt.m.xpos = x;
                currentNode.elt.m.ypos = y;
                printf("You moved to that point!\n");
                break;
            case L:
                currentNode.eltType = L;
                printf("To what point do you want to draw a line ?\n");
                printf("x position : ");
                scanf("%f", &x);
                printf("y position : ");
                scanf("%f", &y);
                printf("\n");
                currentNode.elt.l.xpos = x;
                currentNode.elt.l.ypos = y;
                printf("You drew a line to that point !\n");
                break;
            case H:
                currentNode.eltType = L;
                printf("To what x-axis do you want to draw a horizontal line ? \n");
                printf("x-axis : ");
                scanf("%f", &x);
                printf("\n");
                currentNode.elt.h.xpos = x;
                printf("You drew a horizontal line to that axis !\n");
                break;
            case V:
                currentNode.eltType = V;
                printf("To what y-axis do you want to draw a vertical line? \n");
                printf("y-axis : ");
                scanf("%f", &y);
                printf("\n");
                currentNode.elt.v.ypos = y;
                printf("You drew a vertical line to that axis !\n");
                break;
            case Z:
                currentNode.eltType = Z;
                printf("You drew a line to the last unclosed point !\n");
                currentNode.elt.z.verif = 0;
                break;
            case C:
                currentNode.eltType = C;
                printf("To what point do you want to create a cubic curve ?\n");
                printf("x position : ");
                scanf("%f", &x);
                printf("y position : ");
                scanf("%f", &y);
                printf("\n");
                printf("Now, what's the control point for the start of your curve ?\n");
                printf("x position : ");
                scanf("%f", &xpent1);
                printf("y position : ");
                scanf("%f", &ypent1);
                printf("\n");
                printf("And, what's the control point for the end of your curve ?\n");
                printf("x position : ");
                scanf("%f", &xpent2);
                printf("y position : ");
                scanf("%f", &ypent2);
                printf("\n");
                currentNode.elt.c.xend = x;
                currentNode.elt.c.yend = y;
                currentNode.elt.c.xpent1 = xpent1;
                currentNode.elt.c.ypent1 = ypent1;
                currentNode.elt.c.xpent2 = xpent2;
                currentNode.elt.c.ypent2 = ypent2;
                printf("You drew a cubic curve !\n");
                break;
            case S:
                currentNode.eltType = S;
                printf("To what point do you want to draw that cubic curve ?\n");
                printf("x position : ");
                scanf("%f", &x);
                printf("y position : ");
                scanf("%f", &y);
                printf("\n");
                printf("And now, what will be the control point for the end of that curve ?\n");
                printf("x position : ");
                scanf("%f", &xpent2);
                printf("y position : ");
                scanf("%f", &ypent2);
                printf("\n");
                currentNode.elt.s.xend = x;
                currentNode.elt.s.yend = y;
                currentNode.elt.s.xpent2 = xpent2;
                currentNode.elt.s.ypent2 = ypent2;
                printf("You drew a cubic curve !\n");
                break;
            case Q:
                currentNode.eltType = Q;
                printf("To what point do you want to create a quadratic curve ?\n");
                printf("x position : ");
                scanf("%f", &x);
                printf("y position : ");
                scanf("%f", &y);
                printf("\n");
                printf("And, what will be the control point of your curve ?\n");
                printf("x position : ");
                scanf("%f", &xpent1);
                printf("y position : ");
                scanf("%f", &ypent1);
                printf("\n");
                currentNode.elt.q.xend = x;
                currentNode.elt.q.yend = y;
                currentNode.elt.q.xpent1 = xpent1;
                currentNode.elt.q.ypent1 = ypent1;
                printf("You drew a quadratic curve !\n");
                break;
            case T:
                currentNode.eltType = T;
                printf("To what point do you want to draw that quadratic curve ?\n");
                printf("x position : ");
                scanf("%f", &x);
                printf("y position : ");
                scanf("%f", &y);
                printf("\n");
                currentNode.elt.t.xend = x;
                currentNode.elt.t.yend = y;
                printf("You drew a quadratic curve ! \n");
                break;
            case A:
                currentNode.eltType = A;
                printf("First of all, to what point will your arc go ?\n");
                printf("x position : ");
                scanf("%f", &x);
                printf("y position : ");
                scanf("%f", &y);
                printf("\n");
                printf("Now, what are the radiuses of the ellipse to make your arc ?\n");
                printf("x radius (lenght) : ");
                scanf("%f", &xr);
                printf("y radius (height) : ");
                scanf("%f", &yr);
                printf("\n");
                printf("What will be the rotation of that ellipse, to draw your arc ?\n");
                scanf("%s", &rotation);
                printf("\n");
                printf("So, will the small or big side of the ellipse be drawn as an arc ?\n");
                printf("Type 0 for the small, or 1 for the big ");
                scanf("%d", &side);
                if(side != 0 && side != 1){
                    side = 1;
                    printf("If a value other than 0 or 1 has been typed, it'll be considered as 1.\n");
                }
                printf("And to finish, will the arc be drawn at positive angles or negative ones ?\n");
                printf("Type 0 for the negative, or 1 for the positive ");
                scanf("%d", &drawingWay);
                if(drawingWay != 0 && drawingWay != 1){
                    drawingWay = 1;
                    printf("If a value other then 0 or 1 has been typed, it'll be considered as 1.\n");
                }
                currentNode.elt.a.xend = x;
                currentNode.elt.a.yend = y;
                currentNode.elt.a.xradius = xr;
                currentNode.elt.a.yradius = yr;
                currentNode.elt.a.rotation = rotation;
                currentNode.elt.a.side = side;
                currentNode.elt.a.drawingWay = drawingWay;
                printf("You drew an arc !\n");
                break;
            default:
                printf("That operation is not recognized, please type again.\n");
                break;
        }
        if (t.l.firstOperation == NULL){
            t.l.firstOperation = &currentNode;
        }
        else{
            prev = t.l.firstOperation;
            while (prev->next != NULL){
                prev = prev->next;
            }
            prev->next = currentNode;
            currentNode.previous = prev;
        }
    }
}