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

	Fixed &		operator=(Fixed const & rhs);

	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	float		toFloat(void) const;
	int			toInt(void) const;

private:
	int					_raw;
	static int const	_bit = 8;	
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif
