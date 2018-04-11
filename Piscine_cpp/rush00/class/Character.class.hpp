/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:16:54 by malorin           #+#    #+#             */
/*   Updated: 2018/03/31 16:16:55 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

#include "Ship.class.hpp"

class Character : public Ship
{
public:
	Character();
	Character(Game *game);
	Character(Game *game, Character const & src);
	~Character();
	Character & operator=(Character const & rhs);

	void			update();
	void			takeDamage(unsigned int amount);
	unsigned int	_life;

private:
	int				_i;

};

#endif
