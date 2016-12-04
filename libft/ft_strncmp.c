/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:10:11 by malorin           #+#    #+#             */
/*   Updated: 2016/01/25 15:20:29 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!str1[i] && !str2[i]) || n == 0)
		return (0);
	while (i < (n - 1) && (str1[i] || str2[i]) && str1[i] == str2[i])
		i++;
	return ((const unsigned char)str1[i] - (const unsigned char)str2[i]);
}
