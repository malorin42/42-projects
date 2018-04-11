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
#include "NinjaTrap.hpp"


int		main()
{
	ScavTrap	Robot1("Zaz");
	FragTrap	Robot2("Thor");
	NinjaTrap	Robot3("Xavier");
	NinjaTrap	Robot4("Nicolas");

	std::srand(std::time(0));
	std::cout << "Test Basic meleeAttack" << std::endl;
	Robot3.meleeAttack("a little bird");
	std::cout << std::endl;
	std::cout << "Test Basic rangedAttack" << std::endl;
	std::cout << std::endl;
	Robot3.rangedAttack("a little bird");
	std::cout << std::endl;
	std::cout << "Test Damage" << std::endl;
	std::cout << std::endl;
	Robot3.takeDamage(10);
	Robot3.takeDamage(60);
	Robot3.takeDamage(50);
	std::cout << std::endl;
	std::cout << "Test healing" << std::endl;
	std::cout << std::endl;
	Robot3.beRepaired(20);
	Robot3.beRepaired(100);
	Robot3.beRepaired(20);
	std::cout << std::endl;
	std::cout << "Test Special function ninjaShoebox" << std::endl;
	std::cout << std::endl;
	Robot3.ninjaShoebox(Robot1);
	Robot3.ninjaShoebox(Robot2);
	Robot3.ninjaShoebox(Robot4);
	std::cout << std::endl;
}
