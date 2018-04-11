#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "Printable.class.hpp"

void print_in_middle(WINDOW *win, int starty, int startx, int width, std::string str);
int main()
{	initscr();			/* Start curses mode 		*/
	if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	curs_set(0);
	// wresize(stdscr, 120, 120);
	// resizeterm(120, 120);
	// refresh();
	start_color();			/* Start color 			*/
	// init_pair(1, COLOR_RED, COLOR_BLUE);
    //
	// attron(COLOR_PAIR(1));
	// print_in_middle(stdscr, LINES / 2, 0, 0, std::string("Viola !!! In color ..."));
	// attroff(COLOR_PAIR(1));
	char	buff[64] = SHIP_MODEL_A;
	t_bitmap btm;
	memcpy(&btm.bitmap, &buff, 64);
	Printable *ship = new Printable(COLOR_RED, btm);
	ship->print(stdscr, 16, 16);
	ship->print(stdscr, 16, 32, left);
	ship->print(stdscr, 16, 48, right);
	ship->print(stdscr, 16, 64, downwards);

    	getch();
	endwin();
}
void print_in_middle(WINDOW *win, int starty, int startx, int width, std::string str)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(str.c_str());
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", str.c_str());
	refresh();
}
