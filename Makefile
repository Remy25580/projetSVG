CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra
OBJ := main.o projetsvg.o
SRC := main.c projetsvg.c
EXE := projetSvg.exe
BIN_DIR := bin

build:
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -c projetsvg.c
	$(CC) $(OBJ) -o $(EXE)

move_to_bin:
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	if exist $(EXE) move /Y $(EXE) $(BIN_DIR)\
	if exist main.o move /Y main.o $(BIN_DIR)\
	if exist projetsvg.o move /Y projetsvg.o $(BIN_DIR)\


clean:
	if exist $(BIN_DIR)\$(EXE) del /Q $(BIN_DIR)\$(EXE)
	if exist $(BIN_DIR)\main.o del /Q $(BIN_DIR)\main.o
	if exist $(BIN_DIR)\projetsvg.o del /Q $(BIN_DIR)\projetsvg.o

.PHONY: build move_to_bin clean