/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:08:56 by malorin           #+#    #+#             */
/*   Updated: 2016/01/25 15:21:18 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(char *str, const char *substr, size_t len)
{
	size_t	len2;

	if (!*substr)
		return ((char*)str);
	len2 = ft_strlen(substr);
	while (*str && len-- >= len2)
	{
		if (*str == *substr && ft_memcmp(str, substr, len2) == 0)
			return ((char*)str);
		str++;
	}
	return (NULL);
}
