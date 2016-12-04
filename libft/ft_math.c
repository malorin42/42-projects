/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:22:06 by malorin           #+#    #+#             */
/*   Updated: 2016/01/18 18:01:33 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_math(int number, unsigned int addnum, char sign)
{
	if (sign == '-')
		number = number - addnum;
	else if (sign == '+')
		number = number + addnum;
	else if (sign == '*')
		number = number * addnum;
	else if (sign == '/')
		number = number / addnum;
	else if (sign == '%')
		number = number % addnum;
	return (number);
}
