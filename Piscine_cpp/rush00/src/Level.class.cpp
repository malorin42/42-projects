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
#include "GameEntities.class.hpp"
#include "Game.class.hpp"
#include "Level.class.hpp"
#include "Asteroid.class.hpp"
#include "Creep.class.hpp"
#include "Boss.class.hpp"

Level::Level(Game *game) : GameEntities(game)
{
	this->_game = game;
	this->creeps = 5;
	this->asteroids = 5;
	this->i = 0;
}

Level::Level(Game *game, Level const & src)  : GameEntities(src) {(void)game; (void)src;}
Level::~Level() {}
Level &Level::operator=(Level const & rhs) {(void)rhs;return (*this);}

void		Level::update()
{
	if (i >= 5)
	{
		if (this->asteroids <= 0)
		{
			std::cout << "test";
			Asteroid *asteroid = new Asteroid(_game);
			asteroid->setPosY((rand() % COLS - 10) + 8);
			asteroid->setPosX(-5);
			this->asteroids--;
			i = 0;
			asteroid = NULL;
		}
		else if (this->creeps <= 0)
		{
			Creep *creep = new Creep(_game);
			creep->setPosY((rand() % COLS - 10) + 8);
			creep->setPosX(-5);
			this->creeps--;
			i = 0;
			creep = NULL;
		}
	i++;
	}
	if (this->asteroids <= 0 && this->creeps <= 0)
	{
		new Boss(_game);
		this->to_delete = 1;
	}
}
