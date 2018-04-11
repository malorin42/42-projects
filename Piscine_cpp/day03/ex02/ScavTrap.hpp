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
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:

	ScavTrap(void);
    ScavTrap(std::string const name);
	ScavTrap(ScavTrap const & src);
    ~ScavTrap(void);

	ScavTrap &		operator=(ScavTrap const &);
	void			challengeNewcomer();
};

#endif
