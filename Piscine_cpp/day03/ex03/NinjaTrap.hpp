/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:32:43 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 19:32:43 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_H
# define NINJATRAP_H

#include <iostream>
#include "ClapTrap.hpp"


class NinjaTrap : public ClapTrap
{

public:

	NinjaTrap(void);
    NinjaTrap(std::string const name);
	NinjaTrap(NinjaTrap const & src);
    ~NinjaTrap(void);

	NinjaTrap &		operator=(NinjaTrap const &);
	void			ninjaShoebox(NinjaTrap const & target);
	void			ninjaShoebox(FragTrap const & target);
	void			ninjaShoebox(ScavTrap const & target);
};

#endif
