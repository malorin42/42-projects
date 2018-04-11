/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:16:37 by malorin           #+#    #+#             */
/*   Updated: 2018/03/27 17:16:38 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(): name("Bob"), type("Infected") {}

Zombie::~Zombie()
{
	std::cout << "<" << name << " (" << type << ")> *Died*" << std::endl;	
}

void		Zombie::announce()
{
	std::cout << "<" << name << " (" << type << ")> Braiiiiiiiiiiiinnnnsssss..." << std::endl;
}