/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:00:53 by malorin           #+#    #+#             */
/*   Updated: 2018/03/29 16:00:55 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( 5 );
	Fixed const c(Fixed(5.05f) * Fixed(2));
	Fixed const d( b );
	Fixed e;
	Fixed const f( Fixed( 5.05f ) * Fixed( 2 ) );
	a = Fixed( 1 );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << c << " = " <<  a - c << std::endl;
	std::cout << a << " * " << a << " = " << a * a << std::endl;
	std::cout << a << " / " << d << " = " << a / d << std::endl;

	if (a < b)
		std::cout << "a plus petit que b" << std::endl;
	else
		std::cout << "b plus petit que a" << std::endl;
	if (a > b)
		std::cout << "a plus grand que b" << std::endl;
	else
		std::cout << "b plus grand que a" << std::endl;
	if (a <= b)
		std::cout << "a plus petit ou egale à b" << std::endl;
	else
		std::cout << "b plus petit ou egale à a" << std::endl;
	if (a >= b)
		std::cout << "a plus grand ou egale à b" << std::endl;
	else
		std::cout << "b plus grand ou egale à a" << std::endl;
	if (a == b)
		std::cout << "a est egale à b" << std::endl;
	else
		std::cout << "a n'est pas egale à b" << std::endl;

	std::cout << "++e = " << ++e << std::endl;
	std::cout << "e is = " << e << std::endl;
	std::cout << "e++ = " << e++ << std::endl;
	std::cout << "e is = " << e << std::endl;
	std::cout << "--e = " << --e << std::endl;
	std::cout << "e-- = " << e-- << std::endl;
	std::cout << "valeur max entre e : " << e << " et f : " << f << " ---> " << Fixed::max( e, f ) << std::endl;
	std::cout << "valeur min entre e : " << e << " et f : " << f << " ---> " << Fixed::min( e, f ) << std::endl;
	return 0;
}