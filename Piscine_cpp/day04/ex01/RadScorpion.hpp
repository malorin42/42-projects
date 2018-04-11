/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:07:52 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 23:07:53 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Enemy.hpp"

#ifndef RADSCORPION_HPP
 #define RADSCORPION_HPP

class RadScorpion : public Enemy
{

public:
	RadScorpion();
	RadScorpion(RadScorpion const &);
	~RadScorpion();
	using Enemy::operator=;
};

#endif