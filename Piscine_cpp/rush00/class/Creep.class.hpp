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

#ifndef CREEP_CLASS_HPP
# define CREEP_CLASS_HPP

#include "Enemy.class.hpp"

class Creep : public Enemy
{
public:
	Creep();
	Creep(Game *game);
	Creep(Game *game, Creep const & src);
	virtual ~Creep();
	virtual Creep & operator=(Creep const & rhs);

	virtual void		update();
	virtual void		takeDamage(unsigned int amount);
	unsigned int	_life;
	int				i;

private:
	int				_posX;
	int				_posY;
};

#endif
