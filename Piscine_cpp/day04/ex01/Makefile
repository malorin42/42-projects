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

NAME = Wasteland

GCC = clang++

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(GCC) $(CFLAGS) -o $(NAME) main.cpp AWeapon.cpp PlasmaRifle.cpp Character.cpp Enemy.cpp PowerFist.cpp RadScorpion.cpp SuperMutant.cpp

fclean:
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
