/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntities.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:14:27 by malorin           #+#    #+#             */
/*   Updated: 2018/03/31 18:14:28 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "GameEntities.class.hpp"
#include "Game.class.hpp"

GameEntities::GameEntities(Game *game) : _nextNode(NULL){
	// std::cout << "GameEntities created." << std::endl;
	this->to_delete = 0;
	this->_game = game;
	this->_nextNode = NULL;
	_game->registerGameEntity(this);
	// std::cout << "GameEntities registered." << std::endl;
}

GameEntities::~GameEntities()
{
	// std::cout << "GameEntities destroy." << std::endl;
}

GameEntities::GameEntities(GameEntities const & src)
{
	*this = src;
}

GameEntities	& GameEntities::operator=(GameEntities const &)
{
	return (*this);
}

void					GameEntities::draw(WINDOW *win)
{
	(void)win;
	return ;
}

void					GameEntities::update()
{
	// std::cout << "Hello World" << std::endl;
}

int GameEntities::canCollide()
{
	return (0);
}

int GameEntities::damage(int i)
{
	(void)i;
	return (0);
}

int GameEntities::tryCollision(int x, int y, int damages)
{
	(void)damages;
	(void)x;
	(void)y;
	return (0);
}

int	GameEntities::ft_z(void)
{
	return (0);
}
