CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra
EXE := projetSvg

build:
	$(CC) $(FLAGS) -c *.c
	$(CC) *.o -o $(EXE)

clean:
	del *.o
	del *.exe
