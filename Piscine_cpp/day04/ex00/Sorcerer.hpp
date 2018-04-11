/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:47:53 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 20:47:54 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SORCERER_HPP
# define SORCERER_HPP

#include "Victim.hpp"
#include <iostream>

class Sorcerer
{
public:
	Sorcerer();
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer & src);
	~Sorcerer();

	Sorcerer &	operator=(Sorcerer & rhs);	
	std::string	getName() const;
	std::string	getTitle() const;
	void	polymorph(Victim const &) const;

private:
	std::string	_name;
	std::string	_title;
};

std::ostream &	operator<<(std::ostream & o, Sorcerer const & rhs);

#endif