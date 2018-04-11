/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:05:55 by malorin           #+#    #+#             */
/*   Updated: 2018/03/28 17:05:56 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	setType(str);
}

Weapon::~Weapon(){}

void				Weapon::setType(std::string newType)
{
	type = newType;
}

std::string const &	Weapon::getType(void)
{
	std::string const &		typeRef = type;
	return(typeRef);
}
