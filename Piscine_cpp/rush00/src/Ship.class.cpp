/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:20:54 by malorin           #+#    #+#             */
/*   Updated: 2018/03/31 17:20:56 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>

#include "Ship.class.hpp"

Ship::Ship(Game *game) : GameEntities(game)
{
	char	buff[64] = ERR_BTM;
	t_bitmap btm;
	memcpy(&btm.bitmap, &buff, 64);
	this->_sprite = Printable(COLOR_RED, btm);
	// std::cout << "[Default Constructor] A new Ship popped !" << std::endl;
}

Ship::~Ship()
{
	// std::cout << "[Destructor] *Ship Explosion* !" << std::endl;
}

Ship::Ship(Game *game, Ship const & src) : GameEntities(game), _sprite(src._sprite),  _life(src._life), _posX(src._posX), _posY(src._posY), _ori(upwards)
{
	// std::cout << "[Copie constructor] New Ship !" << std::endl;
}

Ship &		Ship::operator=(Ship const & rhs)
{
	this->_sprite = rhs._sprite;
	this->_life = rhs._life;
	this->_posX = rhs._posX;
	this->_posY = rhs._posY;
	return (*this);
}

int				Ship::getPosX()
{
	return (this->_posX);
}

int				Ship::getPosY()
{
	return (this->_posY);
}

void			Ship::setPosX(int newpos)
{
	this->_posX = newpos;
}

void			Ship::setPosY(int newpos)
{
	this->_posY = newpos;
}

void			Ship::takeDamage(unsigned int i)
{
	if ((this->_life - i) <= 0)
		this->to_delete = 1;
	else
		this->_life--;
}

int			Ship::damage(int i)
{
	this->takeDamage(i);
	return (this->_life);
}


void			Ship::setBitmap(t_bitmap btm)
{
	this->_sprite.set_bitmap(btm);
}

void			Ship::setOri(int ori)
{
	this->_ori = ori;
}

void			Ship::set_color(int color)
{
	this->_sprite.set_color(color);
}

void			Ship::shoot()
{
	this->shoot(4);
}

void			Ship::shoot(int speed)
{
	int x;
	int y;
	char btm[64];
	// mvwprintw(stdscr, 20, 50, "%i, %i", this->getPosX(), this->getPosY());
	memcpy(btm, (void *)(this->_sprite.get_bitmap().bitmap), 64);

	x = 0;
	y = 0;
	while(y < 8)
	{
		while(x < 8)
		{
			if (btm[(y * 8) + x] == 2)
			{
				new Pew(this->_game,
					this->getPosY() + x + (this->_ori == left ? 4 : this->_ori == right ? -4 : 0),
					this->getPosX() + y + (this->_ori == upwards ? -4 : this->_ori == downwards ? 4 : 0),
					this->_ori, speed);
			}
			x++;
		}
		if (this->_game->chk_collide(this, this->_posY + 1, this->_posX + 1, 5) ||
			this->_game->chk_collide(this, this->_posY + 9, this->_posX + 1, 5) ||
			this->_game->chk_collide(this, this->_posY + 1, this->_posX + 9, 5) ||
			this->_game->chk_collide(this, this->_posY + 9, this->_posX + 9, 5))
			this->to_delete = 1;
		x = 0;
		y++;
	}

	// new Pew(this->_game, this->getPosY(), this->getPosX(), upwards);
}

void			Ship::draw(WINDOW *win)
{
	// std::cout << "one drawed | ";
	this->_sprite.print(win, this->_posX, this->_posY, this->_ori);
	// refresh();
	(void) win;
}

int 			Ship::canCollide()
{
	return (1);
}

int				Ship::tryCollision(int x, int y, int damage)
{
	//if (this->_sprite.hitBox(this->_game->getWin(), this->_posX, this->_posY, this->_ori, x, y))
	if (this->_posX < y && this->_posX + 8 > y && this->_posY < x && this->_posY + 8 > x)
	{
		this->takeDamage(damage);
		return (1);
	}
	return(0);
}

// void			Ship::move()
// {
//
// }
//
// void			Ship::checkCollision(int x, int y)
// {
//
// }

void			Ship::update(void)
{

	// std::cout << "Hello, i'm a Ship " << std::endl;
}
