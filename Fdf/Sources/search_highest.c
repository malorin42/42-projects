/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_highest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 16:01:41 by malorin           #+#    #+#             */
/*   Updated: 2016/06/24 16:01:52 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		search_highest(t_mlx *mlx)
{
	int	i;
	int	j;
	int	zmax;

	i = 0;
	j = 0;
	zmax = 0;
	while (i < mlx->ymax)
	{
		while (i <= mlx->ymax && j <= mlx->xmax)
		{
			if (zmax < mlx->tab[i][j])
				zmax = mlx->tab[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (zmax);
}
