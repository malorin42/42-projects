#ifndef PRINTABLE_CLASS_HPP
# define PRINTABLE_CLASS_HPP

#include <ncurses.h>

enum orientation {upwards, downwards, left, right};

typedef struct	s_bitmap
{
	char		bitmap[64];
}				t_bitmap;

#define ERR_BTM			{ 0, 0, 0, 0, 0, 0, 0, 0, \
						  0, 0, 0, 0, 0, 0, 0, 0, \
						  0, 0, 0, 0, 0, 0, 0, 0, \
						  1, 1, 0, 1, 1, 0, 0, 0, \
						  1, 0, 0, 1, 0, 1, 0, 0, \
						  1, 1, 0, 1, 1, 0, 0, 0, \
						  1, 0, 0, 1, 0, 1, 0, 0, \
						  1, 1, 0, 1, 0, 1, 0, 0 }

#define SHIP_MODEL_A	{ 0, 0, 0, 1, 1, 0, 0, 0, \
						  0, 2, 0, 1, 1, 0, 2, 0, \
						  1, 1, 0, 1, 1, 0, 1, 1, \
						  1, 1, 0, 1, 1, 0, 1, 1, \
						  0, 1, 1, 1, 1, 1, 1, 0, \
						  0, 1, 1, 0, 0, 1, 1, 0, \
						  0, 0, 0, 0, 0, 0, 0, 0,  \
						  0, 0, 0, 0, 0, 0, 0, 0 }

#define SHIP_MODEL_B	{ 1, 0, 0, 0, 0, 0, 1, 0, \
						  0, 1, 0, 1, 0, 1, 0, 0, \
						  0, 1, 1, 1, 1, 1, 0, 1, \
						  0, 0, 1, 1, 1, 0, 1, 0, \
						  0, 0, 0, 0, 0, 0, 0, 0, \
						  0, 0, 0, 0, 0, 0, 0, 0, \
						  0, 0, 0, 0, 0, 0, 0, 0, \
						  0, 0, 0, 0, 0, 0, 0, 0 }

#define SHIP_BOSS		{ 0, 0, 0, 2, 2, 0, 0, 0, \
						  0, 2, 2, 1, 1, 2, 2, 0, \
						  0, 1, 0, 0, 0, 0, 1, 0, \
						  2, 1, 0, 1, 1, 0, 1, 2, \
						  1, 1, 0, 1, 1, 0, 1, 1, \
						  1, 1, 0, 0, 0, 0, 1, 1, \
						  1, 0, 0, 0, 0, 0, 0, 1, \
						  1, 0, 0, 0, 0, 0, 0, 1 }


#define ASTEROID		{ 0, 0, 0, 0, 0, 0, 0, 0, \
						  0, 0, 1, 1, 1, 0, 0, 0, \
						  0, 1, 1, 1, 1, 0, 0, 0, \
						  1, 1, 1, 1, 1, 1, 1, 0, \
						  1, 1, 1, 1, 1, 1, 1, 1, \
						  0, 1, 1, 1, 1, 1, 1, 0, \
						  0, 0, 0, 0, 0, 1, 1, 0, \
						  0, 0, 0, 0, 0, 0, 0, 0 }


class Printable
{
private:
	int			_color;
	t_bitmap	_bitmap;

public:
	Printable();
	Printable(int color);
	Printable(t_bitmap bitmap);
	Printable(int color, t_bitmap bitmap);
	Printable(Printable const& ref);
	~Printable();
	Printable & operator=(Printable const & rhs);

	void		print(WINDOW *win, int x, int y);
	void		print(WINDOW *win, int x, int y, int orientation);
	void		print(WINDOW *win, int x, int y, int color, int orientation);

	int			hitBox(WINDOW *win, int x, int y, int orientation, int textX, int testY);

	void		set_color(int color);
	void		set_bitmap(t_bitmap btm);
	void		set_bitmap(char btm[64]);
	t_bitmap	get_bitmap();
};

#endif
