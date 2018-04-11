/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:21:06 by malorin           #+#    #+#             */
/*   Updated: 2018/03/31 17:21:06 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Boss.class.hpp"

Boss::Boss(Game *game) : Enemy(game), _life(3), _posX(0), _posY(0)
{
	this->_life = 1;

	char	buff[64] = SHIP_BOSS;
	t_bitmap btm;
	memcpy(&btm.bitmap, &buff, 64);
	this->setBitmap(btm);
	this->setPosY(COLS / 2 - 4);
	this->setPosX(-5);
	this->setOri(downwards);
	this->_life = 100;
	this->set_color(COLOR_GREEN);
	// std::cout << "[default constructor] New Player Boss !" << std::endl;
}

Boss::~Boss()
{
	// std::cout << "[Destructor] Boss died !" << std::endl;
}

Boss::Boss(Game *game, Boss const & src) : Enemy(game), _life(src._life), _posX(src._posX), _posY(src._posY)
{
	// std::cout << "[Copie constructor] New Boss !" << std::endl;
}

Boss &		Boss::operator=(Boss const & rhs)
{
	this->_life = rhs._life;
	this->_posX = rhs._posX;
	this->_posY = rhs._posY;
	return (*this);
}

void			Boss::update()
{
	if (this->_posX <= 10)
	{
		this->setPosX(this->_posX + 2);
		return ;
	}
	else
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

void			Boss::takeDamage(unsigned int i)
{
	int		tmp;

	(void)i;
	tmp = this->_life - 5;
	if (tmp <= 0)
	{
		this->to_delete = 1;
	}
	else
		this->_life--;
}
