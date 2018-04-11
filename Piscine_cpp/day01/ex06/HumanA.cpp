/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:06:21 by malorin           #+#    #+#             */
/*   Updated: 2018/03/28 17:06:22 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon & type) : name(newName), myWeapon(type)
{}

HumanA::~HumanA(){}

void			HumanA::attack(void)
{
	std::cout << myWeapon.getType() << std::endl;
}