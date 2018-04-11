/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:38:56 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 21:38:57 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"
#include <iostream>

class Peon : public Victim
{
public:
	Peon();
	Peon(std::string name);
	Peon(Peon & src);
	virtual ~Peon();

	virtual void	getPolymorphed() const;
};

std::ostream &	operator<<(std::ostream & o, Peon const & rhs);

#endif
