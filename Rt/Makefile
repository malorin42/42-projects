NAME = parseur

SRCS = main.c\

OBJ = main.o\

CFLAGS = -Wall -Werror -Wextra

$(NAME) :
		@make -C ../libft/
		@gcc -c $(SRCS) $(CFLAGS)
		@gcc $(CFLAGS) -o $(NAME) $(OBJ) ../libft/libft.a


all : $(NAME)

clean :
		@make clean -C ../libft
		@rm -rf $(OBJ)

fclean : clean
		@make fclean -C ../libft
		@rm -rf ./parseur

re : fclean all