CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra
OBJ := main.o projetsvg.o
SRC := main.c projetsvg.c
EXE := projetSvg
BIN_DIR := bin

build:
	$(CC) $(FLAGS) -c *.c
	$(CC) *.o -o $(EXE)

clean:
	del *.o
	del *.exe
