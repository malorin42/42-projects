/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:20:42 by malorin           #+#    #+#             */
/*   Updated: 2018/03/31 17:20:43 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHIP_CLASS_HPP
# define SHIP_CLASS_HPP

#include "GameEntities.class.hpp"
#include "Printable.class.hpp"
#include "Pew.class.hpp"
#include "Game.class.hpp"

class Ship : public GameEntities
{
private:
	Printable		_sprite;
	unsigned int	_life;
	int				_posX;
	int				_posY;
	int				_ori;

public:
	Ship();
	Ship(Game *game);
	Ship(Game *game, Ship const & src);
	virtual ~Ship();
	virtual Ship 	& operator=(Ship const & rhs);

	int				getPosX();
	int				getPosY();
	void			setPosX(int newpos);
	void			setPosY(int newpos);
	virtual void	takeDamage(unsigned int amount);
	int				damage(int amount);
	void			setBitmap(t_bitmap btm);
	void			set_color(int color);
	void			setOri(int ori);
	void			shoot();
	void			shoot(int speed);
	virtual	void	update() = 0;
	void			draw(WINDOW *win);
	int				canCollide();
	int				tryCollision(int x, int y, int damage);
	// private:
};

#endif
