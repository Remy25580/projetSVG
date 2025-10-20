CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra
EXE := projetSvg

build:
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -c creation/creation.c
	$(CC) $(FLAGS) -c creation/path.c
	$(CC) $(FLAGS) -c creation/userInterface.c
	$(CC) $(FLAGS) -c creation/deletion.c
	$(CC) $(FLAGS) -c creation/color.c
	$(CC) $(FLAGS) -c creation/saveManagement.c
	$(CC) $(FLAGS) -c creation/svg.c
	$(CC) *.o -o $(EXE)

clean:
	del *.o
	del *.exe
