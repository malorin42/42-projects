/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:06:55 by malorin           #+#    #+#             */
/*   Updated: 2016/01/25 15:18:13 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int c)
{
	char	*str2;

	str2 = (char*)str;
	while (*str2)
	{
		if (*str2 == c)
			return (str2);
		str2++;
	}
	if (c == 0)
		return (str2);
	return (NULL);
}
