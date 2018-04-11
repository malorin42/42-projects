/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:21:18 by malorin           #+#    #+#             */
/*   Updated: 2018/03/31 17:21:19 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include "Ship.class.hpp"

class Enemy : public Ship
{
public:
	Enemy();
	Enemy(Game *game);
	Enemy(Game *game, Enemy const & src);
	virtual ~Enemy();
	virtual Enemy & operator=(Enemy const & rhs);

	virtual void		update();
	virtual void		takeDamage(unsigned int amount);
	unsigned int	_life;
	int				i;

private:
	int				_posX;
	int				_posY;
};

#endif
