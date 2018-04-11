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
#include "ClapTrap.hpp"


int		main()
{
	ScavTrap	Robot1("Zaz");
	FragTrap	Robot2("Thor");

	std::srand(std::time(0));
	std::cout << "Test Basic meleeAttack" << std::endl;
	Robot1.meleeAttack("a little bird");
	Robot2.meleeAttack("a sweat child");
	std::cout << std::endl;
	std::cout << "Test Basic rangedAttack" << std::endl;
	std::cout << std::endl;
	Robot1.rangedAttack("a little bird");
	Robot2.rangedAttack("a sweat child");
	std::cout << std::endl;
	std::cout << "Test Damage" << std::endl;
	std::cout << std::endl;
	Robot1.takeDamage(10);
	Robot1.takeDamage(60);
	Robot1.takeDamage(50);
	std::cout << std::endl;
	Robot2.takeDamage(10);
	Robot2.takeDamage(60);
	Robot2.takeDamage(50);
	std::cout << std::endl;
	std::cout << "Test healing" << std::endl;
	std::cout << std::endl;
	Robot1.beRepaired(20);
	Robot1.beRepaired(100);
	Robot1.beRepaired(20);
	std::cout << std::endl;
	Robot2.beRepaired(20);
	Robot2.beRepaired(100);
	Robot2.beRepaired(20);
	std::cout << std::endl;
	std::cout << "Test Special function" << std::endl;
	std::cout << std::endl;
	Robot1.challengeNewcomer();
	Robot2.vaulthunter_dot_exe("Ol");
	std::cout << std::endl;
}
