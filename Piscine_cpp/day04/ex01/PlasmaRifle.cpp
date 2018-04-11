/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:06:34 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 23:06:35 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "PlasmaRifle.hpp"

class AWeapon;

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) : AWeapon(src){

}

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21){

}

PlasmaRifle::~PlasmaRifle() {

}

void			PlasmaRifle::attack() const{
	std::cout<< "* piouuu piouuu piouuu *" << std::endl;
}
