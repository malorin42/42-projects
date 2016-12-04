# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malorin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/10 14:56:52 by malorin           #+#    #+#              #
#    Updated: 2016/07/10 14:56:56 by malorin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol

LIBMLX = ./libmlx.a

OBJ = OBJ/main.o\
		OBJ/draw_julia.o\
		OBJ/draw_mandelbrot.o\
		OBJ/draw_burning_ship.o\
		OBJ/key.o\
		OBJ/color.o\

CFLAGS = -Wall -Werror -Wextra

all: obj $(NAME)

obj:
	@mkdir -p OBJ/

$(NAME): $(OBJ)
		@make -C ../libft/
		@gcc $(CFLAGS) -o $(NAME) $(OBJ) ../libft/libft.a $(LIBMLX) -framework OPENGL -framework Appkit

OBJ/%.o: Sources/%.c
	@gcc -c $+ -o $@

clean:
		@make clean -C ../libft
		@rm -rf /OBJ

fclean: clean
		@make fclean -C ../libft
		@rm -rf ./fract_ol

re: fclean all

.PHONY: all clean fclean re