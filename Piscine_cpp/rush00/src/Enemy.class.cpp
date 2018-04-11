/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:21:06 by malorin           #+#    #+#             */
/*   Updated: 2018/03/31 17:21:06 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Enemy.class.hpp"

Enemy::Enemy(Game *game) : Ship(game), _life(3), _posX(0), _posY(0)
{
	// std::cout << "[default constructor] New Player Enemy !" << std::endl;
}

Enemy::~Enemy()
{
	// std::cout << "[Destructor] Enemy died !" << std::endl;
}

Enemy::Enemy(Game *game, Enemy const & src) : Ship(game), _life(src._life), _posX(src._posX), _posY(src._posY)
{
	// std::cout << "[Copie constructor] New Enemy !" << std::endl;
}

Enemy &		Enemy::operator=(Enemy const & rhs)
{
	this->_life = rhs._life;
	this->_posX = rhs._posX;
	this->_posY = rhs._posY;
	return (*this);
}

void			Enemy::update()
{
	this->i++;
	if (this->i >= 5)
	{
		if ((this->getPosX() + 1) <= LINES + 10)
			this->setPosX(this->getPosX() + 1);
		else
			this->to_delete = 1;
		this->i = 0;
	}
	this->shoot();
}

void			Enemy::takeDamage(unsigned int i)
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
