/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:03:47 by malorin           #+#    #+#             */
/*   Updated: 2018/03/27 18:03:48 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <ctime>

Zombie*	createNewZombie(ZombieEvent Event)
{
	std::string		buff;

	std::cout << "Let's create your Zombie, the Zombie type is set on '" << Event.ztype << "'..." << std::endl;
	std::cout << "Choose a name for your Zombie or Tape 'RANDOM' if you have a lack of imagination : ";
	std::getline(std::cin, buff);
	if (buff == "RANDOM")
		return(Event.randomChump());
	return (Event.newZombie(buff));
}

int		main()
{
	std::string		buff;
	std::string		new_type;
	int				set = 0;
	ZombieEvent		ZombieEvent;
	Zombie 			*Zomb;

	std::srand(std::time(0));
	std::cout << "Hello and Welcome to the Zombie Generator programe !" << std::endl << " To create your first Zombie, tape 'NEW' : ";
	while (1)
	{
		std::getline(std::cin, buff);
		if (buff == "NEW")
		{
			if (set == 1)
				delete Zomb;
			Zomb = createNewZombie(ZombieEvent);
			set = 1;
		}
		else if (buff == "SETTING")
		{
			std::cout << "Choose a zombie type (exemple : 'MALE', 'FEMALE', 'HUNTER', 'CLIMBER' etc...) : ";
			std::getline(std::cin, new_type);
			ZombieEvent.setZombieType(new_type);
			std::cout << "Zombie type is now set on : '"<< ZombieEvent.ztype << "'" << std::endl;
		}
		else if (buff == "BRAIN" && set == 1)
			Zomb->announce();
		else if (buff == "EXIT")
		{
			if (set == 1)
				delete Zomb;
			return (0);
		}
		else
			std::cout << "Error : Action not find !" << std::endl;
		std::cout << "Choose an action between ! Tape 'NEW' to create another Zombie, 'SETTING' to change Zombie type, 'BRAIN' to announce your Zombie, 'EXIT' to quite. ";
	}
}
