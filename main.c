#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation/creation.h"
#include "creation/path.h"
#include "creation/userInterface.h"
#include "creation/deletion.h"
#include "creation/color.h"
#include "creation/saveManagement.h"

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
        printf("3 - Stylish shapes\n");
        printf("4 - Save shapes\n");
        printf("5 - Load shapes\n");
        printf("6 - View your shapes\n");
        printf("7 - Delete a shape\n");
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
                break;
            case(2):
                if(loaded == 0){
                    printf("No shapes have been loaded yet, please create or load some.\n");
                }
                else{
                    editShapes(newCreation);
                }
                break;
            case(3):
                if(loaded == 0){
                    printf("No shapes have been loaded yet, please create or load some.\n");
                }
                else{
                    stylishShapes(newCreation);
                }
                break;
            case(4):
                if (loaded == 0){
                    printf("No shapes have been loaded yet, please create or load some.\n");
                }
                else{
                    saveShapes(newCreation);
                }
                break;
            case(5):
                if (loaded == 1){
                    printf("Shapes are already loaded, you cannot load others.\n");
                }
                else{
                    loadShapes(newCreation);
                    loaded = 1;
                }
                break;
            case(6):
                if (loaded == 0){
                    printf("No shapes have been loaded yet, please create or load some.\n");
                    break;
                }
                else{
                    getShapes(newCreation);
                    break;
                }
                break;
            case(7):
                if(loaded == 0){
                    printf("No shapes have been loaded yet, please create or load some.\n");
                }
                else{
                    deleteShape(newCreation);
                }
                break;
            case(0):
                end =1;
                break;
            default:
                printf("Invalid action, please retype.\n");
                break;

        }
        if(newCreation->nb == 0){
            loaded = 0;
        }
    }
    return EXIT_SUCCESS;
}