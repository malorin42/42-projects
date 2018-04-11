/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:00:35 by malorin           #+#    #+#             */
/*   Updated: 2018/03/29 16:00:37 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(int const i);
	Fixed(float const f);
	~Fixed(void);

	bool		operator<(Fixed const & rhs);
	bool		operator>(Fixed const & rhs);
	bool		operator<=(Fixed const & rhs);
	bool		operator>=(Fixed const & rhs);
	bool		operator!=(Fixed const & rhs);
	bool		operator==(Fixed const & rhs);
	Fixed &		operator=(Fixed const & rhs);
	Fixed		operator+(Fixed const & rhs);
	Fixed		operator-(Fixed const & rhs);
	Fixed		operator*(Fixed const & rhs);
	Fixed		operator/(Fixed const & rhs);
	Fixed &		operator++(void);
	Fixed		operator++(int);
	Fixed &		operator--(void);
	Fixed		operator--(int);

	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	float		toFloat(void) const;
	int			toInt(void) const;
	static Fixed & 			min(Fixed & lhs, Fixed & rhs);
	static Fixed & 			max(Fixed & lhs, Fixed & rhs);
	static const Fixed & 	min(Fixed const & lhs, Fixed const & rhs);
	static const Fixed & 	max(Fixed const & lhs, Fixed const & rhs);

private:
	int					_raw;
	static int const	_bit = 8;	
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif
