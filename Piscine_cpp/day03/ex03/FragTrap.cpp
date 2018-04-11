/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:43:47 by malorin           #+#    #+#             */
/*   Updated: 2018/03/29 22:43:48 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "[FragTrap] " << getName() << ": 'Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!'" << std::endl;
	this->_Hit_points = 100;
	this->_Max_hit_points = 100;
	this->_Level = 1;
	this->_Energy_points = 100;
	this->_Energy_points = 100;
	this->_Melee_attack_damage = 30;
	this->_Ranged_attack_damage = 25;
	this->_Armor_damage_reduction = 5;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] " << getName() << ": I'M DEAD I'M DEAD OHMYGOD I'M DEAD!'" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
}

FragTrap::FragTrap(std::string const newName)
{
	this->setName(newName);
	std::cout << "[FragTrap] " << getName() << ": 'Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!'" << std::endl;
	this->_Hit_points = 100;
	this->_Max_hit_points = 100;
	this->_Level = 1;
	this->_Energy_points = 100;
	this->_Energy_points = 100;
	this->_Melee_attack_damage = 30;
	this->_Ranged_attack_damage = 25;
	this->_Armor_damage_reduction = 5;
}

FragTrap &		FragTrap::operator=(FragTrap const & src)
{	
	this->_name = src.getName();
	this->_Hit_points = src._Hit_points;
	this->_Max_hit_points = src._Max_hit_points;
	this->_Energy_points = src._Energy_points;
	this->_Max_energy_points = src._Max_energy_points;
	this->_Level = src._Level;
	this->_Melee_attack_damage = src._Melee_attack_damage;
	this->_Ranged_attack_damage = src._Ranged_attack_damage;
	this->_Armor_damage_reduction = src._Armor_damage_reduction;
	std::cout << "[FragTrap] " << getName() << ": 'Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!'" << std::endl;
	return (*this);
}

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string		tab[] = {"Splash", "Rm-Rf", "ZazPunch", "Licorn's dance", "Kamehameha", "PubMeteor"};
	if (this->_Energy_points > 0)
	{
		this->_Energy_points -= 25;
		std::cout << this->_name << " use his special attack " << tab[rand() % 5] << " to " << target << " and has now " << this->_Energy_points << " energy points left . It's very effectiv !" << std::endl;
	}
	else
	{
		std::cout << this->_name << " is exhausted !" << std::endl;
	}
}
