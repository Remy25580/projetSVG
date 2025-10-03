CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra
OBJ := main.o projetSvg.o
EXE := projetSvg.exe

build:
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -c projetsvg.c
	$(CC) $(OBJ) -o $(EXE)

clean:
	rm -f bin/$(EXE) $(OBJ)
