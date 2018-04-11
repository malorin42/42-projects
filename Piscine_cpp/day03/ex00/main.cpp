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

int		main()
{
	FragTrap	Robot1;
	FragTrap	Robot2("Bob");
	FragTrap	Robot3(Robot1);
	Robot1 = Robot2;

	std::srand(std::time(0));
	Robot1.rangedAttack("a little bird");
	Robot2.meleeAttack("a sweat child");
	Robot3.takeDamage(10);
	Robot3.takeDamage(60);
	Robot3.takeDamage(50);
	Robot3.beRepaired(20);
	Robot3.beRepaired(100);
	Robot3.beRepaired(20);
	Robot1.vaulthunter_dot_exe("Thor");
	Robot1.vaulthunter_dot_exe("Thor");
	Robot1.vaulthunter_dot_exe("Niel");
	Robot1.vaulthunter_dot_exe("Ol");
	Robot1.vaulthunter_dot_exe("Thor");
}
