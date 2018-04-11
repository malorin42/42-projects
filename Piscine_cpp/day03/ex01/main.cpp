/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:44:07 by malorin           #+#    #+#             */
/*   Updated: 2018/03/29 22:44:08 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main()
{
	ScavTrap	Robot1;
	ScavTrap	Robot2("Bob");
	ScavTrap	Robot3(Robot1);
	Robot1 = Robot2;

	std::srand(std::time(0));
	std::cout << std::endl;
	Robot1.rangedAttack("a little bird");
	Robot2.meleeAttack("a sweat child");
	std::cout << std::endl;
	Robot3.takeDamage(10);
	Robot3.takeDamage(60);
	Robot3.takeDamage(50);
	std::cout << std::endl;
	Robot3.beRepaired(20);
	Robot3.beRepaired(100);
	Robot3.beRepaired(20);
	std::cout << std::endl;
	Robot2.challengeNewcomer();
	Robot2.challengeNewcomer();
	Robot2.challengeNewcomer();
	Robot3.challengeNewcomer();
	Robot3.challengeNewcomer();
	std::cout << std::endl;
}
