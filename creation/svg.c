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

void svgShapes(shapeGroup_t *s, float x, float y){

}