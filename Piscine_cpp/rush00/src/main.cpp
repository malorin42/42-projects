#include "Game.class.hpp"
#include "Enemy.class.hpp"
#include "Pew.class.hpp"
#include "Character.class.hpp"

int main()
{
	Game *game = new Game();
	game->execute();
	delete game;
}
