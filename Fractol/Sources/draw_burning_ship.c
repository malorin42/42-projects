/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:50:30 by malorin           #+#    #+#             */
/*   Updated: 2016/09/05 16:50:34 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static void		search_point(t_mlx *mlx, int x, int y)
{
	t_coo	z;
	int		i;

	z.xd = x;
	z.yd = y;
	i = 0;
	z.ymax = mlx->height;
	z.xmax = mlx->width;
	mlx->c_x = 1.5 * (z.xd - z.xmax / 2) / (0.5 * mlx->zoom
		* mlx->width) + mlx->mx;
	mlx->c_y = (z.yd - z.ymax / 2) / (0.5 * mlx->zoom
		* mlx->height) + mlx->my;
	z.re = 0;
	z.im = 0;
	while (((z.re * z.re) + (z.im * z.im)) < 4 && i < mlx->imax)
	{
		z.tmp = z.re;
		z.re = (z.re * z.re) - (z.im * z.im) + mlx->c_x;
		z.im = fabs(2 * z.im * z.tmp) + mlx->c_y;
		i++;
	}
	choose_color(mlx, x, y, i);
}

void			draw_burning_ship(t_mlx *mlx)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < mlx->height)
	{
		while (x < mlx->width)
		{
			search_point(mlx, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
