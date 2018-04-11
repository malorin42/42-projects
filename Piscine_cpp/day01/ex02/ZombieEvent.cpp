/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:33:25 by malorin           #+#    #+#             */
/*   Updated: 2018/03/27 17:33:26 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() : ztype("Infected"){}

ZombieEvent::~ZombieEvent()
{}

void	ZombieEvent::setZombieType(std::string new_type)
{
	ztype = new_type;
}

Zombie*	ZombieEvent::randomChump(void)
{
	std::string		tab[] = {"Zaz", "Thor", "Ol", "Niel", "Malorin", "Bobby"};
	Zombie* 		zomb = newZombie(tab[rand() % 5]);

	zomb->announce();
	return (zomb);
}

Zombie*	ZombieEvent::newZombie(std::string name)
{
	Zombie 		*newZombie = new Zombie();

	newZombie->type = ztype;
	newZombie->name = name;
	return (newZombie);
}
