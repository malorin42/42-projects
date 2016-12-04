# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malorin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/06 17:55:46 by malorin           #+#    #+#              #
#    Updated: 2016/09/06 17:55:48 by malorin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

LIBMLX = ./libmlx.a

OBJ = OBJ/main.o\
		OBJ/raycasting.o\
		OBJ/draw.o\
		OBJ/draw_door.o\
		OBJ/draw_menu.o\
		OBJ/hack.o\
		OBJ/key_hook.o\
		OBJ/map.o\
		OBJ/key_move.o\
		OBJ/init.o\
		OBJ/open_door.o\
		OBJ/draw_hack.o\
		OBJ/draw_inv.o\
		OBJ/tools.o\
		OBJ/expose.o\
		OBJ/look_door.o\
		OBJ/draw_wall.o\
		OBJ/draw_end_wall.o\
		OBJ/face_color.o\
		OBJ/key_tools.o\

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
		@rm -rf OBJ/

fclean: clean
		@make fclean -C ../libft
		@rm -rf ./wolf3d

re: fclean all

.PHONY: all clean fclean re