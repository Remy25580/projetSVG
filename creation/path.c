#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"
#include "deletion.h"
#include "color.h"
#include "saveManagement.h"

path_t *createPath(path_t *t, int editing){
    if(editing == 0){
        t = malloc(1 * sizeof(path_t));
        printf("You are now creating a path.\n");
    }
    
    t->size = 0;
    int nb = 0;

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

    operationComplete temp;

    char op;
    
    int creating = 0;
    int unvalidOperation;
    while(creating == 0){        
        printf("What operation do you wanna use on your path? \n");
        printf("M, L, H, V, Z, C, S, Q, T, A, or D to stop.\n");
        unvalidOperation = 0;



        
        scanf("%s", &op);
        switch (op){
            case 'D':
                creating = 1;
                unvalidOperation = 1;
                printf("Your path is now made! \n");
                break;
            case 'M':
                temp.opt = M;
                printf("What is the position where you want to move in ? \n");
                printf("x position : ");
                x = inputPositiveFloat(0);
                printf("y position : ");
                y = inputPositiveFloat(0);
                printf("\n");
                temp.op.m.xpos = x;
                temp.op.m.ypos = y;
                printf("You moved to that point!\n");
                break;
            case 'L':
                temp.opt = L;
                printf("To what point do you want to draw a line ?\n");
                printf("x position : ");
                x = inputPositiveFloat(0);
                printf("y position : ");
                y = inputPositiveFloat(0);
                printf("\n");
                temp.op.l.xpos = x;
                temp.op.l.ypos = y;
                printf("You drew a line to that point !\n");
                break;
            case 'H':
                temp.opt = H;
                printf("To what x-axis do you want to draw a horizontal line ? \n");
                printf("x-axis : ");
                x = inputPositiveFloat(0);
                printf("\n");
                temp.op.h.xpos = x;
                printf("You drew a horizontal line to that axis !\n");
                break;
            case 'V':
                temp.opt = V;
                printf("To what y-axis do you want to draw a vertical line? \n");
                printf("y-axis : ");
                y = inputPositiveFloat(0);
                printf("\n");
                temp.op.v.ypos = y;
                printf("You drew a vertical line to that axis !\n");
                break;
            case 'Z':
                temp.opt = Z;
                printf("You drew a line to the last unclosed point !\n");
                temp.op.z.verif = 0;
                break;
            case 'C':
                temp.opt = C;
                printf("To what point do you want to create a cubic curve ?\n");
                printf("x position : ");
                x = inputPositiveFloat(0);
                printf("y position : ");
                y = inputPositiveFloat(0);
                printf("\n");
                printf("Now, what's the control point for the start of your curve ?\n");
                printf("x position : ");
                xpent1 = inputPositiveFloat(0);
                printf("y position : ");
                ypent1 = inputPositiveFloat(0);
                printf("\n");
                printf("And, what's the control point for the end of your curve ?\n");
                printf("x position : ");
                xpent2 = inputPositiveFloat(0);
                printf("y position : ");
                ypent2 = inputPositiveFloat(0);
                printf("\n");
                temp.op.c.xend = x;
                temp.op.c.yend = y;
                temp.op.c.xpent1 = xpent1;
                temp.op.c.ypent1 = ypent1;
                temp.op.c.xpent2 = xpent2;
                temp.op.c.ypent2 = ypent2;
                printf("You drew a cubic curve !\n");
                break;
            case 'S':
                temp.opt = S;
                printf("To what point do you want to draw that cubic curve ?\n");
                printf("x position : ");
                x = inputPositiveFloat(0);
                printf("y position : ");
                y = inputPositiveFloat(0);
                printf("\n");
                printf("And now, what will be the control point for the end of that curve ?\n");
                printf("x position : ");
                xpent2 = inputPositiveFloat(0);
                printf("y position : ");
                ypent2 = inputPositiveFloat(0);
                printf("\n");
                temp.op.s.xend = x;
                temp.op.s.yend = y;
                temp.op.s.xpent2 = xpent2;
                temp.op.s.ypent2 = ypent2;
                printf("You drew a cubic curve !\n");
                break;
            case 'Q':
                temp.opt = Q;
                printf("To what point do you want to create a quadratic curve ?\n");
                printf("x position : ");
                x = inputPositiveFloat(0);
                printf("y position : ");
                y = inputPositiveFloat(0);
                printf("\n");
                printf("And, what will be the control point of your curve ?\n");
                printf("x position : ");
                xpent1 = inputPositiveFloat(0);
                printf("y position : ");
                ypent1 = inputPositiveFloat(0);
                printf("\n");
                temp.op.q.xend = x;
                temp.op.q.yend = y;
                temp.op.q.xpent1 = xpent1;
                temp.op.q.ypent1 = ypent1;
                printf("You drew a quadratic curve !\n");
                break;
            case 'T':
                temp.opt = T;
                printf("To what point do you want to draw that quadratic curve ?\n");
                printf("x position : ");
                x = inputPositiveFloat(0);
                printf("y position : ");
                y = inputPositiveFloat(0);
                printf("\n");
                temp.op.t.xend = x;
                temp.op.t.yend = y;
                printf("You drew a quadratic curve ! \n");
                break;
            case 'A':
                temp.opt = A;
                printf("First of all, to what point will your arc go ?\n");
                printf("x position : ");
                x = inputPositiveFloat(0);
                printf("y position : ");
                y = inputPositiveFloat(0);
                printf("\n");
                printf("Now, what are the radiuses of the ellipse to make your arc ?\n");
                printf("x radius (lenght) : ");
                xr = inputPositiveFloat(1);
                printf("y radius (height) : ");
                yr = inputPositiveFloat(1);
                printf("\n");
                printf("What will be the rotation of that ellipse, to draw your arc ?\n");
                while(scanf("%f", &rotation)!= 1){
                    printf("ERROR: a float is required here, please type again.\n");
                    while (getchar() != '\n');
                }
                printf("\n");
                printf("So, will the small or big side of the ellipse be drawn as an arc ?\n");
                printf("Type 0 for the small, or 1 for the big ");
                side = zeroOrOne();
                printf("And to finish, will the arc be drawn at positive angles or negative ones ?\n");
                printf("Type 0 for the negative, or 1 for the positive ");
                drawingWay = zeroOrOne();
                temp.op.a.xend = x;
                temp.op.a.yend = y;
                temp.op.a.xradius = xr;
                temp.op.a.yradius = yr;
                temp.op.a.rotation = rotation;
                temp.op.a.side = side;
                temp.op.a.drawingWay = drawingWay;
                printf("You drew an arc !\n");
                break;
            default:
                printf("That operation is not recognized, please type again.\n");
                unvalidOperation = 1;
                break;
        }
        if(unvalidOperation == 0){
            nb++;
            if(t->size == 0){
                t->list = malloc(nb * sizeof(operationComplete));
                t->list[0] = temp;
                t->size = t->size + 1;

            }
            else{
                operationComplete *listTemp = realloc(t->list, nb * sizeof(operationComplete));
                t->list = listTemp;
                t->list[t->size] = temp;
                t->size = t->size + 1;
            }
        }
        
    }
    return t;
}

void getPath(path_t *p){
    operationComplete currentOp;
    for(int i = 0; i < p->size; i++){
        currentOp = p->list[i];

        switch(currentOp.opt){
            case M:
                printf("\t -Moved to the point %.2f;%.2f\n", currentOp.op.m.xpos, currentOp.op.m.ypos);
                break;
            case L:
                printf("\t -Drew a line to the point %.2f;%.2f\n", currentOp.op.l.xpos,currentOp.op.l.ypos);
                break;
            case H:
                printf("\t -Drew a horizontal line to the x-axis %.2f\n", currentOp.op.h.xpos);
                break;
            case V:
                printf("\t -Drew a vertical line to the y-axis %.2f\n", currentOp.op.v.ypos);
                break;
            case Z:
                printf("\t -Drew a line to the last unclosed point\n");
                break;
            case C:
                printf("\t -Drew a cubic curve to the point %.2f;%.2f\n", currentOp.op.c.xpent1, currentOp.op.c.ypent1);
                printf("\t with a first control point at %.2f;%.2f\n", currentOp.op.c.xpent1, currentOp.op.c.ypent1);
                printf("\t and a second control point at %.2f;%.2f\n", currentOp.op.c.xpent2, currentOp.op.c.ypent2);
                break;
            case S:
                printf("\t -Drew a mirror cubic curve to the previous one, to the point %.2f;%.2f\n",
                currentOp.op.s.xend, currentOp.op.s.yend);
                printf("\t with a second control point at %.2f;%.2f\n", currentOp.op.s.xpent2, currentOp.op.s.ypent2);
                break;
            case Q:
                printf("\t -Drew a quadratic curve to the point %.2f;%.2f\n", currentOp.op.q.xend, currentOp.op.q.yend);
                printf("\t with a control point at %.2f;%.2f\n", currentOp.op.q.xpent1, currentOp.op.q.ypent1);
                break;
            case T:
                printf("\t -Drew a mirror quadratic curve to the previous one, to the point %.2f;%.2f\n",
                currentOp.op.t.xend, currentOp.op.t.yend);
                break;
            case A:
                printf("\t -Drew an arc to the point %.2f;%.2f\n", currentOp.op.a.xend, currentOp.op.a.yend);
                printf("\t That arc was drawn with an ellipse, which : \n");
                printf("\t \t ->has a x radius of %.2f and an y radius of %.2f\n", currentOp.op.a.xradius, currentOp.op.a.yradius);
                printf("\t \t ->has a inclination of %.2f\n", currentOp.op.a.rotation);
                if(currentOp.op.a.side == 0){
                    printf("\t \t ->little side has been drawn\n");
                }
                else{
                    printf("\t \t ->big side has been drawn\n");
                }
                if(currentOp.op.a.drawingWay == 0){
                    printf("\t \t ->has been drawn by the negative angles\n");
                }
                else{
                    printf("\t \t ->has been drawn by the positive angles\n");
                }
                break;
            default:
                printf("error: unknown operation type\n");
                break;
        }
    }
}