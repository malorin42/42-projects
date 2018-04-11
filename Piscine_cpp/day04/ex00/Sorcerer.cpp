/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:48:04 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 20:48:05 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include <iostream>

Sorcerer::Sorcerer(std::string name, std::string title) {

	_name = name;
	_title = title;
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;	
}

Sorcerer::Sorcerer(Sorcerer & src) {

	*this = src;
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;	
}

Sorcerer::~Sorcerer() {

	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;	
}

Sorcerer &	Sorcerer::operator=(Sorcerer & rhs) {

	this->_name = rhs._name;
	this->_title = rhs._title;
	return *this;
}

std::string	Sorcerer::getName() const {

	return (this->_name);
}

std::string	Sorcerer::getTitle() const {

	return (this->_title);
}

std::ostream &	operator<<(std::ostream & o, Sorcerer const & rhs) {

	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;	
	return o;
}

void	Sorcerer::polymorph(Victim const & src) const {

	src.getPolymorphed();
}