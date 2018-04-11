/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:10:30 by malorin           #+#    #+#             */
/*   Updated: 2018/03/27 15:10:31 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

void	ponyOnTheHeap(void)
{
	Pony 			*myPony = new Pony();
	std::string		buff;

	while (1)
	{
		std::cout << "choose an action between 'EAT', 'RUN', 'SLEEP' or 'KILL' : ";
		std::getline(std::cin, buff);

		if (buff == "EAT")
			myPony->pony_eat();
		else if (buff == "RUN")
			myPony->pony_run();
		else if (buff == "SLEEP")
			myPony->pony_sleep();
		else if (buff == "KILL")
		{
			delete myPony;
			return ;
		}
		else
			std::cout << "This is not a correct action." << std::endl;
	}
}


void	ponyOnTheStack(void)
{
	Pony 			myPony;
	std::string		buff;

	while (1)
	{
		std::cout << "choose an action between 'EAT', 'RUN', 'SLEEP' or 'KILL' : ";
		std::getline(std::cin, buff);

		if (buff == "EAT")
			myPony.pony_eat();
		else if (buff == "RUN")
			myPony.pony_run();
		else if (buff == "SLEEP")
			myPony.pony_sleep();
		else if (buff == "KILL")
			return ;
		else
			std::cout << "This is not a correct action." << std::endl;
	}
}

int 	main(void)
{
	ponyOnTheHeap();
	std::cout << "Message after the ponyOnTheHeap function." << std::endl;
	ponyOnTheStack();
	std::cout << "Message after the ponyOnTheStack function." << std::endl;
	return (0);
}