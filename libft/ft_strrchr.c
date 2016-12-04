/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:07:54 by malorin           #+#    #+#             */
/*   Updated: 2016/01/25 15:21:40 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	char	*str2;

	str2 = (char*)str;
	while (*str2)
		str2++;
	if (c == 0)
		return (str2);
	str2--;
	while (*str2)
	{
		if (*str2 == c)
			return (str2);
		str2--;
	}
	return (NULL);
}
