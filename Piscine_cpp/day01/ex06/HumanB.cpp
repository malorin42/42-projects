/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:06:26 by malorin           #+#    #+#             */
/*   Updated: 2018/03/28 17:06:27 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string newName) : name(newName)
{}

HumanB::~HumanB(){}

void			HumanB::attack(void)
{
	std::cout << myWeapon->getType() << std::endl;
}

void			HumanB::setWeapon(Weapon & type)
{
	myWeapon = &type;
}