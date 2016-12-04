/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 12:19:12 by malorin           #+#    #+#             */
/*   Updated: 2016/07/10 12:19:14 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void		choose_map(t_mlx *mlx, int keycode)
{
	if (keycode == 18 && mlx->map == 0)
	{
		mlx->map = 1;
		struct_init(mlx);
	}
	if (keycode == 19 && mlx->map == 0)
	{
		mlx->map = 2;
		struct_init(mlx);
	}
	if (keycode == 20 && mlx->map == 0)
	{
		mlx->map = 3;
		struct_init(mlx);
	}
}

static void	search_c(t_mlx mlx, int x, int y)
{
	t_coo	z;
	int		i;

	z.xd = x;
	z.yd = y;
	z.ymax = mlx.height;
	z.xmax = mlx.width;
	z.re = 1.5 * (z.xd - z.xmax / 2) / (0.5 * mlx.zoom
		* mlx.width) + mlx.mx;
	z.im = (z.yd - z.ymax / 2) / (0.5 * mlx.zoom
		* mlx.height) + mlx.my;
	i = 0;
	while (((z.re * z.re) + (z.im * z.im)) < 4 && i < mlx.imax)
	{
		z.tmp = (z.re * z.re) + (z.im * z.im);
		z.tmp = z.re;
		z.re = (z.re * z.re) - (z.im * z.im) - mlx.c_x;
		z.im = (2 * z.im * z.tmp) + mlx.c_y;
		i++;
	}
	choose_color(&mlx, x, y, i);
}

void		draw_julia(t_mlx *mlx)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < mlx->height)
	{
		while (x < mlx->width)
		{
			search_c(*mlx, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
