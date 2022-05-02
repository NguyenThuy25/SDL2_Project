SHELL:=/bin/bash
OBJS = $(wildcard */*.cpp)
# OBJS = $(wildcard src/GameObject.cpp src/Card.cpp src/DeckOfCards src/Game.cpp src/TextureManager.cpp src/main.cpp)
CC = g++
INCLUDE_PATHS = -I/usr/local/include
LIBRARY_PATHS = -L/usr/local/lib
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image
OBJ_NAME = a.out

all:
	$(CC) -o $(OBJ_NAME) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(OBJS)