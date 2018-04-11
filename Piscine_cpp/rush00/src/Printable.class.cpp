#include "Printable.class.hpp"
#include <string.h>

Printable::Printable()
{
	char	buff[64] = ERR_BTM;
	t_bitmap btm;
	memcpy(&btm.bitmap, &buff, 64);
	this->set_bitmap(btm);

	this->_color = COLOR_WHITE;
}

Printable::Printable(int color)
{
	char	buff[64] = ERR_BTM;
	t_bitmap btm;
	memcpy(&btm.bitmap, &buff, 64);
	this->set_bitmap(btm);

	this->_color = color;
}

Printable::Printable(t_bitmap bitmap)
{
	this->set_bitmap(bitmap);

	this->_color = COLOR_WHITE;
}

Printable::Printable(int color, t_bitmap bitmap)
{
	this->set_bitmap(bitmap);

	this->_color = color;
}

Printable::Printable(Printable const& ref)
{
	*this = ref;
}

Printable::~Printable()
{

}

Printable & Printable::operator=(Printable const & rhs)
{
	this->_bitmap = rhs._bitmap;
	this->_color = rhs._color;
	return (*this);
}

void		Printable::print(WINDOW *win, int x, int y)
{
	this->print(win, x, y, upwards);
}

void		Printable::print(WINDOW *win, int pos_x, int pos_y, int orientation)
{
	this->print(win, pos_x, pos_y, this->_color, orientation);
}

void		Printable::print(WINDOW *win, int pos_x, int pos_y, int color, int o)
{
	int x;
	int y;

	x = 0;
	y = 0;
	init_pair(COLOR_RED, COLOR_RED, COLOR_RED);
	init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLUE);
	init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_GREEN);
	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_WHITE);
	init_pair(COLOR_YELLOW, COLOR_WHITE, COLOR_BLACK);
	
	attron(COLOR_PAIR(color));
	while (x < 8)
	{
		while (y < 8)
		{
			if (this->_bitmap.bitmap[(((o == upwards || o == downwards ? x : y)) * 8) + (o == upwards || o == downwards ? y :x)] > 0)
				mvwprintw(win, pos_x + (o != left && o != downwards ? x : 8 - x) , pos_y + (o != right && o != downwards ? y : 8 - y), "#");
			// else
			// {
			// attron(COLOR_PAIR(3));
			// 	mvwprintw(win, pos_x + (o != left && o != downwards ? x : 8 - x) , pos_y + (o != right && o != downwards ? y : 8 - y), "#");
			// 	attroff(COLOR_PAIR(3));
			// }
			y++;
		}
		y = 0;
		x++;
	}
	attroff(COLOR_PAIR(color));
}

int			Printable::hitBox(WINDOW *win, int pos_x, int pos_y, int o, int testX, int testY)
{
	int x;
	int y;

	x = 0;
	y = 0;
	(void)win;
	(void)pos_x;
	(void)pos_y;
	(void)testX;
	(void)testY;
	while (x < 8)
	{
		while (y < 8)
		{
			if (this->_bitmap.bitmap[(((o == upwards || o == downwards ? x : y)) * 8) + (o == upwards || o == downwards ? y :x)] > 0)
			{
				// mvwprintw(win, pos_x + (o != left && o != downwards ? x : 8 - x) , pos_y + (o != right && o != downwards ? y : 8 - y), "#");
				if (pos_x + (o != left && o != downwards ? x : 8 - x) == testX && pos_y + (o != right && o != downwards ? y : 8 - y) == testY)
					return(1);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

void		Printable::set_color(int color)
{
	this->_color = color;
}

void		Printable::set_bitmap(t_bitmap btm)
{
	this->_bitmap = btm;
}

t_bitmap	Printable::get_bitmap()
{
	return (this->_bitmap);
}
