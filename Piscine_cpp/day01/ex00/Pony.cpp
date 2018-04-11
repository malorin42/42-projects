/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:31:11 by malorin           #+#    #+#             */
/*   Updated: 2018/03/27 14:31:13 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Pony.hpp"
#include <string>
#include <iostream>

Pony::Pony() : stamina(100), weight(250)
{
	std::string		tmp;
	std::cout << "Hello, who are you ? ";
	std::getline(std::cin, owner);
	std::cout << "How do you want to name your Pony? ";
	std::getline(std::cin, name);

	std::cout << "Ok " << owner << ", " << name << " is ready !" << std::endl;
}

Pony::~Pony(void)
{
	std::cout << "R.I.P " << name << std::endl;
}

void 	Pony::pony_run()
{
	if (stamina < 10)
	{
		std::cout << "Wow calm down , " << name << " have no more stamina !" << std::endl;
		return ;
	}
	else
	{
		if (weight > 300)
		{
			stamina = 0;
			std::cout << owner << " : " << "Run Big Boy !!" << std::endl;
			std::cout << "The Pony is run hard." << std::endl;
		}
		else
		{
			stamina -= 40;
			std::cout << owner << " : " << "Run Big Boy !!" << std::endl;
			std::cout << "The Pony is running." << std::endl;
		}
		weight -= 10;
	}
	return ;
}

void 	Pony::pony_eat()
{
	std::cout << owner << " give an apple.." << std::endl;
	std::cout << "The Pony is eating." << std::endl;
	weight += 25;
	stamina += 20;
}

void 	Pony::pony_sleep()
{
	std::cout << owner << " knock the pony !" << std::endl;
	std::cout << "The Pony is sleeping." << std::endl;
	stamina += 100;
}
