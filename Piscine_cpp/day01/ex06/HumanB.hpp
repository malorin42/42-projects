/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:06:30 by malorin           #+#    #+#             */
/*   Updated: 2018/03/28 17:06:31 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
public:
	HumanB(std::string newName);
	~HumanB();
	
	std::string			name;
	Weapon *			myWeapon;

	void				attack(void);
	void				setWeapon(Weapon & type);	
};

#endif