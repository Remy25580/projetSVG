#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"
#include "deletion.h"
#include "color.h"
#include "saveManagement.h"

void addInList(shapeGroup_t *list, shapesElt *elt){
    if(list->nb == 0){
        list->head = elt;
        list->head->next = NULL;
        list->head->previous = NULL;
    }
    else{
        shapesElt *current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = elt;
        elt->previous = current;
        elt->next = NULL;
    }
    list->nb = list->nb + 1;
}


shapeGroup_t *shapeCreation(shapeGroup_t *g){
    int end = 0;
    int err;
    int creation = 0;
    char *name = malloc(sizeof(char) * 20);
    shapesElt *current;

    
    while(end == 0){
        current = malloc(1*sizeof(shapesElt));
        err = 0;
        printf("What shape do you want to make ?\n");
        printf("1 - rectangle\n");
        printf("2 - square\n");
        printf("3 - circle\n");
        printf("4 - ellipse\n");
        printf("5 - line\n");
        printf("6 - polyline\n");
        printf("7 - polygon\n");
        printf("8 - path\n");
        printf("0 - exit the shapes creation\n");
        printf("\n");
        while(scanf("%d", &creation)!= 1){
            printf("ERROR: an integer is required here, please type again.\n");
            while (getchar() != '\n');
        }
        switch (creation){
            case(1):
                current->shpType = RECTANGLETYPE;
                current->shp.rectangle = createRectangle(NULL, 0);
                printf("How do you want to name your rectangle ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                current->style = NULL;
                printf("\n");
                end = 1;
                break;
            case(2):
                current->shpType = SQUARETYPE;
                current->shp.square = createSquare(NULL, 0);
                printf("How do you want to name your square ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                current->style = NULL;
                printf("\n");
                end = 1;
                break;
            case(3):
                current->shpType = CIRCLETYPE;
                current->shp.circle = createCicrcle(NULL, 0);
                printf("How do you want to name your circle ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                current->style = NULL;
                printf("\n");
                end = 1;
                break;
            case(4):
                current->shpType = ELLIPSETYPE;
                current->shp.ellipse = createEllipse(NULL, 0);
                printf("How do you want to name your ellipse ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                current->style = NULL;
                printf("\n");
                end = 1;
                break;
            case(5):
                current->shpType = LINETYPE;
                current->shp.line = createLine(NULL, 0);
                printf("How do you want to name your line ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                current->style = NULL;
                printf("\n");
                end = 1;
                break;
            case(6):
                current->shpType = POLYLINETYPE;
                current->shp.polyline = createPolyline(NULL, 0);
                printf("How do you want to name your polyline ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                current->style = NULL;
                printf("\n");
                end = 1;
                break;
            case(7):
                current->shpType = POLYGONTYPE;
                current->shp.polygon = createPolygon(NULL, 0);
                printf("How do you want to name your polygon ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                current->style = NULL;
                printf("\n");
                end = 1;
                break;
            case(8):
                current->shpType = PATHTYPE;
                current->shp.path = createPath(NULL, 0);
                printf("How do you want to name your path ?(20 characters maximum)\n");
                scanf("%19s", name);
                current->name = name;
                current->style = NULL;
                printf("\n");
                end = 1;
                break;
            case(0):
                end = 1;
                err = 1;
                break;
            default:
                err = 1;
                printf("That shape can't be created, please type again.\n");
                break;

            

        }
        if (end ==1 && err == 0){
            addInList(g, current);
        }

    }
    
    return g;
}

void getShapes(shapeGroup_t *s){
    printf("There are your shapes : \n");
    shapesElt *current = s->head;
    while(current != NULL){
        switch(current->shpType){
            case(RECTANGLETYPE):
                printf("Here's your rectangle, %s : \n", current->name);
                getRectangle(current->shp.rectangle);
                break;
            case(SQUARETYPE):
                printf("Here's your square, %s : \n", current->name);
                getSquare(current->shp.square);
                break;
            case(CIRCLETYPE):
                printf("Here's your circle, %s : \n", current->name);
                getCircle(current->shp.circle);
                break;
            case(ELLIPSETYPE):
                printf("Here's your ellipse, %s : \n", current->name);
                getEllipse(current->shp.ellipse);
                break;
            case(LINETYPE):
                printf("Here's your line, %s : \n", current->name);
                getLine(current->shp.line);
                break;
            case(POLYLINETYPE):
                printf("Here's your polyline, %s : \n", current->name);
                getPolyline(current->shp.polyline);
                break;
            case(POLYGONTYPE):
                printf("Here's your polygon, %s : \n", current->name);
                getPolygon(current->shp.polygon);
                break;
            case(PATHTYPE):
                printf("Here's your path, %s : \n", current->name);
                getPath(current->shp.path);
                break;
            default:
                break;
        }
        if(current->style !=NULL){
            if(strcmp(current->style->color, "none") != 0){
                printf("\t Color of the contour : %s\n", current->style->color);
            }
            if(strcmp(current->style->fillColor, "none") != 0){
                printf("\t Filling color of the shape : %s\n", current->style->fillColor);
            }
            if(current->style->rotate != 0){
                printf("\t Rotation of the shape with an angle of : %.2f\n", current->style->rotate);
            }
            if(current->style->xtranslate !=0 || current->style->ytranslate != 0){
                printf("\t Shape translated to %.2f;%.2f\n", current->style->xtranslate, current->style->ytranslate);
            }
            if(current->style->xinvert == 1){
                printf("\t Shape inverted on the x-axis\n");
            }
            if(current->style->yinvert == 1){
                printf("\t Shape inverted on the y-axis\n");
            }
        }
        printf("\n");
        current = current->next;
    }

}

void deleteShape(shapeGroup_t *s){
    int deleted = 0;
    int i;
    shapesElt *printingElt;
    shapesElt *current;
    int choice;
    while(deleted == 0){
        printingElt = s->head;
        i = 1;
        while(printingElt != NULL){
            printf("%d - %s\n", i, printingElt->name);
            i++;
            printingElt = printingElt->next;
        }
        printf("What shape do you want to delete ? Please enter its number (0 to cancel)\n");

        while(scanf("%d", &choice)!= 1){
            printf("ERROR: an integer is required here, please type again.\n");
            while (getchar() != '\n');
        }

        if(choice < 1){
            deleted = 1;
            break;
        }

        if(choice > s->nb){
            printf("No shape of yours is attributed to this number, please type again\n");
        }

        else{
            s->nb = s->nb - 1;
            current = s->head;
            if(choice == 1){
                if(s->head->next == NULL){
                    s->head = NULL;
                }
                else{
                    s->head = s->head->next;
                    s->head->previous = NULL;
                }
                freeShape(current);
            }
            else{
                while(choice > 1){
                    current = current->next;
                    choice--;
                }
                if (current->next == NULL) {
                    current->previous->next = NULL;
                }
                else{
                    current->next->previous = current->previous;
                    current->previous->next = current->next;
                }
                freeShape(current);
            }
            deleted = 1;
        }
    }
}

void stylishShapes(shapeGroup_t *s){
    int edited = 0;
    shapesElt *printingElt;
    int i;
    int choice;
    int choice2;
    shapeStyle *st = malloc(1*sizeof(shapeStyle));
    st->color = "none";
    st->fillColor = "none";
    st->rotate = 0;
    st->xtranslate = 0;
    st->ytranslate = 0;
    st->xinvert = 0;
    st->yinvert = 0;

    float x;
    float y;
    float r;
    shapesElt *editing;


    while(edited == 0){
        printingElt = s->head;
        i = 1;
        while(printingElt != NULL){
            printf("%d - %s\n", i, printingElt->name);
            i++;
            printingElt = printingElt->next;
        }
        printf("What shape do you want to stylish ? Please enter its number (0 to cancel)\n");
        while(scanf("%d", &choice)!= 1){
            printf("ERROR: an integer is required here, please type again.\n");
            while (getchar() != '\n');
        }

        if(choice < 0 || choice > s->nb){
            printf("No shape of yours is attributed to this number, please type again\n");
        }
        else{
            if(choice == 0){
                edited = 1;
            }

            else{
                editing = s->head;
                if(choice > 1){
                    editing = editing->next;
                    choice--;
                }
                if(editing->style != NULL){
                    st = editing->style;
                }

                while(edited == 0){
                    printf("1 - Change its contour's color\n");
                    printf("2 - Change its filling color\n");
                    printf("3 - Move it to a x;y popsition\n");
                    printf("4 - Rotate it with a angle\n");
                    printf("5 - Invert it on x-axis\n");
                    printf("6 - Invert it on y-axis\n");
                    printf("0 - Cancel\n");
                    printf("How do you want to edit it ?\n");
                    while(scanf("%d", &choice2)!= 1){
                        printf("ERROR: an integer is required here, please type again.\n");
                        while (getchar() != '\n');
                    }

                    if(choice < 0 || choice > s->nb){
                        printf("No shape of yours is attributed to this number, please type again");
                    }
                    if(choice == 0){
                        edited = 1;
                    }

                    else{
                        switch(choice2){
                            case(1):
                                setColor(st, 0);
                                edited = 1;
                                break;
                            case(2):
                                setColor(st, 1);
                                edited = 1;
                                break;
                            case(3):
                                printf("At what point do you want to move it ?\n");
                                printf("x position : ");
                                while(scanf("%f", &x)!= 1){
                                    printf("ERROR: a float is required here, please type again.\n");
                                    while (getchar() != '\n');
                                }
                                printf("y position : ");
                                while(scanf("%f", &y)!= 1){
                                    printf("ERROR: a float is required here, please type again.\n");
                                    while (getchar() != '\n');
                                }
                                st->xtranslate = x;
                                st->ytranslate = y;
                                edited = 1;
                                break;
                            case(4):
                                printf("To what angle do you want it to rotate ?\n");
                                while(scanf("%f", &r)!= 1){
                                    printf("ERROR: a float is required here, please type again.\n");
                                    while (getchar() != '\n');
                                }
                                st->rotate = r;
                                edited = 1;
                                break;
                            case(5):
                                if(st->xinvert == 0){
                                    st->xinvert = 1;
                                }
                                else{
                                    st->xinvert = 0;
                                }
                                printf("Shape inverted by the x-axis\n");
                                edited = 1;
                                break;
                            case(6):
                                if(st->yinvert == 0){
                                    st->yinvert = 1;
                                }
                                else{
                                    st->yinvert = 0;
                                }
                                printf("Shape inverted by the y-axis\n");
                                edited = 1;
                                break;
                            default:
                                printf("Invalid action, please type again\n");
                                break;
                        }
                    }
                }
                editing->style = st;
            }
        }
    }
}

void editShapes(shapeGroup_t *s){
    int edited = 0;
    int i;
    shapesElt *printingElt;
    int choice;
    shapesElt *current;

    while(edited == 0){
        printingElt = s->head;
        i = 1;
        while(printingElt != NULL){
            printf("%d - %s\n", i, printingElt->name);
            i++;
            printingElt = printingElt->next;
        }

        printf("What shape do you want to edit ? Please enter its number (0 to cancel)\n");
        while(scanf("%d", &choice)!= 1){
            printf("ERROR: an integer is required here, please type again.\n");
            while (getchar() != '\n');
        }

        if(choice < 1){
            edited = 1;
            break;
        }

        if (choice > s->nb){
            printf("No shape of yours is attributed to this number. Please type again\n");
        }

        else{
            current = s->head;
            while(choice > 1){
                current = current->next;
                choice--;
            }
            switch(current->shpType){
                case(RECTANGLETYPE):
                    current->shp.rectangle = createRectangle(current->shp.rectangle, 1);
                    edited = 1;
                    break;
                case(SQUARETYPE):
                    current->shp.square = createSquare(current->shp.square, 1);
                    edited = 1;
                    break;
                case(CIRCLETYPE):
                    current->shp.circle = createCicrcle(current->shp.circle, 1);
                    edited = 1;
                    break;
                case(ELLIPSETYPE):
                    current->shp.ellipse = createEllipse(current->shp.ellipse, 1);
                    edited = 1;
                    break;
                case(LINETYPE):
                    current->shp.line = createLine(current->shp.line, 1);
                    edited = 1;
                    break;
                case(POLYLINETYPE):
                    current->shp.polyline = createPolyline(current->shp.polyline, 1);
                    edited = 1;
                    break;
                case(POLYGONTYPE):
                    current->shp.polygon = createPolygon(current->shp.polygon, 1);
                    edited = 1;
                    break;
                case(PATHTYPE):
                    current->shp.path = createPath(current->shp.path, 1);
                    edited = 1;
                    break;
                default:
                    break;
            }
        }
    }
}

float inputPositiveFloat(int zero){
    float val;
    while(0){
        while(scanf("%f", &val) != 1){
            printf("ERROR: a float is required here.\n");
            printf("Please type again : ");
            while (getchar() != '\n');
        }

        if(zero == 0){
            if(val >= 0){
                return val;
            }
            else{
                printf("The value must be positive or 0.\n");
                printf("Please type again  : ");
            }
        }
        else{
            if(val>0){
                return val;
            }
            else{
                printf("The value must be positive.\n");
                printf("Please type again  : ");
            }
        }
    }
}

int inputPositiveInt(int zero){
    int val;
    while(0){
        while(scanf("%d", &val) != 1){
            printf("ERROR: an integer is required here.\n");
            printf("Please type again : ");
            while (getchar() != '\n');
        }

        if(zero == 0){
            if(val >= 0){
                return val;
            }
            else{
                printf("The value must be positive or 0.\n");
                printf("Please type again : ");
            }
        }
        else{
            if(val>0){
                return val;
            }
            else{
                printf("The value must be positive.\n");
                printf("Please type again  : ");
            }
        }
    }
}

int zeroOrOne(void){
    int val;
    while(0){
        while(scanf("%d", &val) != 1){
            printf("ERROR: an integer is required here.\n");
            printf("Please type again : ");
            while (getchar() != '\n');
        }

        if(val == 0 || val == 1){
            return val;
        }
        else{
            printf("The value must be either 0 or 1.\n");
            printf("Please type again : ");
        }
    }
}