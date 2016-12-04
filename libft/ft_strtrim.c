/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:46:42 by malorin           #+#    #+#             */
/*   Updated: 2015/12/08 16:25:45 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		y;
	size_t		j;
	char		*str;

	i = 0;
	j = 0;
	y = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return ("");
	while (s[y] == ' ' || s[y] == '\n' || s[y] == '\t')
		y--;
	str = (char*)malloc(sizeof(char) * (y - i + 2));
	if (str == NULL)
		return (NULL);
	while (j < y - i + 1)
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
