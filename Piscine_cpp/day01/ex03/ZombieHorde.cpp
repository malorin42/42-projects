/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:00:51 by malorin           #+#    #+#             */
/*   Updated: 2018/03/27 22:00:53 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(int N)
{
	std::string		tab_name[] = {"Zaz", "Thor", "Ol", "Niel", "Malorin", "Bobby"};
	std::string		tab_type[] = {"Infected", "Hunter", "Male", "Female", "Boomer", "Dev 42"};
	int		i = 0;
	horde = new Zombie[N];
	znumber = N;

	while (i < N)
	{
		horde[i].name = tab_name[rand() % 5];
		horde[i].type = tab_type[rand() % 5];
		i++;
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] horde;
	std::cout << "The Zombie Horde died !" << std::endl;
}

void		ZombieHorde::announce()
{
	int		i = 0;

	while (i < znumber)
	{
		horde[i].announce();
		i++;
	}
}

