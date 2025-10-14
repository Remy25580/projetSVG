#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation.h"
#include "path.h"
#include "userInterface.h"
#include "deletion.h"
#include "color.h"

void setColor(shapeStyle *s, int fillOrContour){
    int finished = 0;
    int choice;
    while(finished == 0){
        printf("What color do you want to apply ? 0 to cancel\n");
        printf("1 - black\n");
        printf("2 - white\n");
        printf("3 - red\n");
        printf("4 - blue\n");
        printf("5 - green\n");
        printf("6 - yellow\n");
        printf("7 - gray\n");
        printf("8 - purple\n");
        printf("9 - lime\n");
        printf("10 - aqua\n");
        printf("11 - teal\n");
        printf("12 - maroon\n");
        printf("13 - navy\n");
        printf("14 - silver\n");
        printf("15 - fuchsia\n");
        printf("16 - olive\n");
        scanf("%d", &choice);

        switch(choice){
            case(1):
                if(fillOrContour == 0){
                    s->color = "black";
                }
                else{
                    s->fillColor = "black";
                }
                finished = 1;
                break;
            case(2):
                if(fillOrContour == 0){
                    s->color = "white";
                }
                else{
                    s->fillColor = "white";
                }
                finished = 1;
                break;
            case(3):
                if(fillOrContour == 0){
                    s->color = "red";
                }
                else{
                    s->fillColor = "red";
                }
                finished = 1;
                break;
            case(4):
                if(fillOrContour == 0){
                    s->color = "blue";
                }
                else{
                    s->fillColor = "blue";
                }
                finished = 1;
                break;
            case(5):
                if(fillOrContour == 0){
                    s->color = "green";
                }
                else{
                    s->fillColor = "green";
                }
                finished = 1;
                break;
            case(6):
                if(fillOrContour == 0){
                    s->color = "yellow";
                }
                else{
                    s->fillColor = "yellow";
                }
                finished = 1;
                break;
            case(7):
                if(fillOrContour == 0){
                    s->color = "gray";
                }
                else{
                    s->fillColor = "gray";
                }
                finished = 1;
                break;
            case(8):
                if(fillOrContour == 0){
                    s->color = "purple";
                }
                else{
                    s->fillColor = "purple";
                }
                finished = 1;
                break;
            case(9):
                if(fillOrContour == 0){
                    s->color = "lime";
                }
                else{
                    s->fillColor = "lime";
                }
                finished = 1;
                break;
            case(10):
                if(fillOrContour == 0){
                    s->color = "aqua";
                }
                else{
                    s->fillColor = "aqua";
                }
                finished = 1;
                break;
            case(11):
                if(fillOrContour == 0){
                    s->color = "teal";
                }
                else{
                    s->fillColor = "teal";
                }
                finished = 1;
                break;
            case(12):
                if(fillOrContour == 0){
                    s->color = "maroon";
                }
                else{
                    s->fillColor = "maroon";
                }
                finished = 1;
                break;
            case(13):
                if(fillOrContour == 0){
                    s->color = "navy";
                }
                else{
                    s->fillColor = "navy";
                }
                finished = 1;
                break;
            case(14):
                if(fillOrContour == 0){
                    s->color = "silver";
                }
                else{
                    s->fillColor = "silver";
                }
                finished = 1;
                break;
            case(15):
                if(fillOrContour == 0){
                    s->color = "fuchsia";
                }
                else{
                    s->fillColor = "fuchsia";
                }
                finished = 1;
                break;
            case(16):
                if(fillOrContour == 0){
                    s->color = "olive";
                }
                else{
                    s->fillColor = "olive";
                }
                finished = 1;
                break;
            case(0):
                finished = 1;
                break;
            default:
                printf("Invalid value. Please type again\n");
                break;
        }
    }
}