/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:06:01 by malorin           #+#    #+#             */
/*   Updated: 2018/03/28 17:06:02 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_HPP
# define Weapon_HPP

#include <iostream>
#include <string>

class Weapon
{
public:
	Weapon(std::string str);
	~Weapon();
	
	std::string				type;

	void					setType(std::string newType);
	std::string const &		getType(void);
};

#endif
