CC := g++
SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
NAME := K-means3D

#=====================

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC)  $(OBJ) -o $(NAME) 

%.o : %.cpp
	$(CC)  -c $< -o $@

clean :
	rm -f $(OBJ)

