/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 16:11:54 by malorin           #+#    #+#             */
/*   Updated: 2016/06/24 16:11:57 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	color_rgb(int z)
{
	if (z <= 10)
		return (255 + (0 * 256) + (0 * 256 * 256));
	if (z >= 11 && z <= 20)
		return (0 + (255 * 256) + (0 * 256 * 256));
	if (z >= 21)
		return (0 + (0 * 256) + (255 * 256 * 256));
	return (0);
}

static int	color_terre(int z, int zmax)
{
	int	avg;

	avg = z * 100 / zmax;
	if (avg <= 10)
		return (34 + (66 * 256) + (124 * 256 * 256));
	if (avg > 10 && avg <= 40)
		return (127 + (221 * 256) + (76 * 256 * 256));
	if (avg > 40 && avg <= 60)
		return (0 + (86 * 256) + (27 * 256 * 256));
	if (avg > 60 && avg <= 80)
		return (78 + (61 * 256) + (40 * 256 * 256));
	if (avg > 80)
		return (186 + (186 * 256) + (186 * 256 * 256));
	return (0);
}

static int	color_marin(int z, int zmax)
{
	int	avg;

	avg = z * 100 / zmax;
	if (avg <= 10)
		return (47 + (27 * 256) + (12 * 256 * 256));
	if (avg > 10 && avg <= 20)
		return (70 + (46 * 256) + (1 * 256 * 256));
	if (avg > 20 && avg <= 60)
		return (173 + (79 * 256) + (9 * 256 * 256));
	if (avg > 60 && avg <= 90)
		return (223 + (109 * 256) + (20 * 256 * 256));
	if (avg > 90)
		return (187 + (174 * 256) + (152 * 256 * 256));
	return (0);
}

static int	color_moon(int z, int zmax)
{
	int	avg;

	avg = z * 100 / zmax;
	if (avg <= 33)
		return (127 + (127 * 256) + (127 * 256 * 256));
	if (avg > 33 && avg <= 66)
		return (132 + (132 * 256) + (132 * 256 * 256));
	if (avg > 66)
		return (206 + (206 * 256) + (206 * 256 * 256));
	return (0);
}

int			color(t_mlx *mlx, int z1, int z2)
{
	int	z;

	if (z1 < z2)
		z = z1;
	else
		z = z2;
	if (mlx->color == 1)
		return (color_rgb(z));
	if (mlx->color == 2)
		return (color_terre(z, mlx->zmax));
	if (mlx->color == 3)
		return (color_moon(z, mlx->zmax));
	if (mlx->color == 4)
		return (color_marin(z, mlx->zmax));
	return (0);
}
