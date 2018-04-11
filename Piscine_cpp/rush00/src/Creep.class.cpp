/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Creep.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:21:06 by malorin           #+#    #+#             */
/*   Updated: 2018/03/31 17:21:06 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Creep.class.hpp"

Creep::Creep(Game *game) : Enemy(game), _life(3), _posX(0), _posY(0)
{
	this->_life = 1;

	char	buff[64] = SHIP_MODEL_B;
	t_bitmap btm;
	memcpy(&btm.bitmap, &buff, 64);
	this->setBitmap(btm);
	this->setPosY((rand() % COLS - 10) + 8);
	this->setPosX(-5);
	this->setOri(downwards);
	this->set_color(COLOR_RED);
	// std::cout << "[default constructor] New Player Creep !" << std::endl;
}

Creep::~Creep()
{
	// std::cout << "[Destructor] Creep died !" << std::endl;
}

Creep::Creep(Game *game, Creep const & src) : Enemy(game), _life(src._life), _posX(src._posX), _posY(src._posY)
{
	// std::cout << "[Copie constructor] New Creep !" << std::endl;
}

Creep &		Creep::operator=(Creep const & rhs)
{
	this->_life = rhs._life;
	this->_posX = rhs._posX;
	this->_posY = rhs._posY;
	return (*this);
}

void			Creep::update()
{
	this->i++;
	if (this->i >= 3)
	{
		if ((this->getPosX() + 1) <= LINES + 10)
			this->setPosX(this->getPosX() + 1);
		else
			this->to_delete = 1;
		this->i = 0;
	}
	this->shoot();
}

void			Creep::takeDamage(unsigned int i)
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
