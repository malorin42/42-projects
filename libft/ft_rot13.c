/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot13.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:55:44 by malorin           #+#    #+#             */
/*   Updated: 2016/01/25 15:11:15 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rot13(char *str)
{
	char	*str2;
	int		i;

	str2 = str;
	i = 0;
	while (str2[i])
	{
		if ((str2[i] >= 'A' && str2[i] <= 'M') ||
				(str2[i] >= 'a' && str2[i] <= 'm'))
			str2[i] += 13;
		else if (str2[i] >= 'N' && str2[i] <= 'Z')
			str2[i] = 'A' + str2[i] + 12 - 'Z';
		else if (str2[i] >= 'n' && str2[i] <= 'z')
			str2[i] = 'a' + str2[i] + 12 - 'z';
		i++;
	}
	return (str2);
}
