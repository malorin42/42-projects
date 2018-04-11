/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:08:06 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 23:08:07 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
 #define CHARACTER_HPP

#include <string>
#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
	std::string const		_name;
	AWeapon	*				_weapon;
	int						_AP;

	public:
	Character(std::string const & name);
	Character();
	Character(Character const &);
	~Character();
	Character & operator=(Character const &);
	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);
	std::string const &		getName() const;
	int 				getAP()const;
	AWeapon *			getWeapon()const;
};

std::ostream & operator<<(std::ostream & o, Character const & src);
#endif