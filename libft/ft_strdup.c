/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:00:44 by malorin           #+#    #+#             */
/*   Updated: 2016/01/25 15:19:29 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str2;

	str2 = ft_strnew(ft_strlen(str));
	if (str2 == NULL)
		return (NULL);
	ft_strcpy(str2, str);
	return (str2);
}
