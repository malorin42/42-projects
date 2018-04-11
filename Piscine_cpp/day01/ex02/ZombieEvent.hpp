/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:33:30 by malorin           #+#    #+#             */
/*   Updated: 2018/03/27 17:33:31 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H

#include <iostream>
#include "Zombie.hpp"
#include <string>

class ZombieEvent {

public:

	void		setZombieType(std::string newtype);
	Zombie* 	newZombie(std::string name);
	Zombie*		randomChump(void);

	std::string	ztype;
	
	ZombieEvent();
	~ZombieEvent();
};

#endif