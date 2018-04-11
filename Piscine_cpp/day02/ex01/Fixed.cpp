/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:00:42 by malorin           #+#    #+#             */
/*   Updated: 2018/03/29 16:00:43 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;

	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

	return ;
}

Fixed::Fixed(int const i)
{
	std::cout << "Int constructor called" << std::endl;

	setRawBits(i << _bit);
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;

	setRawBits(roundf(f * (1 << _bit)));
}

void		Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

Fixed &		Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		this->_raw = rhs.getRawBits();

	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

int			Fixed::getRawBits(void) const
{
	return (this->_raw);
}


int			Fixed::toInt(void) const
{
	return (getRawBits() >> this->_bit);
}

float		Fixed::toFloat(void) const
{
	float	n;

	n = getRawBits();
	return (n / (1 << this->_bit));
}