/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:39:00 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 21:39:01 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include <iostream>

Peon::Peon(std::string name): Victim(name) {

	this->_name = name;
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon & src): Victim(src) {

	*this = src;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {

	std::cout << "Bleuark..." << std::endl;	
}

std::ostream &	operator<<(std::ostream & o, Peon const & rhs) {

	o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;	
	return o;
}

void	Peon::getPolymorphed() const {

	std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}