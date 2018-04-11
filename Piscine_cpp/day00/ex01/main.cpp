/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:12:16 by malorin           #+#    #+#             */
/*   Updated: 2018/03/26 16:12:18 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.h"

void	search_contact(Contact *tab)
{
	int	i = 0;
	std::string	num;
	int index;

	std::cout << "    Index|First Name| Last Name| Nick Name" << std::endl;
	while (tab[i].set == 1)
	{
		tab[i].display_contact(i + 1);
		i++;
	}
	std::cout << "Enter the index of a contact : ";
	std::getline(std::cin, num);
	if (num.size() == 1 && num[0] > 48 && num[0] < 57)
	{
		index = num[0] - 49;
		if (tab[index].set == 1)
			tab[index].display_full_contact();
		else
			std::cout << "Error : This is not a correct Index." << std::endl;
	}
	else
		std::cout << "Error : This is not a correct Index." << std::endl;
}

void new_contact(Contact *tab, int nb_contact)
{
	if (tab[7].set == 1)
	{
		std::cout << "Error : The Dark List is Full ." << std::endl;
		return ;
	}
	tab[nb_contact].add_new();
}

int		main(void)
{
	std::string		buff;
	Contact 		tab[8];
	int				nb_contact = 0;

	while (1)
	{
		std::cout << "Choose an action : ";
		std::getline(std::cin, buff);

		if (buff == "EXIT")
			return (0);
		else if (buff == "ADD")
		{
			new_contact(tab, nb_contact);
			nb_contact++;
		}
		else if (buff == "SEARCH")
			search_contact(tab);
		else
			std::cout << "Invalid action ! Choose between EXIT, ADD or SEARCH ..." << std::endl;
	}
}