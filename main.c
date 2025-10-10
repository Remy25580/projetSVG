#include <stdio.h>
#include <stdlib.h>
#include "creation/creation.h"
#include "creation/path.h"
#include "creation/userInterface.h"

int main(void){
    int choice = 1;
    printf("Welcome to that SVG editor.\n");
    while(choice > 0 && choice < 6){
        printf("What do you want to do ?\n");
        printf("1 - Create new shapes\n");
        printf("2 - Edit shapes\n");
        printf("3 - Save shapes\n");
        printf("4 - Load shapes\n");
        printf("5 - View your shapes\n");
        printf("0 - Exit\n");
        printf("\n");

        scanf("%d", &choice);
        switch (choice){
            case(0):
                break;
            case(1):
                break;
            case(2):
                break;
            case(3):
                break;
            case(4):
                break;
            case(5):
                break;
            default:
                break;
        }
    }
    return EXIT_SUCCESS;
}