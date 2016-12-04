/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:04:39 by malorin           #+#    #+#             */
/*   Updated: 2016/04/05 15:04:41 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int		find_height(char *map)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			c++;
			while (map[i + 1] != '\0' && map[i + 1] == '\n')
				i++;
		}
		i++;
	}
	return (c);
}

static char		*init_map(char **ac)
{
	int		fd;
	char	*line;
	char	*map;
	int		i;

	fd = open(ac[1], O_RDONLY);
	i = 0;
	map = "";
	while (get_next_line(fd, &line) > 0)
	{
		map = ft_strjoin(map, line);
		map = ft_strjoin(map, "\n");
	}
	return (map);
}

static int		find_width(char *map)
{
	int	i;
	int	c;
	int	j;

	i = 0;
	c = 0;
	j = 0;
	while (map[i] != '\0')
	{
		if (ft_isdigit(map[i]) == 1)
		{
			c++;
			j = 0;
			while (j <= 3 && ft_isdigit(map[i]) == 1)
			{
				i++;
				j++;
			}
		}
		i++;
	}
	return (c);
}

void			search_size(char **ac)
{
	t_env	size;
	int		x;
	char	*map;

	size.xmax = 0;
	x = 0;
	map = init_map(ac);
	size.ymax = find_height(map);
	size.xmax = find_width(map) / size.ymax;
	fill_tab(map, size.ymax, size.xmax);
}
