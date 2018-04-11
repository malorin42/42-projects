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

ScavTrap::ScavTrap() : _name("SV4G-TP"), _Hit_points(100), _Max_hit_points(100), _Energy_points(50), _Max_energy_points(50), _Level(1), _Melee_attack_damage(20), _Ranged_attack_damage(15), _Armor_damage_reduction(3)
{
	std::cout << getName() << " : 'Hello, i'm a Pandoracorn's butthole!'" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << getName() << ": 'I'll stop talking when I'm dead!'" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
}

ScavTrap::ScavTrap(std::string const newName) : _Hit_points(100), _Max_hit_points(100), _Energy_points(50), _Max_energy_points(50), _Level(1), _Melee_attack_damage(20), _Ranged_attack_damage(15), _Armor_damage_reduction(3)
{
	this->setName(newName);
	std::cout << "Jack : 'Your new designation is " << this->_name << " . You are a servant machine. Got it?'" << std::endl;

}

void			ScavTrap::setName(std::string const newName)
{
	this->_name = newName;
}

std::string		ScavTrap::getName(void) const
{
	return (this->_name);
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
	std::cout << this->_name << ": 'Does this mean I can start dancing? Pleeeeeeaaaaase?'" << std::endl;
	return (*this);
}

void			ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_name << " : 'Take that!''   " << target << " get hit by a ranged attack causing " << this->_Ranged_attack_damage << " points of damages !" << std::endl;
}

void			ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_name << " : 'Heyyaaah''   " << target << " get hit by a melee attack causing " << this->_Melee_attack_damage << " points of damages !" << std::endl;	
}

void			ScavTrap::takeDamage(unsigned int amount)
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

void			ScavTrap::beRepaired(unsigned int amount)
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