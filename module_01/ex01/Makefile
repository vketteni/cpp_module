NAME=zombieHorde
CC=g++

SRCS=main.cpp newZombie.cpp randomChump.cpp Zombie.cpp zombieHorde.cpp
OBJ_DIR=obj/
OBJS=$(SRCS:%.cpp=$(OBJ_DIR)%.o)


FLAGS=-Wall -Wextra -Werror -std=c++98
# INC=

all: $(NAME)

$(NAME):  $(OBJS)
		$(CC) $(FLAGS) $(INC) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re