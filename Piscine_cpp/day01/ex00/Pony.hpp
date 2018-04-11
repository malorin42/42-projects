/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:31:20 by malorin           #+#    #+#             */
/*   Updated: 2018/03/27 14:31:21 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <string>
#include <iostream>

class Pony
{

public:

	 Pony(void);
	~Pony(void);

	void	pony_run(void);
	void	pony_eat(void);
	void	pony_sleep(void);

	int				stamina;
	int				weight;	
	std::string		name;
	std::string		owner;
};

#endif
