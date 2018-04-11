/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:40:22 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 16:40:22 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <iostream>

class ScavTrap {

public:

	ScavTrap(void);
    ScavTrap(std::string const name);
	ScavTrap(ScavTrap const & src);
    ~ScavTrap(void);

	ScavTrap &		operator=(ScavTrap const &);
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			setName(std::string const name);
	std::string		getName(void) const;
	void			challengeNewcomer();

private:

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
