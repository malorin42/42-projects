/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:17:22 by malorin           #+#    #+#             */
/*   Updated: 2018/03/31 16:17:25 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "Character.class.hpp"
#include "Pew.class.hpp"
#include "Printable.class.hpp"

Character::Character(Game *game) : Ship(game), _life(3)
{
	this->_i = 0;
	// std::cout << "[default constructor] New Player Character !" << std::endl;
}

Character::~Character()
{
	this->_game->gameOver = 1;
	// std::cout << "[Destructor] You died !" << std::endl;
}

Character::Character(Game *game, Character const & src) : Ship(game), _life(src._life)
{
	// std::cout << "[Copie constructor] New Player Character !" << std::endl;
}

Character &		Character::operator=(Character const & rhs)
{
	this->_life = rhs._life;
	return (*this);
}

void			Character::update()
{
	int key;

	while ((key = getch()) != ERR)
	{
		if (key == 27)
			this->_game->gameOver = 1;
			// std::cout << key << " - " << std::flush;
		else if (key == 32)
			this->shoot();
		else if (key == 115 && (this->getPosX() + 1) <= LINES - 8)
			this->setPosX(this->getPosX() + 1);
		else if (key == 119 && (this->getPosX() - 1) >= 5)
			this->setPosX(this->getPosX() - 1);
		else if (key == 97 && (this->getPosY() - 2) >= 0)
			this->setPosY(this->getPosY() - 2);
		else if (key == 100  && (this->getPosY() + 2) <= COLS - 8)
			this->setPosY(this->getPosY() + 2);
	}
	// std::cout << std::endl;
	// std::cout << "I'm a Player ! :D " << std::flush;
}

void			Character::takeDamage(unsigned int i)
{
	int		tmp;

	tmp = this->_life - i;
	if (tmp <= 0)
	{
		this->to_delete = 1;
	}
	else
		this->_life--;
}
