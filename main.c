#include <stdio.h>
#include <stdlib.h>
#include "creation/creation.h"
#include "creation/path.h"
#include "creation/userInterface.h"
#include "creation/deletion.h"

int main(void){
    int end = 0;
    int choice = 1;
    int loaded = 0;
    shapeGroup_t *newCreation = malloc(1 * sizeof(shapeGroup_t));
    printf("Welcome to that SVG editor.\n");
    while(end == 0){
        printf("What do you want to do ?\n");
        printf("1 - Create new shapes\n");
        printf("2 - Edit shapes\n");
        printf("3 - Save shapes\n");
        printf("4 - Load shapes\n");
        printf("5 - View your shapes\n");
        printf("6 - Delete a shape\n");
        printf("0 - Exit\n");
        printf("\n");

        scanf("%d", &choice);
        switch (choice){
            case(1):
                if (loaded == 0){
                    loaded = 1;
                    newCreation->nb = 0;
                    newCreation->head = NULL;
                }
                newCreation = shapeCreation(newCreation);
                printf("%d\n", newCreation->nb);
                break;
            case(2):
                break;
            case(3):
                break;
            case(4):
                break;
            case(5):
                if (loaded == 0){
                    printf("No shapes have been loaded yet, please create or load some.\n");
                    break;
                }
                else{
                    getShapes(newCreation);
                    break;
                }
                break;
            case(6):
                if(loaded == 0){
                    printf("No shapes have been loaded yet, please create or load some.\n");
                }
                else{
                    printf("You can delete shapes but the function doesnt exist yet\n");
                }
                break;
            case(0):
                end =1;
                break;
            default:
                printf("Invalid action, please retype.\n");
                break;
        }
    }
    return EXIT_SUCCESS;
}