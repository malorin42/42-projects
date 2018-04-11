#include "Pew.class.hpp"
#include "Printable.class.hpp"
#include "Game.class.hpp"
#include <ncurses.h>


Pew::Pew(Game *game, int x, int y, int ori, int speed) : GameEntities(game)
{
	this->_i = 0;
	this->_x = x;
	this->_y = y;
	this->_ori = ori;
	this->speed = speed;
}

Pew::~Pew()
{

}

void	Pew::update()
{
	if (this->_i % speed == 1)
	{
		if (_ori == left || _ori == right)
			this->_x += (_ori == right ? 1 : -1);
		if (_ori == upwards || _ori == downwards)
			this->_y += (_ori == downwards ? 1 : -1);
	}
	this->_i++;
	if (this->_game->chk_collide(this, this->_x, this->_y, 5))
		this->to_delete = 1;
}

void	Pew::draw(WINDOW *win)
{
	char c[2];
	c[1] = '\0';
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	switch (this->_ori)
	{
		case upwards:
			*c = '^';
			break;
		case downwards:
			*c = 'v';
			break;
		case left:
			*c = '<';
			break;
		case right:
			*c = '>';
			break;
		default:
			*c = '*';
			break;
	}
	mvwprintw(win, this->_y, this->_x, c);
	attroff(COLOR_PAIR(2));
}

int Pew::canCollide()
{
	return (1);
}

int Pew::tryCollision(int x, int y, int damages)
{
	(void)damages;
	if (x == this->_x && y == this->_y)
	{
		this->_game->removeGameEntity(this);
		return (1);
	}
	return (0);
}

Pew	&	Pew::operator=(Pew const & rhs)
{
	this->_i = rhs._i;
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_ori = rhs._ori;
	return (*this);
}
