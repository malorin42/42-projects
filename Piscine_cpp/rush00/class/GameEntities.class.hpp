/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntities.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:04:05 by malorin           #+#    #+#             */
/*   Updated: 2018/03/31 18:04:08 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITIES_CLASS_HPP
# define GAMEENTITIES_CLASS_HPP

#include <ncurses.h>
#include <iostream>

class Game;

class GameEntities
{
public:
	GameEntities();
	GameEntities(Game *game);
	GameEntities(GameEntities const & src);
	virtual ~GameEntities();
	virtual GameEntities 	& operator=(GameEntities const &);

	virtual void			update() = 0;
	virtual void			draw(WINDOW *win);
	virtual int				canCollide();
	virtual int				tryCollision(int x, int y, int damage);
	virtual int				damage(int damage);
	GameEntities			*_nextNode;
	Game					*_game;
	int						to_delete;

	virtual int				ft_z(void);

protected:
  // Variables membres

	bool _isManager;

};

#endif
