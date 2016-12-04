/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:08:25 by malorin           #+#    #+#             */
/*   Updated: 2016/01/25 16:24:54 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_line(char *str)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			c++;
		i++;
	}
	c++;
	return (c);
}

int			find_eol(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int			end_line(char **tmp, char **line)
{
	*line = ft_strsub(*tmp, 0, find_eol(*tmp));
	*tmp = ft_strdup(&(*tmp)[find_eol(*tmp) + 1]);
	return (1);
}

int			end_gnl(char **tmp, char **line)
{
	if (tmp && count_line(*tmp) == 2)
	{
		*line = ft_strsub(*tmp, 0, find_eol(*tmp));
		*tmp = ft_strdup(&(*tmp)[find_eol(*tmp) + 1]);
		return (1);
	}
	if (tmp && count_line(*tmp) == 1 && ft_strlen(*tmp) > 0)
	{
		*line = ft_strdup(*tmp);
		*tmp = NULL;
		return (1);
	}
	*tmp = NULL;
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*tmp = NULL;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while (1)
	{
		if (tmp && count_line(tmp) > 2)
			return (end_line(&tmp, line));
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (ret != 0)
		{
			buf[ret] = '\0';
			if (!tmp)
				tmp = "";
			tmp = ft_strjoin(tmp, buf);
		}
		if (ret <= 0)
		{
			if (tmp)
				return (end_gnl(&tmp, line));
			return (0);
		}
	}
}
