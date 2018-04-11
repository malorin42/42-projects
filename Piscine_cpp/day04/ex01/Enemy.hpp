/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:07:01 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 23:07:03 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENNEMY_HPP
 #define ENNEMY_HPP

#include <string>

class Enemy
{
	protected:
		std::string const	_type;
		int					_HP;

	public:
		Enemy();
		Enemy(Enemy const &);
		Enemy(int hp, std::string const & type);
		virtual ~Enemy();
		std::string const &		getType() const;
		int 					getHP() const;
		virtual void 			takeDamage(int);
		Enemy &					operator=(Enemy const &);
};
#endif