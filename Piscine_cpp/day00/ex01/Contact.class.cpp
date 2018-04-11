/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:59:31 by malorin           #+#    #+#             */
/*   Updated: 2018/03/26 16:59:35 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.class.h"

Contact::Contact() : set(0) {}

Contact::~Contact(void) {}

void	Contact::add_new(void)
{
	set = 1;
	std::cout << "First Name : ";
	std::getline(std::cin , first_name);	
	std::cout << "Last Name : ";
	std::getline(std::cin , last_name);	
	std::cout << "Nickname : ";
	std::getline(std::cin , nickname);
	std::cout << "Login : ";
	std::getline(std::cin , login);
	std::cout << "Postal Address : ";
	std::getline(std::cin , postal_address);
	std::cout << "Email Address : ";
	std::getline(std::cin , email);
	std::cout << "Phone Number : ";
	std::getline(std::cin , phone);
	std::cout << "Birthday Date : ";
	std::getline(std::cin , birthday);
	std::cout << "Favorite Meal : ";
	std::getline(std::cin , favorite_meal);
	std::cout << "Underwear Color : ";
	std::getline(std::cin , underwear_color);
	std::cout << "Darkest Secret : ";
	std::getline(std::cin , darkest_secret);
}

void 	Contact::display_full_contact(void)
{
	std::cout << "First Name : " << first_name << std::endl;

	std::cout << "Last Name : " << last_name << std::endl;

	std::cout << "Nickname : " << nickname << std::endl;

	std::cout << "Login : " << login << std::endl;

	std::cout << "Postal Address : " << postal_address << std::endl;

	std::cout << "Email Address : " << email << std::endl;

	std::cout << "Phone Number : " << phone << std::endl;

	std::cout << "Birthday Date : " << birthday << std::endl;

	std::cout << "Favorite Meal : " << favorite_meal << std::endl;

	std::cout << "Underwear Color : " << underwear_color << std::endl;

	std::cout << "Darkest Secret : " << darkest_secret << std::endl;
}

void	Contact::show_truncated(std::string str)
{
	char	buffer[11];

	std::cout << std::setfill (' ') << std::setw (10);
	if (str.size() > 10)
	{
		str.copy(buffer, 9, 0);
		buffer[9]='.';
		buffer[10]='\0';
		std::cout << buffer;
	}
	else
		std::cout << str;
}

void	Contact::display_contact(int index)
{
	if (set == 0)
	{
		std::cout << std::setfill (' ') << std::setw (11);
		std::cout << "|";
		std::cout << std::setfill (' ') << std::setw (11);
		std::cout << "|";
		std::cout << std::setfill (' ') << std::setw (11);
		std::cout << std::endl;
		return ;
	}
	std::cout << std::setw(9) << index << "|";
	show_truncated(first_name);
	std::cout << "|";
	show_truncated(last_name);
	std::cout << "|";
	show_truncated(nickname);
	std::cout << std::endl;
}