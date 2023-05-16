#---------------------------------------------------------------------------------------
# Makefile in charge of compiling and linking RayTracer components to a excecutable file 
#---------------------------------------------------------------------------------------

CPP = g++
NAME = main
TYPE = .exe

SRC := $(wildcard src/*.cc)
OBJ = $(SRC:.c=o)

OBJ_DIR = /build
SRC_DIR = /src

$(NAME)$(TYPE): $(SRC)
	$(CPP) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CPP) -c -o $@ $<








