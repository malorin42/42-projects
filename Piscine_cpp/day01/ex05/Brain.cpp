/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:35:46 by malorin           #+#    #+#             */
/*   Updated: 2018/03/28 16:35:47 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain(void) {}

Brain::~Brain(void) {}

std::string		Brain::identify(void) const
{
	std::stringstream	str;

	str << this;
	return (str.str());
}
