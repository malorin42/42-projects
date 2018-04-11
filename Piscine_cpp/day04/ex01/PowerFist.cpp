/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:06:51 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 23:06:51 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "PowerFist.hpp"

class AWeapon;

PowerFist::PowerFist(PowerFist const & src) : AWeapon(src){

}

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50){

}

PowerFist::~PowerFist() {

}

void			PowerFist::attack() const{
	std::cout<< "* pschhh... SBAM! *" << std::endl;
}