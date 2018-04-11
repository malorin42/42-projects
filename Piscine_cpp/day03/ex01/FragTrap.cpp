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

FragTrap::FragTrap() : _name("FR4G-TP"), _Hit_points(100), _Max_hit_points(100), _Energy_points(100), _Max_energy_points(100), _Level(1), _Melee_attack_damage(30), _Ranged_attack_damage(20), _Armor_damage_reduction(5)
{
	std::cout << "Jack: ' "<< getName() << " -- start bootup sequence!'" << std::endl;
	std::cout << getName() << ": 'Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!'" << std::endl;
	std::cout << "Jack: 'No no no no! Cancel directive three!'" << std::endl;
	std::cout << getName() << ": 'Commencing directive three!' *Uhntssuhntssuhntss*"<< std::endl;
	std::cout << "*************************************" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << getName() << ": I'M DEAD I'M DEAD OHMYGOD I'M DEAD!'" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
}

FragTrap::FragTrap(std::string const newName) : _Hit_points(100), _Max_hit_points(100), _Energy_points(100), _Max_energy_points(100), _Level(1), _Melee_attack_damage(30), _Ranged_attack_damage(20), _Armor_damage_reduction(5)
{
	this->setName(newName);
	std::cout << "Jack: ' "<< getName() << " -- start Recompiling your combat code!'" << std::endl;
	std::cout << getName() << ": 'Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!'" << std::endl;
	std::cout << "Jack: 'No no no no! Cancel directive three!'" << std::endl;
	std::cout << getName() << ": 'Commencing directive three!' *Uhntssuhntssuhntss*"<< std::endl;
	std::cout << "*************************************" << std::endl;
}

void			FragTrap::setName(std::string const newName)
{
	this->_name = newName;
}

std::string		FragTrap::getName(void) const
{
	return (this->_name);
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
	std::cout << "Jaaaack: ' "<< this->_name << " -- start Recompiling your combat code!'" << std::endl;
	std::cout << this->_name << ": 'Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!'" << std::endl;
	std::cout << "Jack: 'No no no no! Cancel directive three!'" << std::endl;
	std::cout << this->_name << ": 'Commencing directive three!' *Uhntssuhntssuhntss*"<< std::endl;
	std::cout << "*************************************" << std::endl;
	return (*this);
}

void			FragTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_name << " attacks " << target << " at range, causing " << this->_Ranged_attack_damage << " points of damages !" << std::endl;
}

void			FragTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_name << " attacks " << target << " at melee, causing " << this->_Melee_attack_damage << " points of damages !" << std::endl;	
}

void			FragTrap::takeDamage(unsigned int amount)
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

void			FragTrap::beRepaired(unsigned int amount)
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
