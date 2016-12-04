/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:03:36 by malorin           #+#    #+#             */
/*   Updated: 2016/04/05 15:03:39 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	incr_x(int z)
{
	int	x;

	x = 0;
	while (z >= 10)
	{
		z = z % 10;
		x++;
	}
	return (x);
}

void		fill_tab(char *map, int ymax, int xmax)
{
	int		**tab;
	t_env	coord;
	int		i;

	tab = malloc(sizeof(int*) * ymax);
	coord.x = 0;
	coord.y = 0;
	i = -1;
	while (map[++i] != '\0' && coord.y < ymax)
	{
		tab[coord.y] = (int*)malloc(sizeof(int*) * xmax);
		while (map[i] != '\n' && coord.x < xmax)
			if (ft_isdigit(map[i++]) == 1)
			{
				tab[coord.y][coord.x] = ft_atoi(&(map[i - 1]));
				i += incr_x(tab[coord.y][coord.x++]);
			}
		coord.x = 0;
		coord.y++;
	}
	init_mlx(ymax, xmax, &tab);
}
