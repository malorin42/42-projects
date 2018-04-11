/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:06:46 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 23:06:47 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
 #define POWERFIST_HPP

#include <iostream>
#include "AWeapon.hpp"

class PowerFist  : public AWeapon
{
	public:
		PowerFist(PowerFist const & src);
		PowerFist();
		~PowerFist();
		using AWeapon::operator=;

		void			attack() const;
};
#endif