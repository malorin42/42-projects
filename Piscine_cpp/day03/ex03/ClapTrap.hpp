/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:04:20 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 18:04:21 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{

public:
	ClapTrap(void);
	ClapTrap(std::string const name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);
	
	ClapTrap &		operator=(ClapTrap const &);
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			setName(std::string const name);
	std::string		getName(void) const;

protected:
	std::string		_name;
	int				_Hit_points;
	int				_Max_hit_points;
	int				_Energy_points;
	int				_Max_energy_points;
	int				_Level;
	int				_Melee_attack_damage;
	int				_Ranged_attack_damage;
	int				_Armor_damage_reduction;
};

#endif
