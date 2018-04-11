#include "GameEntities.class.hpp"
#include "Game.class.hpp"
#include "Enemy.class.hpp"
#include "Character.class.hpp"
#include "ShootingStar.class.hpp"
#include <time.h>

float Game::_hasTicked()
{
	static std::clock_t lastTick = 0;
	double duration;

	duration = std::clock() - lastTick;
	//std::cout<<"printf: "<< duration / CLOCKS_PER_SEC << " " << 1.0 / this->_ticksPerSec << "||||||||||||||||||||||||||||" ;
	if (duration / CLOCKS_PER_SEC > 1.0 / this->_ticksPerSec)
	{
		lastTick = std::clock();
		return (1);
	}
	return (0);
}

Game::Game() : _entities(NULL), i(0)
{
	initscr();
	if(has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	this->_win = stdscr;
	this->gameOver = 0;
	timeout(-1);
	curs_set(0);
	noecho();
	raw();
	keypad(this->_win, TRUE);
	nodelay(this->_win, TRUE);
	start_color();

	// this->_win = newwin(0, 0, 50, 50);
	this->setGameSpeed(60);

	Ship *player;
	player = new Character(this);
	player->setPosX(30);
	player->setPosY(20);

	char	buff[64] = SHIP_MODEL_A;
	t_bitmap btm;
	memcpy(&btm.bitmap, &buff, 64);
	player->setBitmap(btm);
	player->set_color(COLOR_BLUE);
	this->_hasTicked();
}

Game::~Game()
{
	endwin();
}

Game::Game(Game const& ref)
{
	this->_entities = ref._entities;
	this->_win = ref._win;
}

// void	Game::cleanupEntities()
// {
// 	GameEntities *curr;
// 	GameEntities **prec;
//
// 	prec = &this->_entities;
// 	while (this->_entities != NULL && (curr = this->_entities)->to_delete == 1)
// 	{
// 		(*prec) = curr->_nextNode;
// 		delete curr;
// 	}
// 	curr = this->_entities;
// 	while(curr != NULL)
// 	{
// 		if ()
// 	}
//
// }

int		Game::execute()
{
	int i;
	srand (time(NULL));
	GameEntities *curr;
	GameEntities **prec;

	i = 0;
	this->j = 0;
	while (1)
	{
		refresh();
		if (this->_hasTicked())
		{
			this->j++;
			this->i++;
			if (this->i >= 60)// tu fais spawn que tout les 30ticks
				this->createNewEnemy();
			if (this->j >= 40)
				this->createNewShootingStar();
			curr = this->_entities;
			while(curr != NULL)
			{
				curr->update();
				curr = curr->_nextNode;
			}


			prec = &this->_entities;
			curr = this->_entities;
			while(curr != NULL)
			{
				if (curr->to_delete == 1 || this->gameOver == 1)
				{
					(*prec) = curr->_nextNode;
					prec = &this->_entities;
					delete curr;
					curr = this->_entities;
					continue;
				}
				prec = &curr->_nextNode;
				curr = curr->_nextNode;
			}
			if (this->gameOver == 1)
				return (0);


			curr = this->_entities;
			clear();
			while (curr != NULL)
			{
				if (curr->ft_z() == 1)
					curr->draw(this->_win);
				curr = curr->_nextNode;
			}
			curr = this->_entities;
			while(curr != NULL)
			{
				if (curr->ft_z() == 0)
					curr->draw(this->_win);
				curr = curr->_nextNode;
			}
			refresh();
		}
	}
	return(0);
}

int		Game::chk_collide(GameEntities *itself, int x, int y, int dmg)
{
	GameEntities *curr;

	curr = this->_entities;
	while (curr != NULL)
	{
		// mvprintw(10, 10, "AAaaaaAAAAAAAAAAAAAAAAAAAAAAAAA");
		if (curr->canCollide() && curr != itself)
		{
			// mvprintw(10, 10, "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
			if (curr->tryCollision(x, y, dmg))
				return(1);
			// (void)x;
			// (void)y;
			// (void)dmg;
		}
		curr = curr->_nextNode;
	}
	return (0);
}

void	Game::registerGameEntity(GameEntities *newGE)
{
	if (newGE == NULL)
		return ;
	newGE->_nextNode = this->_entities;
	this->_entities = newGE;

	GameEntities *curr;
	curr = this->_entities;
	int i = 0;
	while (curr != NULL)
	{
		i++;
		curr = curr->_nextNode;
	}
	//std::cout << "added " << newGE << " to linked list, we whave now " << i << " entities." << std::endl;
}

void	Game::removeGameEntity(GameEntities *toRM)
{
	toRM->to_delete = 1;
}

void Game::setGameSpeed(int tps) {
	this->_ticksPerSec = tps;
}

WINDOW	*Game::getWin()
{
	return (this->_win);
}

Game& Game::operator=(Game const& rhs)
{
	(void)rhs;
	return(*this);
}

void		Game::createNewEnemy(void)
{
	Ship *enemy = new Enemy(this);

	char	buff[64] = SHIP_MODEL_B;
	t_bitmap btm;
	memcpy(&btm.bitmap, &buff, 64);
	enemy->setBitmap(btm);
	enemy->setPosY((rand() % COLS - 10) + 8);
	enemy->setPosX(-5);
	enemy->setOri(downwards);
	this->i = 0;
}

void		Game::createNewShootingStar(void)
{
	ShootingStar *star = new ShootingStar(this);

	star->setPosX((rand() % COLS));
	star->setPosY(0);
	this->j = 0;
}
