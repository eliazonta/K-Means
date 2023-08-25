CC := g++
CFLAGS := -Wall -std=c++11 # -Wextra -Werror 
NAME := K-means3D
BIN := bin
OBJ_FOLDER := obj
SRC_FOLDER := src
 #=====================

 all : $(NAME)

# OBjs
$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.cpp 
	@mkdir -p $(OBJ_FOLDER)
	$(CC) $(CFLAGS) -c -o $@ $<

# Executable
$(NAME) : $(OBJ_FOLDER)/point.o $(OBJ_FOLDER)/readWrite.o $(OBJ_FOLDER)/k-means.o $(OBJ_FOLDER)/main.o
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) $^ -o $(BIN)/$(NAME) 

 clean :
	rm -rf $(OBJ_FOLDER) $(BIN) $(NAME)
