/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:42:53 by malorin           #+#    #+#             */
/*   Updated: 2015/12/14 15:49:54 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_incr(char const *s, char c)
{
	unsigned int	i;
	int				cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cnt++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (cnt);
}

static char		*ft_strndup(const char *s, size_t n)
{
	char *str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		y;
	size_t		j;
	char		**str;

	i = 0;
	y = 0;
	str = (char **)malloc(sizeof(char *) * (ft_incr(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > j)
		{
			str[y] = ft_strndup(s + j, i - j);
			y++;
		}
	}
	str[y] = NULL;
	return (str);
}
