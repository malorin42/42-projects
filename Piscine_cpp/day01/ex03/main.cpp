/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:21:21 by malorin           #+#    #+#             */
/*   Updated: 2018/03/27 22:21:22 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <string>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int		main()
{
	ZombieHorde theHorde = ZombieHorde(78);
	std::cout << "A big fat Zombie horde is here !" << std::endl;
	theHorde.announce();
	std::cout << "* NUCLEAR LAUCH DETECTED *" << std::endl;
	return (0);
}
