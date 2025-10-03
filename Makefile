CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra
EXE := projetSvg

build:
	$(CC) $(FLAGS) -c projetsvg.c
	$(CC) $(FLAGS) -c main.c
	$(CC) *.o -o $(EXE)

clean:
	del *.o
	del *.exe
