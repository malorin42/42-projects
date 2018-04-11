/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:36:06 by malorin           #+#    #+#             */
/*   Updated: 2018/03/28 16:36:07 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"
#include "Brain.hpp"

Human::Human(){}

Human::~Human(){}

Brain const & 		Human::getBrain()
{
	return (myBrain);
}

std::string			Human::identify() const
{
	return (myBrain.identify());
}