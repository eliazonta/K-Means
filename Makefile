CC := g++
CFLAGS := -std=c++11 # -Wextra -Werror -Wall
# OMPFLAGS := -fopenmp
NAME := K-Means3D
BIN := bin
OBJ_FOLDER := obj
SRC_FOLDER := src
 #=====================

 all : $(NAME)

# OBjs
$(OBJ_FOLDER)/point.o $(OBJ_FOLDER)/readWrite.o $(OBJ_FOLDER)/k-means.o $(OBJ_FOLDER)/main.o: $(SRC_FOLDER)/point.cpp $(SRC_FOLDER)/readWrite.cpp $(SRC_FOLDER)/k-means.cpp $(SRC_FOLDER)/main.cpp
	@mkdir -p $(OBJ_FOLDER)
	$(CC) $(CFLAGS) -c $^ 
	@mv *.o $(OBJ_FOLDER)

# Executable
$(NAME) : $(OBJ_FOLDER)/point.o $(OBJ_FOLDER)/readWrite.o $(OBJ_FOLDER)/k-means.o $(OBJ_FOLDER)/main.o
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) $^ -o $(BIN)/$(NAME) $(OMPFLAGS) 

 clean :
	rm -rf $(OBJ_FOLDER) $(BIN) $(NAME)
