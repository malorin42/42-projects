/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:21:06 by malorin           #+#    #+#             */
/*   Updated: 2018/03/31 17:21:06 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Asteroid.class.hpp"

Asteroid::Asteroid(Game *game) : Enemy(game), _life(3), _posX(0), _posY(0)
{
	this->_life = 1;

	char	buff[64] = ASTEROID;
	t_bitmap btm;
	memcpy(&btm.bitmap, &buff, 64);
	this->setBitmap(btm);
	this->setPosY((rand() % COLS - 10) + 8);
	this->setPosX(-5);
	this->setOri(downwards);
	this->set_color(COLOR_YELLOW);
	// std::cout << "[default constructor] New Player Asteroid !" << std::endl;
}

Asteroid::~Asteroid()
{
	// std::cout << "[Destructor] Asteroid died !" << std::endl;
}

Asteroid::Asteroid(Game *game, Asteroid const & src) : Enemy(game), _life(src._life), _posX(src._posX), _posY(src._posY)
{
	// std::cout << "[Copie constructor] New Asteroid !" << std::endl;
}

Asteroid &		Asteroid::operator=(Asteroid const & rhs)
{
	this->_life = rhs._life;
	this->_posX = rhs._posX;
	this->_posY = rhs._posY;
	return (*this);
}

void			Asteroid::update()
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

void			Asteroid::takeDamage(unsigned int i) {(void)i;}
