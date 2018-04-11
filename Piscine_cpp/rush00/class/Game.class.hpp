#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include <ncurses.h>
# include <unistd.h>
# include <stdlib.h>
# include <iostream>
# include <cstdio>
# include <ctime>
# include "GameEntities.class.hpp"
# include "Ship.class.hpp"
# include "ShootingStar.class.hpp"

class Game
{
private:
	GameEntities	*_entities;
	WINDOW			*_win;
	int				_ticksPerSec;
	float			_hasTicked();

public:
	Game();
	~Game();
	Game(Game const& ref);

	Game& operator=(Game const& rhs);

	int		execute();
	void	setGameSpeed(int tps);
	int		chk_collide(GameEntities *itself, int x, int y, int dmg);
	void	cleanupEntities();

	void	createNewShootingStar(void);
	void	createNewEnemy(void);
	void	registerGameEntity(GameEntities *newEntity);
	void	removeGameEntity(GameEntities *entity);
	WINDOW	*getWin();

	int		i;
	int		j;
	int		gameOver;
};

#endif
