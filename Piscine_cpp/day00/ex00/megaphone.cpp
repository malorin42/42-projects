/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:00:43 by malorin           #+#    #+#             */
/*   Updated: 2018/03/26 15:00:48 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

int		main(int argc, char *argv[])
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int						i = 1;
		std::string::size_type	j = 0;
 		std::locale loc;
		std::string str;

		while (i < argc)
		{
			str = argv[i];
			while (j < str.length())
			{
				std::cout << std::toupper(str[j], loc);
				j++;
			}
			j = 0;
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
