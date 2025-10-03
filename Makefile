CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra

build:
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -c projetsvg.c
	$(CC) main.o projetsvg.o -o projetSvg

clean:
	rm bin/main
