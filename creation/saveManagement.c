#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"
#include "deletion.h"
#include "color.h"
#include "saveManagement.h"

void saveShapes(shapeGroup_t *s){
    int choice = 2;
    int valid = 0;
    shapesElt *current;
    char *fileNametext = malloc(20*sizeof(char));

    while(choice != 1){
        printf("Are you sure you want to save now ? 0 for no, 1 for yes\n");
        while(scanf("%f", &choice)!= 1){
            printf("ERROR: a float is required here, please type again.\n");
            while (getchar() != '\n');
        }
        if(choice == 0){
            break;
        }
    }

    if(choice == 1){


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
        strcat(fileNametext, ".txt");

        FILE *ft = fopen(fileNametext, "w");


        current = s->head;

        while(current != NULL){
            switch(current->shpType){
                case(RECTANGLETYPE):
                    fprintf(ft, "RECTANGLETYPE\n");
                    fprintf(ft, "%s\n", current->name);
                    fprintf(ft, "%f\n", current->shp.rectangle->xpos);
                    fprintf(ft, "%f\n", current->shp.rectangle->ypos);
                    fprintf(ft, "%f\n", current->shp.rectangle->height);
                    fprintf(ft, "%f\n", current->shp.rectangle->width);
                    fprintf(ft, "%f\n", current->shp.rectangle->xradius);
                    fprintf(ft, "%f\n", current->shp.rectangle->yradius);
                    break;
                case(SQUARETYPE):
                    fprintf(ft, "SQUARETYPE\n");
                    fprintf(ft, "%s\n", current->name);
                    fprintf(ft, "%f\n", current->shp.square->xpos);
                    fprintf(ft, "%f\n", current->shp.square->ypos);
                    fprintf(ft, "%f\n", current->shp.square->dimension);
                    fprintf(ft, "%f\n", current->shp.square->xradius);
                    fprintf(ft, "%f\n", current->shp.square->yradius);
                    break;
                case(CIRCLETYPE):
                    fprintf(ft, "CIRCLETYPE\n");
                    fprintf(ft, "%s\n", current->name);
                    fprintf(ft, "%f\n", current->shp.circle->xpos);
                    fprintf(ft, "%f\n", current->shp.circle->ypos);
                    fprintf(ft, "%f\n", current->shp.circle->radius);
                    break;
                case(ELLIPSETYPE):
                    fprintf(ft, "ELLIPSETYPE\n");
                    fprintf(ft, "%s\n", current->name);
                    fprintf(ft, "%f\n", current->shp.ellipse->xpos);
                    fprintf(ft, "%f\n", current->shp.ellipse->ypos);
                    fprintf(ft, "%f\n", current->shp.ellipse->xradius);
                    fprintf(ft, "%f\n", current->shp.ellipse->yradius);
                    break;
                case(LINETYPE):
                    fprintf(ft, "LINETYPE\n");
                    fprintf(ft, "%s\n", current->name);
                    fprintf(ft, "%f\n", current->shp.line->xstart);
                    fprintf(ft, "%f\n", current->shp.line->ystart);
                    fprintf(ft, "%f\n", current->shp.line->xend);
                    fprintf(ft, "%f\n", current->shp.line->yend);
                    break;
                case(POLYLINETYPE):
                    fprintf(ft, "POLYLINETYPE\n");
                    fprintf(ft, "%s\n", current->name);
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
                    fprintf(ft, "%s\n", current->name);
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
                    fprintf(ft, "%s\n", current->name);
                    fprintf(ft, "%d\n", current->shp.path->size);
                    for(int k = 0; k < current->shp.path->size; k++){
                        switch(current->shp.path->list[k].opt){
                            case(M):
                                fprintf(ft, "M\n");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.m.xpos);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.m.ypos);
                                break;
                            case(L):
                                fprintf(ft, "L\n");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.l.xpos);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.l.ypos);
                                break;
                            case(H):
                                fprintf(ft, "H\n");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.h.xpos);
                                break;
                            case(V):
                                fprintf(ft, "V\n");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.v.ypos);
                                break;
                            case(Z):
                                fprintf(ft, "Z\n");
                                fprintf(ft, "%d\n", current->shp.path->list[k].op.z.verif);
                                break;
                            case(C):
                                fprintf(ft, "C\n");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.c.xend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.c.yend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.c.xpent1);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.c.ypent1);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.c.xpent2);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.c.ypent2);
                                break;
                            case(S):
                                fprintf(ft, "S\n");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.s.xend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.s.yend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.s.xpent2);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.s.ypent2);
                                break;
                            case(Q):
                                fprintf(ft, "Q\n");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.q.xend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.q.yend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.q.xpent1);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.q.ypent1);
                                break;
                            case(T):
                                fprintf(ft, "T\n");
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.t.xend);
                                fprintf(ft, "%f\n", current->shp.path->list[k].op.t.yend);
                                break;
                            case(A):
                                fprintf(ft, "A\n");
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
        fprintf(ft, "ENDSAVE");
        fclose(ft);
    }

}

void loadShapes(shapeGroup_t *s){
    s->nb = 0;
    char *fileName = malloc(20*sizeof(char));
    FILE *ft;
    int opened = 0;
    int errName;
    char line[256];
    shapesElt *current;

    while(opened == 0){
        errName = 0;
        printf("What file do you want to open?\n");
        printf("Please type the name of the file without the extension      ");
        scanf("%19s", fileName);
        if(strstr(fileName, ".") != NULL){
            printf("Invalid file name, you must not put a dot.\n");
            errName = 1;
        }
        if(errName == 0){
            strcat(fileName, ".txt");
            ft = fopen(fileName, "r");
            if(ft == NULL){
                printf("This file does not exit, please type again\n");
            }
            else{
                printf("file opened\n");
                opened = 1;
            }
        }

    }

    fgets(line, sizeof(line), ft);
    line[strcspn(line, "\n")] = '\0'; 

    while(strcmp(line, "ENDSAVE") != 0){
        current = malloc(sizeof(shapesElt));
        if(strcmp(line, "RECTANGLETYPE") == 0){
            current->shpType = RECTANGLETYPE;
            current->shp.rectangle = malloc(sizeof(rectangle_t));
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0'; 
            current->name = strdup(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.rectangle->xpos = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.rectangle->ypos = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.rectangle->height = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.rectangle->width = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.rectangle->xradius = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.rectangle->yradius = atof(line);
        }
        if(strcmp(line, "SQUARETYPE") == 0){
            current->shpType = SQUARETYPE;
            current->shp.square = malloc(sizeof(square_t));
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0'; 
            current->name = strdup(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.square->xpos = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.square->ypos = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.square->dimension = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.square->xradius = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.square->yradius = atof(line);
        }
        if(strcmp(line, "CIRCLETYPE") == 0){
            current->shpType = CIRCLETYPE;
            current->shp.circle = malloc(sizeof(circle_t));
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->name = strdup(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.circle->xpos = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.circle->ypos = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.circle->radius = atof(line);
        }
        if(strcmp(line, "ELLIPSETYPE") == 0){
            current->shpType = ELLIPSETYPE;
            current->shp.ellipse = malloc(sizeof(ellipse_t));
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->name = strdup(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.ellipse->xpos = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.ellipse->ypos = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.ellipse->xradius = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.ellipse->yradius = atof(line);
        }
        if(strcmp(line, "LINETYPE") == 0){
            current->shpType = LINETYPE;
            current->shp.line = malloc(sizeof(line_t));
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->name = strdup(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.line->xstart = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.line->ystart = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.line->xend = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.line->yend = atof(line);
        }
        if(strcmp(line, "POLYLINETYPE") == 0){
            current->shpType = POLYLINETYPE;
            current->shp.polyline = malloc(sizeof(polyline_t));
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->name = strdup(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.polyline->nbLines = atoi(line);
            current->shp.polyline->lines = malloc(current->shp.polyline->nbLines * sizeof(line_t));
            for(int i = 0; i < current->shp.polyline->nbLines; i++){
                fgets(line, sizeof(line), ft);
                line[strcspn(line, "\n")] = '\0';
                current->shp.polyline->lines[i].xstart = atof(line);
                fgets(line, sizeof(line), ft);
                line[strcspn(line, "\n")] = '\0';
                current->shp.polyline->lines[i].ystart = atof(line);
                fgets(line, sizeof(line), ft);
                line[strcspn(line, "\n")] = '\0';
                current->shp.polyline->lines[i].xend = atof(line);
                fgets(line, sizeof(line), ft);
                line[strcspn(line, "\n")] = '\0';
                current->shp.polyline->lines[i].yend = atof(line);
            }
        }
        if(strcmp(line, "POLYGONTYPE") == 0){
            current->shpType = POLYGONTYPE;
            current->shp.polygon = malloc(sizeof(polygon_t));
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->name = strdup(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.polygon->nbSides = atoi(line);
            current->shp.polygon->lines = malloc(current->shp.polygon->nbSides * sizeof(line_t));
            for(int j = 0; j < current->shp.polygon->nbSides; j++){
                fgets(line, sizeof(line), ft);
                line[strcspn(line, "\n")] = '\0';
                current->shp.polygon->lines[j].xstart = atof(line);
                fgets(line, sizeof(line), ft);
                line[strcspn(line, "\n")] = '\0';
                current->shp.polygon->lines[j].ystart = atof(line);
                fgets(line, sizeof(line), ft);
                line[strcspn(line, "\n")] = '\0';
                current->shp.polygon->lines[j].xend = atof(line);
                fgets(line, sizeof(line), ft);
                line[strcspn(line, "\n")] = '\0';
                current->shp.polygon->lines[j].yend = atof(line);
            }
        }
        if(strcmp(line, "PATHTYPE") == 0){
            current->shpType = PATHTYPE;
            current->shp.path = malloc(sizeof(path_t));
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->name = strdup(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->shp.path->size = atoi(line);
            current->shp.path->list = malloc(current->shp.path->size * sizeof(operationComplete));
            for(int k = 0; k < current->shp.path->size; k++){
                fgets(line, sizeof(line), ft);
                line[strcspn(line, "\n")] = '\0';
                if(strcmp(line, "M") == 0){
                    current->shp.path->list[k].opt = M;
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.m.xpos = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.m.ypos = atof(line);
                }
                if(strcmp(line, "L") == 0){
                    current->shp.path->list[k].opt = L;
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.l.xpos = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.l.ypos = atof(line);
                }
                if(strcmp(line, "H") == 0){
                    current->shp.path->list[k].opt = H;
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.h.xpos = atof(line);
                }
                if(strcmp(line, "V") == 0){
                    current->shp.path->list[k].opt = V;
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.v.ypos = atof(line);
                }
                if(strcmp(line, "Z") == 0){
                    current->shp.path->list[k].opt = Z;
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.z.verif = atoi(line);
                }
                if(strcmp(line, "C") == 0){
                    current->shp.path->list[k].opt = C;
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.c.xend = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.c.yend = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.c.xpent1 = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.c.ypent1 = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.c.xpent2 = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.c.ypent2 = atof(line);
                }
                if(strcmp(line, "S") == 0){
                    current->shp.path->list[k].opt = S;
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.s.xend = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.s.yend = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.s.xpent2 = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.s.ypent2 = atof(line);
                }
                if(strcmp(line, "Q") == 0){
                    current->shp.path->list[k].opt = Q;
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.q.xend = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.q.yend = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.q.xpent1 = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.q.ypent1 = atof(line);
                }
                if(strcmp(line, "T") == 0){
                    current->shp.path->list[k].opt = T;
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.t.xend = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.t.yend = atof(line);
                }
                if(strcmp(line, "A") == 0){
                    current->shp.path->list[k].opt = A;
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.a.xend = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.a.yend = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.a.xradius = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.a.yradius = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.a.rotation = atof(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.a.side = atoi(line);
                    fgets(line, sizeof(line), ft);
                    line[strcspn(line, "\n")] = '\0';
                    current->shp.path->list[k].op.a.drawingWay = atoi(line);
                }
            }
        }

        fgets(line, sizeof(line), ft);
        line[strcspn(line, "\n")] = '\0';
        if(strcmp(line, "0") == 0){
            current->style = NULL;
        }
        if(strcmp(line, "1") == 0){
            current->style = malloc(sizeof(shapeStyle));
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->style->color = strdup(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->style->fillColor = strdup(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->style->rotate = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->style->xtranslate = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->style->ytranslate = atof(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->style->xinvert = atoi(line);
            fgets(line, sizeof(line), ft);
            line[strcspn(line, "\n")] = '\0';
            current->style->yinvert = atoi(line);
        }
        fgets(line, sizeof(line), ft);

        fgets(line, sizeof(line), ft);
        line[strcspn(line, "\n")] = '\0';
        addInList(s, current);
    }
    printf("Save loaded!\n");
}