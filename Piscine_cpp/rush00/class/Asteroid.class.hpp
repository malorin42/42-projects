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

#ifndef ASTEROID_CLASS_HPP
# define ASTEROID_CLASS_HPP

#include "Enemy.class.hpp"

class Asteroid : public Enemy
{
public:
	Asteroid();
	Asteroid(Game *game);
	Asteroid(Game *game, Asteroid const & src);
	virtual ~Asteroid();
	virtual Asteroid & operator=(Asteroid const & rhs);

	virtual void		update();
	virtual void		takeDamage(unsigned int amount);
	unsigned int	_life;
	int				i;

private:
	int				_posX;
	int				_posY;
};

#endif
