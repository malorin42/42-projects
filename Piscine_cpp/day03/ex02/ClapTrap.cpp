/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:04:14 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 18:04:15 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default")
{
	std::cout << "[ClapTrap] " << getName() << " : 'Let's get this party started!' *basic construction*" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] " << getName() << " : 'Why do I even feel pain?!' *destruction*" << std::endl;
}

ClapTrap::ClapTrap(std::string const newName)
{
	this->setName(newName);
	std::cout << "[ClapTrap] " << getName() << " : 'Let's get this party started!' *construction name*" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {

	std::cout << "[ClapTrap] " << getName() << " : 'New copied clap-trap'" << std::endl;
	*this = src;
	return;
}

void			ClapTrap::setName(std::string const newName)
{
	this->_name = newName;
}

std::string		ClapTrap::getName(void) const
{
	return (this->_name);
}

ClapTrap &  ClapTrap::operator=(ClapTrap const & src) {

	this->_name = src.getName();
	this->_Hit_points = src._Hit_points;
	this->_Max_hit_points = src._Max_hit_points;
	this->_Energy_points = src._Energy_points;
	this->_Max_energy_points = src._Max_energy_points;
	this->_Level = src._Level;
	this->_Melee_attack_damage = src._Melee_attack_damage;
	this->_Ranged_attack_damage = src._Ranged_attack_damage;
	this->_Armor_damage_reduction = src._Armor_damage_reduction;
	return *this;
}

void			ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_name << " attacks " << target << " at range, causing " << this->_Ranged_attack_damage << " points of damages !" << std::endl;
}

void			ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_name << " attacks " << target << " at melee, causing " << this->_Melee_attack_damage << " points of damages !" << std::endl;	
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	int		tmp_hit;
	int		damages;

	tmp_hit = this->_Hit_points;
	damages = amount - this->_Armor_damage_reduction;
	if (damages <= 0)
	{
		std::cout << "The " << this->_name << "'s armor is to big. The attacks didn't pass througt it." << std::endl;
		return ;
	}
	if ((tmp_hit - damages) < 0)
	{
		this->_Hit_points = 0;
		std::cout << this->_name << " get hit and took " << damages << " damages. It's nothing more than a pile of scrap." << std::endl;
	}
	else
	{
		this->_Hit_points -= damages;
		std::cout << this->_name << " get hit and took " << damages << " damages. He still have " << this->_Hit_points << "hit points." << std::endl;
	}
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	int		tmp_hit;

	tmp_hit = this->_Hit_points;
	if (tmp_hit == this->_Max_hit_points)
	{
		std::cout << this->_name << " is already fully repaired." << std::endl;
		return ;
	}
	if ((tmp_hit + (int)amount) > this->_Max_hit_points)
	{
		this->_Hit_points = this->_Max_hit_points;
		std::cout << this->_name << " is repaired by " << amount << " of hit points, and is now fully repaired." << std::endl;
	}
	else
	{
		this->_Hit_points += amount;
		std::cout << this->_name << " is repaired by " << amount << " of hit points, and has now " << this->_Hit_points << "hit points." << std::endl;
	}
}