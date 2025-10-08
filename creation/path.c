#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "path.h"

path_t createPath(void){
    float x;
    float y;
    nodePath *prev;
    path_t t;
    printf("You are now creating a path.\n");
    int creating = 0;
    while(creating == 0){
        nodePath currentNode;
        currentNode.next = NULL;
        currentNode.previous = NULL;
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
                currentNode.elt.l.xpos = x;
                currentNode.elt.l.ypos = y;
                printf("You draw a line to that point !\n");
                break;
            case H:
                currentNode.eltType = L;
                printf("To what x-axis do you want to draw a horizontal line ? \n");
                printf("x-axis : ");
                scanf("%f", &x);
                currentNode.elt.h.xpos = x;
                printf("You draw a horizontal line to that axis !\n");
                break;
            case V:
                currentNode.eltType = V;
                printf("To what y-axis do you want to draw a vertical line? \n");
                printf("y-axis : ");
                scanf("%f", &y);
                currentNode.elt.v.ypos = y;
                printf("You drax a vertical line to that axis !\n");
                break;
            case Z:
                currentNode.eltType = Z;
                printf("You draw a line to the last unclosed point !\n");
                currentNode.elt.z.verif = 0;
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