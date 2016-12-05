NAME = rtv1

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = obj/main.o obj/parser.o

LIBFT = ../libft/libft.a

all: obj $(NAME)

$(NAME): $(OBJ)
	@make -C ../libft/
	@$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " |        |"
	@echo " | RTv1   |"
	@echo " '--------'"

obj:
	@mkdir -p OBJ/

obj/%.o: Sources/%.c
	@$(GCC) -c $+ -o $@

clean:
	@rm -rf OBJ/
	@$(MAKE) -s clean -C ../libft/

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s fclean -C ../libft/

re: fclean all

.PHONY: all obj clean fclean re
