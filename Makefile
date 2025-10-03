CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra
OBJ := main.o projetsvg.o
SRC := main.c projetsvg.c
EXE := projetSvg
BIN_DIR := bin

build:
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -c projetsvg.c
	$(CC) $(OBJ) -o $(EXE)


clean:
	del *.o
	del *.exe
