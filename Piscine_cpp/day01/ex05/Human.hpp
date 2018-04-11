/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:36:02 by malorin           #+#    #+#             */
/*   Updated: 2018/03/28 16:36:02 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"

class Human
{
public:
	Human();
	~Human();
	
	Brain const &		getBrain(void);
	std::string			identify(void) const;

	Brain const			myBrain;

};

#endif

