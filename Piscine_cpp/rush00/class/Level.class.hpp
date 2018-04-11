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

#ifndef LEVEL_CLASS_HPP
# define LEVEL_CLASS_HPP

#include "GameEntities.class.hpp"

class Level : public GameEntities
{
public:
	Level();
	Level(Game *game);
	Level(Game *game, Level const & src);
	virtual ~Level();
	virtual Level & operator=(Level const & rhs);

	virtual void		update();
	int					asteroids;
	int					creeps;
	int					i;

private:
};

#endif
