# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malorin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/05 02:00:10 by malorin           #+#    #+#              #
#    Updated: 2016/07/05 02:00:13 by malorin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBMLX = ./libmlx.a

OBJ = OBJ/main.o\
		OBJ/search_size.o\
		OBJ/search_highest.o\
		OBJ/fill_tab.o\
		OBJ/init_mlx.o\
		OBJ/draw_fdf.o\
		OBJ/draw_ramps.o\
		OBJ/draw_ramps_re.o\
		OBJ/color.o\

CFLAGS = -Wall -Werror -Wextra

all: obj $(NAME)

obj:
	mkdir -p OBJ/

$(NAME): $(OBJ)
		@make -C ../libft/
		@gcc $(CFLAGS) -o $(NAME) $(OBJ) ../libft/libft.a $(LIBMLX) -framework OPENGL -framework Appkit

OBJ/%.o: Sources/%.c
	@gcc -c $+ -o $@

clean:
		@make clean -C ../libft
		@rm -rf OBJ/

fclean: clean
		@make fclean -C ../libft
		@rm -rf ./fdf

re: fclean all

.PHONY: all clean fclean re