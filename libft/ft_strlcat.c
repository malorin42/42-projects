/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:05:53 by malorin           #+#    #+#             */
/*   Updated: 2016/01/25 15:14:51 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *dest, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (dest[i] == 0)
			return (i);
		i++;
	}
	return (size);
}

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t n;
	size_t i;
	size_t ret;

	i = 0;
	if (size <= (ft_strnlen(dest, size) + 1))
		return (ft_strnlen(dest, size) + ft_strlen(src));
	n = ft_strlen(dest);
	ret = n + ft_strlen(src);
	while (src[i])
	{
		if (n < size - 1)
		{
			dest[n] = src[i];
			n++;
		}
		i++;
	}
	dest[n] = 0;
	return (ret);
}
