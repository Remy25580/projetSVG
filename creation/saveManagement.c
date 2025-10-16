#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"
#include "deletion.h"
#include "color.h"
#include "saveManagement.h"

void saveShapes(shapeGroup_t *s, FILE *ft, char fileNametext[20]){
    int choice = 2;
    int valid = 0;
    shapesElt *current;
    fileNametext = " ";

    while(choice != 0 || choice != 1){
        printf("Are you sure you want to save now ? 0 for no, 1 for yes\n");
        scanf("%d", &choice);
        if(choice == 0){
            break;
        }
    }

    if(choice == 1){

        if(strcmp(fileNametext, " ") == 0){
            while(valid == 0){
                printf("How do you want to name your save file ?\n");
                scanf("%19s", fileNametext);

                if(strstr(fileNametext, ".") != NULL){
                    printf("Invalid file name, you must not put a dot.\n");
                }
                else{
                    valid = 1;
                }
            }
        }
        strcat(fileNametext, ".txt");
        if(ft == NULL){
            ft = fopen(fileNametext, "w");
        }
        else{
            ft = fopen(fileNametext, "a");
        }

        current = s->head;

        while(current != NULL){
            fprintf(ft, "%s\n", current->name);
            switch(current->shpType){
                case(RECTANGLETYPE):
                    fprintf(ft, "RECTANGLETYPE\n");
                    fprintf(ft, "%f\n", current->shp.rectangle->xpos);
                    fprintf(ft, "%f\n", current->shp.rectangle->ypos);
                    fprintf(ft, "%f\n", current->shp.rectangle->height);
                    fprintf(ft, "%f\n", current->shp.rectangle->width);
                    fprintf(ft, "%f\n", current->shp.rectangle->xradius);
                    fprintf(ft, "%f\n", current->shp.rectangle->yradius);
                    break;
                case(SQUARETYPE):
                    fprintf(ft, "SQUARETYPE\n");
                    fprintf(ft, "%f\n", current->shp.square->xpos);
                    fprintf(ft, "%f\n", current->shp.square->ypos);
                    fprintf(ft, "%f\n", current->shp.square->dimension);
                    fprintf(ft, "%f\n", current->shp.square->xradius);
                    fprintf(ft, "%f\n", current->shp.square->yradius);
                    break;
                case(CIRCLETYPE):
                    fprintf(ft, "CIRCLETYPE\n");
                    fprintf(ft, "%f\n", current->shp.circle->xpos);
                    fprintf(ft, "%f\n", current->shp.circle->ypos);
                    fprintf(ft, "%f\n", current->shp.circle->radius);
                    break;
                case(ELLIPSETYPE):
                    fprintf(ft, "ELLIPSETYPE\n");
                    fprintf(ft, "%f\n", current->shp.ellipse->xpos);
                    fprintf(ft, "%f\n", current->shp.ellipse->ypos);
                    fprintf(ft, "%f\n", current->shp.ellipse->xradius);
                    fprintf(ft, "%f\n", current->shp.ellipse->yradius);
                    break;
                case(LINETYPE):
                    fprintf(ft, "LINETYPE\n");
                    fprintf(ft, "%f\n", current->shp.line->xstart);
                    fprintf(ft, "%f\n", current->shp.line->ystart);
                    fprintf(ft, "%f\n", current->shp.line->xend);
                    fprintf(ft, "%f\n", current->shp.line->yend);
                    break;
                case(POLYLINETYPE):
                    fprintf(ft, "POLYLINETYPE\n");
                    fprintf(ft, "%d\n", current->shp.polyline->nbLines);
                    for(int i = 0; i < current->shp.polyline->nbLines; i++){
                        fprintf(ft, "%f\n", current->shp.polyline->lines[i].xstart);
                        fprintf(ft, "%f\n", current->shp.polyline->lines[i].ystart);
                        fprintf(ft, "%f\n", current->shp.polyline->lines[i].xend);
                        fprintf(ft, "%f\n", current->shp.polyline->lines[i].yend);
                    }
                    break;
                case(POLYGONTYPE):
                    fprintf(ft, "POLYGONTYPE\n");
                    fprintf(ft, "%d\n", current->shp.polygon->nbSides);
                    for(int j = 0; j < current->shp.polygon->nbSides; j++){
                        fprintf(ft, "%f\n", current->shp.polygon->lines[j].xstart);
                        fprintf(ft, "%f\n", current->shp.polygon->lines[j].ystart);
                        fprintf(ft, "%f\n", current->shp.polygon->lines[j].xend);
                        fprintf(ft, "%f\n", current->shp.polygon->lines[j].yend);
                    }
                    break;
                case(PATHTYPE):
                    fprintf(ft, "PATHTYPE\n");
                    fprintf(ft, "%d\n", current->shp.path->size);
                    for(int k = 0; k < current->shp.path->size; k++){
                        switch(current->shp.path->list[k].opt){
                            case(M):
                                fprintf(ft, "M");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.m.xpos);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.m.ypos);
                                break;
                            case(L):
                                fprintf(ft, "L");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.l.xpos);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.l.ypos);
                                break;
                            case(H):
                                fprintf(ft, "H");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.h.xpos);
                                break;
                            case(V):
                                fprintf(ft, "V");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.v.ypos);
                                break;
                            case(Z):
                                fprintf(ft, "Z");
                                fprintf(ft, "%d\n", current->shp.path->list[k].op.z.verif);
                                break;
                            case(C):
                                fprintf(ft, "C");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.c.xend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.c.yend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.c.xpent1);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.c.ypent1);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.c.xpent2);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.c.ypent2);
                                break;
                            case(S):
                                fprintf(ft, "S");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.s.xend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.s.yend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.s.xpent2);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.s.ypent2);
                                break;
                            case(Q):
                                fprintf(ft, "Q");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.q.xend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.q.yend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.q.xpent1);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.q.ypent1);
                                break;
                            case(T):
                                fprintf(ft, "T");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.t.xend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.t.yend);
                                break;
                            case(A):
                                fprintf(ft, "A");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.a.xend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.a.yend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.a.xradius);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.a.yradius);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.a.rotation);
                                fprintf(ft, "%d\n", current->shp.path->list[k].op.a.side);
                                fprintf(ft, "%d\n", current->shp.path->list[k].op.a.drawingWay);
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case(GROUPTYPE):
                    fprintf(ft, "GROUPTYPE\n");
                    fprintf(ft, "%d\n", current->shp.group->nb);
                    saveShapes(current->shp.group, ft, fileNametext);
                    break;
                default:
                    break;
            }
            if(current->style != NULL){
                fprintf(ft, "1\n");
                fprintf(ft, "%s\n", current->style->color);
                fprintf(ft, "%s\n", current->style->fillColor);
                fprintf(ft, "%f\n", current->style->rotate);
                fprintf(ft, "%f\n", current->style->xtranslate);
                fprintf(ft, "%f\n", current->style->ytranslate);
                fprintf(ft, "%d\n", current->style->xinvert);
                fprintf(ft, "%d\n", current->style->yinvert);
            }
            else{
                fprintf(ft, "0\n");
            }
            fprintf(ft, "\n");
            current = current->next;
        }
    }
}