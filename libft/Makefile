# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malorin <malorin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 15:02:26 by malorin           #+#    #+#              #
#    Updated: 2016/01/25 14:57:38 by malorin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ = OBJ/ft_memset.o\
	OBJ/ft_math.o\
	OBJ/ft_bzero.o\
	OBJ/ft_memcpy.o\
	OBJ/ft_memccpy.o\
	OBJ/ft_memmove.o\
	OBJ/ft_memchr.o\
	OBJ/ft_memcmp.o\
	OBJ/ft_cherchc.o\
	OBJ/ft_strlen.o\
	OBJ/ft_strclen.o\
	OBJ/ft_strdup.o\
	OBJ/ft_strcpy.o\
	OBJ/ft_strncpy.o\
	OBJ/ft_strcat.o\
	OBJ/ft_strncat.o\
	OBJ/ft_strlcat.o\
	OBJ/ft_strchr.o\
	OBJ/ft_strrchr.o\
	OBJ/ft_strstr.o\
	OBJ/ft_strnstr.o\
	OBJ/ft_strcmp.o\
	OBJ/ft_strncmp.o\
	OBJ/ft_atoi.o\
	OBJ/ft_isalpha.o\
	OBJ/ft_isdigit.o\
	OBJ/ft_isalnum.o\
	OBJ/ft_isimpair.o\
	OBJ/ft_ispair.o\
	OBJ/ft_isspace.o\
	OBJ/ft_isascii.o\
	OBJ/ft_isprint.o\
	OBJ/ft_toupper.o\
	OBJ/ft_tolower.o\
	OBJ/ft_putstr.o\
	OBJ/ft_putchar.o\
	OBJ/ft_putendl.o\
	OBJ/ft_striteri.o\
	OBJ/ft_strmap.o\
	OBJ/ft_strmapi.o\
	OBJ/ft_strequ.o\
	OBJ/ft_strnequ.o\
	OBJ/ft_striter.o\
	OBJ/ft_itoa.o\
	OBJ/ft_putendl_fd.o\
	OBJ/ft_putnbr.o\
	OBJ/ft_strjoin.o\
	OBJ/ft_strsplit.o\
	OBJ/ft_strsub.o\
	OBJ/ft_strtrim.o\
	OBJ/ft_putchar_fd.o\
	OBJ/ft_putstr_fd.o\
	OBJ/ft_putnbr_fd.o\
	OBJ/ft_strclr.o\
	OBJ/ft_memalloc.o\
	OBJ/ft_memdel.o\
	OBJ/ft_strdel.o\
	OBJ/ft_strnew.o\
	OBJ/ft_lstnew.o\
	OBJ/ft_lstmap.o\
	OBJ/ft_lstiter.o\
	OBJ/ft_lstdelone.o\
	OBJ/ft_lstdel.o\
	OBJ/ft_lstadd.o\
	OBJ/ft_rot13.o\
	OBJ/get_next_line.o\
	OBJ/ft_parse_double.o\
	OBJ/ft_tab_new.o\
	OBJ/ft_tab_add.o\
	OBJ/ft_tab_ini.o\
	OBJ/ft_tab_addn.o\
	OBJ/ft_tab_ext.o\
	OBJ/ft_tab_kill.o\

CFLAGS = -Wall -Wextra -Werror

all: obj $(NAME)

obj:
	@mkdir -p OBJ/

$(NAME):    $(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

OBJ/%.o: %.c
	@gcc -c $+ -o $@

clean:
			@rm -rf OBJ/

fclean: clean
			rm -rf $(NAME)

re: fclean all
