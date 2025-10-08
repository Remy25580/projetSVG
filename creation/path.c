#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "path.h"

path_t createPath(void){
    int x;
    int y;
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
                scanf("%d", &x);
                printf("y position : ");
                scanf("%d", &y);
                currentNode.elt.m.xpos = x;
                currentNode.elt.m.ypos = y;
                printf("You moved to that point!\n");
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