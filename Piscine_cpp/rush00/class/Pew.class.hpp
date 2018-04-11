#ifndef PEW_CLASS_HPP
# define PEW_CLASS_HPP

# include "GameEntities.class.hpp"

class Pew : public GameEntities
{
public:
	Pew();
	Pew(Game *game, int x, int y, int ori, int speed);
	~Pew();

	Pew & operator=(Pew const & rhs);
	void	update();
	void	draw(WINDOW *win);
	int		canCollide();
	int		tryCollision(int x, int y, int dmg);
	int		speed;

private:
	int _i;
	int _x;
	int _y;
	int _ori;
};

#endif
