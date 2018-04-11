/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:06:29 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 23:06:30 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PLASMARIFLE_HPP
 #define PLASMARIFLE_HPP

#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle(PlasmaRifle const & src);
		PlasmaRifle();
		~PlasmaRifle();
		using AWeapon::operator=;

		void			attack() const;
};
#endif