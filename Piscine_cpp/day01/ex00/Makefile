# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malorin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 15:55:10 by malorin           #+#    #+#              #
#    Updated: 2018/03/26 15:55:18 by malorin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Pony

GCC = clang++

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(GCC) $(CFLAGS) -o $(NAME) main.cpp Pony.cpp

fclean:
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
