/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:32:47 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 19:32:48 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap()
{
	std::cout << "[NinjaTrap] " << getName() << ": *Ninja Dance*" << std::endl;
	this->_Hit_points = 60;
	this->_Max_hit_points = 60;
	this->_Level = 1;
	this->_Energy_points = 120;
	this->_Energy_points = 120;
	this->_Melee_attack_damage = 60;
	this->_Ranged_attack_damage = 5;
	this->_Armor_damage_reduction = 0;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "[NinjaTrap] " << getName() << ": *Suicide with her own blade*" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
	*this = src;
}

NinjaTrap::NinjaTrap(std::string const newName)
{
	this->setName(newName);
	std::cout << "[NinjaTrap] " << getName() << ": *Ninja Dance*" << std::endl;
	this->_Hit_points = 60;
	this->_Max_hit_points = 60;
	this->_Level = 1;
	this->_Energy_points = 120;
	this->_Energy_points = 120;
	this->_Melee_attack_damage = 60;
	this->_Ranged_attack_damage = 5;
	this->_Armor_damage_reduction = 0;
}

NinjaTrap &		NinjaTrap::operator=(NinjaTrap const & src)
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
	std::cout << "[NinjaTrap] " << getName() << ": 'Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!'" << std::endl;
	return (*this);
}

void			NinjaTrap::ninjaShoebox(NinjaTrap const & target)
{
	std::cout << "[NinjaTrap] *" << getName() << " Throws a shuriken to "<< target.getName() << "*" << std::endl;
}

void			NinjaTrap::ninjaShoebox(ScavTrap const & target)
{
	std::cout << "[NinjaTrap] *" << getName() << " Jump behind " << target.getName() << " and kill him*" << std::endl;
}

void			NinjaTrap::ninjaShoebox(FragTrap const & target)
{
	std::cout << "[NinjaTrap] *" << getName() << " Dash and hit " << target.getName() << " with a katana*" << std::endl;
}