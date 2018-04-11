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
	// std::cout << "Default constructor called" << std::endl;

	return ;
}

Fixed::Fixed(Fixed const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
	
	return ;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;

	return ;
}

Fixed::Fixed(int const i)
{
	// std::cout << "Int constructor called" << std::endl;

	setRawBits(i << _bit);
}

Fixed::Fixed(float const f)
{
	// std::cout << "Float constructor called" << std::endl;

	setRawBits(roundf(f * (1 << _bit)));
}

void		Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

Fixed &		Fixed::operator=(Fixed const & rhs)
{
	// std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		this->_raw = rhs.getRawBits();

	return (*this);
}

Fixed 		Fixed::operator+(Fixed const & rhs)
{
	// std::cout << "Assignation operator called" << std::endl;
	Fixed	resultat;

	resultat.setRawBits(this->_raw + rhs._raw);

	return (resultat);
}

Fixed 		Fixed::operator-(Fixed const & rhs)
{
	// std::cout << "Assignation operator called" << std::endl;
	Fixed	resultat;

	resultat.setRawBits(this->_raw - rhs._raw);

	return (resultat);
}

Fixed 		Fixed::operator*(Fixed const & rhs)
{
	// std::cout << "Assignation operator called" << std::endl;
	Fixed	resultat;

	resultat._raw = (this->_raw * rhs._raw) >> this->_bit;

	return (resultat);
}

Fixed 		Fixed::operator/(Fixed const & rhs)
{
	// std::cout << "Assignation operator called" << std::endl;
	Fixed	resultat;

	resultat._raw = (this->_raw << this->_bit) / rhs._raw;

	return (resultat);
}

bool		Fixed::operator==(Fixed const & rhs)
{
	// std::cout << "Assignation operator called" << std::endl;

	if (this->getRawBits() == rhs.getRawBits())
		return (1);
	else
		return (0);
}

bool		Fixed::operator>(Fixed const & rhs)
{
	// std::cout << "Assignation operator called" << std::endl;

	if (this->getRawBits() > rhs.getRawBits())
		return (1);
	else
		return (0);
}

bool		Fixed::operator<(Fixed const & rhs)
{
	// std::cout << "Assignation operator called" << std::endl;

	if (this->getRawBits() < rhs.getRawBits())
		return (1);
	else
		return (0);
}

bool		Fixed::operator>=(Fixed const & rhs)
{
	// std::cout << "Assignation operator called" << std::endl;

	if (this->getRawBits() >= rhs.getRawBits())
		return (1);
	else
		return (0);
}

bool		Fixed::operator<=(Fixed const & rhs)
{
	// std::cout << "Assignation operator called" << std::endl;

	if (this->getRawBits() <= rhs.getRawBits())
		return (1);
	else
		return (0);
}

bool		Fixed::operator!=(Fixed const & rhs)
{
	// std::cout << "Assignation operator called" << std::endl;

	if (this->getRawBits() != rhs.getRawBits())
		return (1);
	else
		return (0);
}

Fixed &		Fixed::operator++(void)
{
	this->_raw++;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed	newfix;

	newfix = *this;
	this->_raw++;
	return (newfix);
}

Fixed &		Fixed::operator--(void)
{
	this->_raw--;
	return (*this);
}

Fixed		Fixed::operator--(int)
{
	Fixed	newfix;

	newfix = *this;
	this->_raw++;
	return (newfix);
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

Fixed & 			Fixed::min(Fixed & lhs, Fixed & rhs)
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (rhs);
	return (lhs);
}

Fixed & 			Fixed::max(Fixed & lhs, Fixed & rhs)
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

const Fixed & 	Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (rhs);
	return (lhs);
}

const Fixed & 	Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}
