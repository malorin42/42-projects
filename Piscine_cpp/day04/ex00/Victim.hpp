/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:25:31 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 21:25:32 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim
{
public:
	Victim();
	Victim(std::string name);
	Victim(Victim & src);
	virtual ~Victim();

	Victim &	operator=(Victim & rhs);	
	std::string	getName() const;
	virtual void	getPolymorphed() const;

protected:
	std::string	_name;
};

std::ostream &	operator<<(std::ostream & o, Victim const & rhs);

#endif