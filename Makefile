CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra
OBJ := main.o projetsvg.o
SRC := main.c projetsvg.c
EXE := projetSvg.exe

build:
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -c projetsvg.c
	$(CC) $(OBJ) -o $(EXE)

clean:
	$(EXE) del /Q projetSVG\$(EXE)
	main.o del /Q projetSVG\main.o
	projetsvg.o del /Q projetSVG\projetsvg.o