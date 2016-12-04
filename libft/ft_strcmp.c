/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:09:33 by malorin           #+#    #+#             */
/*   Updated: 2016/01/25 15:13:38 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	size_t len;

	len = ft_strlen(str1);
	if (len < ft_strlen(str2))
		len = ft_strlen(str2);
	return (ft_strncmp(str1, str2, len));
}
