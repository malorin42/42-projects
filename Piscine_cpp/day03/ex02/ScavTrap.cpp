/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:40:18 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 16:40:19 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


ScavTrap::ScavTrap()
{
	std::cout << "[ScavTrap] " << getName() << " : 'Hello, i'm a Pandoracorn's butthole!'" << std::endl;
	this->_Hit_points = 100;
	this->_Max_hit_points = 100;
	this->_Level = 1;
	this->_Energy_points = 50;
	this->_Max_energy_points = 50;
	this->_Melee_attack_damage = 20;
	this->_Ranged_attack_damage = 15;
	this->_Armor_damage_reduction = 3;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] " << getName() << ": 'I'll stop talking when I'm dead!'" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
}

ScavTrap::ScavTrap(std::string const newName)
{
	this->setName(newName);
	std::cout << "[ScavTrap] : 'My new designation is " << this->_name << " . I'm a servant machine.'" << std::endl;
	this->_Hit_points = 100;
	this->_Max_hit_points = 100;
	this->_Level = 1;
	this->_Energy_points = 50;
	this->_Max_energy_points = 50;
	this->_Melee_attack_damage = 20;
	this->_Ranged_attack_damage = 15;
	this->_Armor_damage_reduction = 3;
}

ScavTrap &		ScavTrap::operator=(ScavTrap const & src)
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
	std::cout << "[ScavTrap] " << this->_name << ": 'Does this mean I can start dancing? Pleeeeeeaaaaase?'" << std::endl;
	return (*this);
}

void			ScavTrap::challengeNewcomer(void)
{
	std::string		specialChallenge[] = {"jump", "climb stairs", "find his G-Spot", "lick his elbow", "do a barrel roll"};

	if (this->_Energy_points > 0) {
		this->_Energy_points -= 25;
		std::cout << this->_name << " tries to " << specialChallenge[(rand() % 5)] << " and fail pathetically, he has now " << this->_Energy_points << " energy points left !" << std::endl;
	}
	else
		std::cout << this->_name << " is too tired !" << std::endl;
}