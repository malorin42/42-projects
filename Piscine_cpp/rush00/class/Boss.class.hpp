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

#ifndef BOSS_CLASS_HPP
# define BOSS_CLASS_HPP

#include "Enemy.class.hpp"

class Boss : public Enemy
{
public:
	Boss();
	Boss(Game *game);
	Boss(Game *game, Boss const & src);
	virtual ~Boss();
	virtual Boss & operator=(Boss const & rhs);

	virtual void		update();
	virtual void		takeDamage(unsigned int amount);
	unsigned int	_life;
	int				i;
	int				dir;

private:
	int				_posX;
	int				_posY;
};

#endif
