CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra
EXE := projetSvg

build:
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -c creation/creation.c
	$(CC) $(FLAGS) -c creation/path.c
	$(CC) *.o -o $(EXE)

clean:
	del *.o
	del *.exe
