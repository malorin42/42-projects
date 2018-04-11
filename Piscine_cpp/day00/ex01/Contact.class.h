/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:30:30 by malorin           #+#    #+#             */
/*   Updated: 2018/03/26 16:30:32 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact {

public:

	void			add_new(void);
	void			display_contact(int index);
	void			show_truncated(std::string str);
	void 			display_full_contact(void);

	std::string		first_name;
	std::string		last_name;
	std::string		nickname;
	std::string		login;
	std::string		postal_address;
	std::string		email;
	std::string		phone;
	std::string		birthday;
	std::string		favorite_meal;
	std::string		underwear_color;
	std::string		darkest_secret;
	int				set;

	Contact();
	~Contact(void);
};

#endif
