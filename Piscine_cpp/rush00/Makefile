NAME = ft_retro

CPP_FILES =	main.cpp \
			Printable.class.cpp \
			Game.class.cpp \
			GameEntities.class.cpp \
			Ship.class.cpp \
			Character.class.cpp \
			Enemy.class.cpp \
			Pew.class.cpp \
			Asteroid.class.cpp \
			Creep.class.cpp \
			Boss.class.cpp \
			Level.class.cpp \
			ShootingStar.class.cpp

INC =ncurses			#includes

INC_DIR = class

CC = g++ -g3 -Wextra -Werror -Wall -std=c++98 -pedantic
OBJ = $(addprefix $(O_PATH), $(CPP_FILES:.cpp=.o))
SRC = $(addprefix $(C_PATH), $(CPP_FILES))
######
C_PATH = ./src/
O_PATH = ./obj/

$(addprefix $(O_PATH),%.o): $(addprefix $(C_PATH),%.cpp)
	@mkdir -p $(O_PATH)
	$(CC) -o $@ -c $^ -I$(INC_DIR)
	@echo -n .

all: $(NAME)

$(NAME): obj_comp $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -l$(INC)
	@echo "\n\x1b[32m-- COMPILING SUCCESSFULL --"

obj_comp:
	@echo "\x1b[33m-- COMPILING ... --\033[0m"

clean:
	@rm -rf ./obj
	@echo ".o cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "exec deleted"
	@echo "Project Cleaned."

re: fclean all
