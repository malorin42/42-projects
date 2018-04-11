/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:07:27 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 23:07:28 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Enemy.hpp"


#ifndef SUPERMUTANT_HPP
 #define SUPERMUTANT_HPP

class SuperMutant : public Enemy
{

public:
	SuperMutant();
	SuperMutant(SuperMutant const &);
	~SuperMutant();
	using Enemy::operator=;
	void 		takeDamage(int);	
};

#endif