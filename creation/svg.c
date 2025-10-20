#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"
#include "deletion.h"
#include "color.h"
#include "saveManagement.h"
#include "svg.h"

float xMax(shapeGroup_t *s){
    float max = -1;
    shapesElt *current = s->head;

    while(current != NULL){
        switch(current->shpType){
            case(RECTANGLETYPE):
                if(current->shp.rectangle->xpos + current->shp.rectangle->width > max){
                    max = current->shp.rectangle->xpos + current->shp.rectangle->width;
                }
                break;
            case(SQUARETYPE):
                if(current->shp.square->xpos + current->shp.square->dimension > max){
                    max = current->shp.square->xpos + current->shp.square->dimension;
                }
                break;
            case(CIRCLETYPE):
                if(current->shp.circle->xpos + current->shp.circle->radius > max){
                    max = current->shp.circle->xpos + current->shp.circle->radius;
                }
                break;
            case(ELLIPSETYPE):
                if(current->shp.ellipse->xpos + current->shp.ellipse->xradius > max){
                    max = current->shp.ellipse->xpos + current->shp.ellipse->xradius;
                }
                break;
            case(LINETYPE):
                if(current->shp.line->xstart > max){
                    max = current->shp.line->xstart;
                }
                if(current->shp.line->xend > max){
                    max = current->shp.line->xend;
                }
                break;
            case(POLYLINETYPE):
                for(int i = 0; i<current->shp.polyline->nbLines; i++){
                    if(current->shp.polyline->lines[i].xstart > max){
                        max = current->shp.polyline->lines[i].xstart;
                    }
                    if(current->shp.polyline->lines[i].xend > max){
                        max = current->shp.polyline->lines[i].xend;
                    }
                }
                break;
            case(POLYGONTYPE):
                for(int j = 0; j<current->shp.polygon->nbSides; j++){
                    if(current->shp.polygon->lines[j].xstart > max){
                        max = current->shp.polygon->lines[j].xstart;
                    }
                    if(current->shp.polygon->lines[j].xend > max){
                        max = current->shp.polygon->lines[j].xend;
                    }
                }
                break;
            case(PATHTYPE):
                for(int k = 0; k<current->shp.path->size; k++){
                    switch(current->shp.path->list[k].opt){
                        case(M):
                            if(current->shp.path->list[k+1].opt != M){
                                if(current->shp.path->list[k].op.m.xpos > max){
                                    max = current->shp.path->list[k].op.m.xpos;
                                }
                            }
                            break;
                        case(L):
                            if(current->shp.path->list[k].op.l.xpos > max){
                                max = current->shp.path->list[k].op.l.xpos;
                            }
                            break;
                        case(H):
                            if(current->shp.path->list[k].op.h.xpos > max){
                                max = current->shp.path->list[k].op.h.xpos;
                            }
                            break;
                        case(C):
                            if(current->shp.path->list[k].op.c.xend > max){
                                max = current->shp.path->list[k].op.c.xend;
                            }
                            if(current->shp.path->list[k].op.c.xpent1 > max){
                                max = current->shp.path->list[k].op.c.xpent1;
                            }
                            if(current->shp.path->list[k].op.c.xpent2 > max){
                                max = current->shp.path->list[k].op.c.xpent2;
                            }
                            break;
                        case(S):
                            if(current->shp.path->list[k].op.s.xend > max){
                                max = current->shp.path->list[k].op.s.xend;
                            }
                            if(current->shp.path->list[k].op.s.xpent2 > max){
                                max = current->shp.path->list[k].op.s.xpent2;
                            }
                            break;
                        case(Q):
                            if(current->shp.path->list[k].op.q.xend > max){
                                max = current->shp.path->list[k].op.q.xend;
                            }
                            if(current->shp.path->list[k].op.q.xpent1 > max){
                                max = current->shp.path->list[k].op.q.xpent1;
                            }
                            break;
                        case(A):
                            if(current->shp.path->list[k].op.a.xend > max){
                                max = current->shp.path->list[k].op.a.xend;
                            }
                            break;
                        default:
                            break;
                    }
                }
                break;
        }
        current = current->next;
    }
    return max;
}

float yMax(shapeGroup_t *s){
    float max = -1;
    shapesElt *current = s->head;

    while(current != NULL){
        switch(current->shpType){
            case(RECTANGLETYPE):
                if(current->shp.rectangle->ypos + current->shp.rectangle->height > max){
                    max = current->shp.rectangle->ypos + current->shp.rectangle->height;
                }
                break;
            case(SQUARETYPE):
                if(current->shp.square->ypos + current->shp.square->dimension > max){
                    max = current->shp.square->ypos + current->shp.square->dimension;
                }
                break;
            case(CIRCLETYPE):
                if(current->shp.circle->ypos + current->shp.circle->radius > max){
                    max = current->shp.circle->ypos + current->shp.circle->radius;
                }
                break;
            case(ELLIPSETYPE):
                if(current->shp.ellipse->ypos + current->shp.ellipse->yradius > max){
                    max = current->shp.ellipse->ypos + current->shp.ellipse->yradius;
                }
                break;
            case(LINETYPE):
                if(current->shp.line->ystart > max){
                    max = current->shp.line->ystart;
                }
                if(current->shp.line->yend > max){
                    max = current->shp.line->yend;
                }
                break;
            case(POLYLINETYPE):
                for(int i = 0; i<current->shp.polyline->nbLines; i++){
                    if(current->shp.polyline->lines[i].ystart > max){
                        max = current->shp.polyline->lines[i].ystart;
                    }
                    if(current->shp.polyline->lines[i].yend > max){
                        max = current->shp.polyline->lines[i].yend;
                    }
                }
                break;
            case(POLYGONTYPE):
                for(int j = 0; j<current->shp.polygon->nbSides; j++){
                    if(current->shp.polygon->lines[j].ystart > max){
                        max = current->shp.polygon->lines[j].ystart;
                    }
                    if(current->shp.polygon->lines[j].yend > max){
                        max = current->shp.polygon->lines[j].yend;
                    }
                }
                break;
            case(PATHTYPE):
                for(int k = 0; k<current->shp.path->size; k++){
                    switch(current->shp.path->list[k].opt){
                        case(M):
                            if(current->shp.path->list[k+1].opt != M){
                                if(current->shp.path->list[k].op.m.ypos > max){
                                    max = current->shp.path->list[k].op.m.ypos;
                                }
                            }
                            break;
                        case(L):
                            if(current->shp.path->list[k].op.l.ypos > max){
                                max = current->shp.path->list[k].op.l.ypos;
                            }
                            break;
                        case(V):
                            if(current->shp.path->list[k].op.v.ypos > max){
                                max = current->shp.path->list[k].op.v.ypos;
                            }
                            break;
                        case(C):
                            if(current->shp.path->list[k].op.c.yend > max){
                                max = current->shp.path->list[k].op.c.yend;
                            }
                            if(current->shp.path->list[k].op.c.ypent1 > max){
                                max = current->shp.path->list[k].op.c.ypent1;
                            }
                            if(current->shp.path->list[k].op.c.ypent2 > max){
                                max = current->shp.path->list[k].op.c.ypent2;
                            }
                            break;
                        case(S):
                            if(current->shp.path->list[k].op.s.yend > max){
                                max = current->shp.path->list[k].op.s.yend;
                            }
                            if(current->shp.path->list[k].op.s.ypent2 > max){
                                max = current->shp.path->list[k].op.s.ypent2;
                            }
                            break;
                        case(Q):
                            if(current->shp.path->list[k].op.q.yend > max){
                                max = current->shp.path->list[k].op.q.yend;
                            }
                            if(current->shp.path->list[k].op.q.ypent1 > max){
                                max = current->shp.path->list[k].op.q.ypent1;
                            }
                            break;
                        case(A):
                            if(current->shp.path->list[k].op.a.yend > max){
                                max = current->shp.path->list[k].op.a.yend;
                            }
                            break;
                        default:
                            break;
                    }
                }
                break;
        }
        current = current->next;
    }
    return max;
}

void svgShapes(shapeGroup_t *s){
    char *name = malloc(20 * sizeof(char));
    char *nameFile = malloc(25*sizeof(char));
    int validName = 0;
    float x = xMax(s)*1.5;
    float y = yMax(s)*1.5;
    shapesElt *current = s->head;
    int transformApplied;

    while(validName == 0){
        printf("How do you want to name your SVG file ?\n");
        printf("Name : ");
        scanf("%19s", name);
        if(strstr(name, ".") != NULL){
            printf("Invalid file name, you must not put a dot.\n");
        }
        else{
            validName=1;
        }
    }

    nameFile = name;
    strcat(nameFile, ".svg");

    FILE *ft = fopen(nameFile, "w");
    fprintf(ft, "<?xml version='1.0' encoding='UTF-8'?>\n");
    fprintf(ft, "<svg xmlns='http://www.w3.org/2000/svg'\n");
    fprintf(ft, "width='%f' height='%f'\n", x, y);
    fprintf(ft, "viewBox='0 0 %f %f'\n", x, y);
    fprintf(ft, "role='img' aria-label='%19s'>\n", name);
    fprintf(ft, "\n");
    while(current != NULL){
        switch(current->shpType){
            case(RECTANGLETYPE):
                fprintf(ft, "<rect id='%s' x='%f' y='%f' width='%f' height='%f'",
                current->name, current->shp.rectangle->xpos, current->shp.rectangle->ypos,
                current->shp.rectangle->width, current->shp.rectangle->height);
                if(current->shp.rectangle->xradius > 0 && current->shp.rectangle->yradius > 0){
                    fprintf(ft, "\nrx='%f' ry='%f'", current->shp.rectangle->xradius,
                    current->shp.rectangle->yradius);
                }
                break;
            case(SQUARETYPE):
                fprintf(ft, "<rect id='%s' x='%f' y='%f' width='%f' height='%f'",
                current->name, current->shp.square->xpos, current->shp.square->ypos,
                current->shp.square->dimension, current->shp.square->dimension);
                if(current->shp.square->xradius > 0 && current->shp.square->yradius > 0){
                    fprintf(ft, "\nrx='%f' ry='%f'", current->shp.rectangle->xradius,
                    current->shp.rectangle->yradius);
                }
                break;
            case(CIRCLETYPE):
                fprintf(ft, "<circle id='%s' cx='%f' cy='%f' r='%f'", current->name,
                current->shp.circle->xpos, current->shp.circle->ypos, current->shp.circle->radius);
                break;
            case(ELLIPSETYPE):
                fprintf(ft, "<ellipse id='%s' cx='%f' cy='%f' rx='%f' ry='%f'", current->name,
                current->shp.ellipse->xpos, current->shp.ellipse->ypos,
                current->shp.ellipse->xradius, current->shp.ellipse->yradius);
                break;
            case(LINETYPE):
                fprintf(ft, "<line id='%s' x1='%f' y1='%f' x2='%f' y2='%f'", current->name,
                current->shp.line->xstart, current->shp.line->ystart,
                current->shp.line->xend, current->shp.line->yend);
                break;
            case(POLYLINETYPE):
                fprintf(ft, "<polyline id='%s' points='%f,%f ", current->name,
                current->shp.polyline->lines[0].xstart, current->shp.polyline->lines[0].ystart);
                for(int i = 0; i < current->shp.polyline->nbLines; i++){
                    fprintf(ft, "%f,%f", current->shp.polyline->lines[i].xend, current->shp.polyline->lines[i].yend);
                    if(i != current->shp.polyline->nbLines-1){
                        fprintf(ft, " ");
                    }
                }
                fprintf(ft, "'");
                break;
            case(POLYGONTYPE):
                fprintf(ft, "<polygon id='%s' points='%f,%f ", current->name,
                current->shp.polygon->lines[0].xstart, current->shp.polygon->lines[0].ystart);
                for(int j = 0; j < current->shp.polygon->nbSides-1; j++){
                    fprintf(ft, "%f,%f", current->shp.polygon->lines[j].xend, current->shp.polygon->lines[j].yend);
                    if(j != current->shp.polygon->nbSides -2){
                        fprintf(ft, " ");
                    }
                }
                fprintf(ft, "'");
                break;
            case(PATHTYPE):
                fprintf(ft, "<path id='%s' d='", current->name);
                for(int k = 0; k < current->shp.path->size; k++){
                    switch(current->shp.path->list[k].opt){
                        case(M):
                            fprintf(ft, "M %f %f", current->shp.path->list[k].op.m.xpos, current->shp.path->list[k].op.m.ypos);
                            break;
                        case(L):
                            fprintf(ft, "L %f %f", current->shp.path->list[k].op.l.xpos, current->shp.path->list[k].op.l.ypos);
                            break;
                        case(H):
                            fprintf(ft, "H %f", current->shp.path->list[k].op.h.xpos);
                            break;
                        case(V):
                            fprintf(ft, "V %f", current->shp.path->list[k].op.v.ypos);
                            break;
                        case(Z):
                            fprintf(ft, "Z");
                            break;
                        case(C):
                            fprintf(ft, "C %f %f, %f %f, %f %f",
                            current->shp.path->list[k].op.c.xend, current->shp.path->list[k].op.c.yend,
                            current->shp.path->list[k].op.c.xpent1, current->shp.path->list[k].op.c.ypent1,
                            current->shp.path->list[k].op.c.xpent2, current->shp.path->list[k].op.c.ypent2);
                            break;
                        case(S):
                            fprintf(ft, "S %f %f, %f %f",
                            current->shp.path->list[k].op.s.xend, current->shp.path->list[k].op.s.yend,
                            current->shp.path->list[k].op.s.xpent2, current->shp.path->list[k].op.s.ypent2);
                            break;
                        case(Q):
                            fprintf(ft, "Q %f %f, %f %f",
                            current->shp.path->list[k].op.q.xend, current->shp.path->list[k].op.q.yend,
                            current->shp.path->list[k].op.q.xpent1, current->shp.path->list[k].op.q.ypent1);
                            break;
                        case(T):
                            fprintf(ft, "T %f %f",
                            current->shp.path->list[k].op.t.xend, current->shp.path->list[k].op.t.yend);
                            break;
                        case(A):
                            fprintf(ft, "A %f %f %f %d %d %f %f",
                            current->shp.path->list[k].op.a.xradius, current->shp.path->list[k].op.a.yradius,
                            current->shp.path->list[k].op.a.rotation,
                            current->shp.path->list[k].op.a.side,
                            current->shp.path->list[k].op.a.drawingWay,
                            current->shp.path->list[k].op.a.xend, current->shp.path->list[k].op.a.yend);
                            break;
                        case(D):
                            break;
                        default:
                            break;;
                    }
                    if(k != current->shp.path->size - 1){
                        fprintf(ft, " ");
                    }
                }
                fprintf(ft, "'");
                break;
            default:
                break;

        }

        if(current->style != NULL){
            transformApplied = 0;
            fprintf(ft, "\n");
            if(strcmp(current->style->color, "none")!=0){
                fprintf(ft, "stroke='%s' ", current->style->color);
            }
            if(strcmp(current->style->fillColor, "none")!=0){
                fprintf(ft, "fill='%s' ", current->style->fillColor);
            }
            fprintf(ft, "/>\n");
            fprintf(ft, "\n");
            if(current->style->rotate != 0){
                if(transformApplied == 0){
                    fprintf(ft, "<g transform=");
                    transformApplied = 1;
                }
                fprintf(ft, "rotate(%f) ", current->style->rotate);
            }
            if(current->style->xtranslate != 0 || current->style->ytranslate != 0){
                if(transformApplied == 0){
                    fprintf(ft, "<g transform=");
                    transformApplied = 1;
                }
                fprintf(ft, "translate(%f,%f) ", current->style->xtranslate, current->style->ytranslate);
            }
            if(current->style->xinvert == 1 && current->style->yinvert == 0){
                if(transformApplied == 0){
                    fprintf(ft, "<g transform=");
                    transformApplied = 1;
                }
                fprintf(ft, "scale(1,-1) ");
            }
            if(current->style->xinvert == 0 && current->style->yinvert == 1){
                if(transformApplied == 0){
                    fprintf(ft, "<g transform=");
                    transformApplied = 1;
                }
                fprintf(ft, "scale(-1,1) ");
            }
            if(current->style->xinvert == 1 && current->style->yinvert == 1){
                if(transformApplied == 0){
                    fprintf(ft, "<g transform=");
                    transformApplied = 1;
                }
                fprintf(ft, "scale(-1,-1) ");
            }
            if(transformApplied == 1){
                fprintf(ft, "/>\n");
                fprintf(ft, "<use href='#%s'/>\n", current->name);
            }
        }

        else{
            fprintf(ft, "/>\n");
        }
        fprintf(ft, "\n");

        current = current->next;
    }
    fprintf(ft, "/svg");
    fclose(ft);
}