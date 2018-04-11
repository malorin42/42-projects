/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShootingStar.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:25:18 by malorin           #+#    #+#             */
/*   Updated: 2018/04/01 21:25:19 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShootingStar.class.hpp"
#include <iostream>
#include <time.h>
#include "Game.class.hpp"


ShootingStar::ShootingStar(Game *game) : GameEntities(game)
{
	std::string		tab_name[] = {"x", "+", "*"};
	
	this->c = tab_name[rand() % 3];
}

ShootingStar::~ShootingStar(){}

ShootingStar &		ShootingStar::operator=(ShootingStar const & rhs)
{
	this->_posX = rhs._posX;
	this->_posY = rhs._posY;
	return (*this);
}

int				ShootingStar::getPosX()
{
	return (this->_posX);
}

int				ShootingStar::getPosY()
{
	return (this->_posY);
}

void			ShootingStar::setPosX(int newpos)
{
	this->_posX = newpos;
}

void			ShootingStar::setPosY(int newpos)
{
	this->_posY = newpos;
}

int				ShootingStar::ft_z(void)
{
	return (1);
}

void			ShootingStar::update()
{
	this->i++;
	if (this->i >= 30)
	{
		if ((this->getPosY() + 1) <= LINES)
			this->setPosY(this->getPosY() + 1);
		else
			this->to_delete = 1;
		this->i = 0;
	}
}

void			ShootingStar::draw(WINDOW *win)
{
	const char	*star = this->c.c_str();

	mvwprintw(win, this->getPosY(), this->getPosX(), star);
}
