/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ramps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 07:14:11 by malorin           #+#    #+#             */
/*   Updated: 2016/04/06 07:14:15 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_ramps_sup1(t_mlx *mlx, t_env coo, int z1, int z2)
{
	int	x;
	int	y;

	coo.dp = 2 * coo.dx - coo.dy;
	coo.delta_e = 2 * coo.dx;
	coo.delta_ne = 2 * (coo.dx - coo.dy);
	x = coo.x0;
	y = coo.y0;
	mlx_pixel_put(mlx->init, mlx->win, x, y, color(mlx, z1, z2));
	while (y < coo.y1)
	{
		if (coo.dp <= 0)
		{
			coo.dp = coo.dp + coo.delta_e;
			y++;
		}
		else
		{
			coo.dp = coo.dp + coo.delta_ne;
			x++;
			y++;
		}
		mlx_pixel_put(mlx->init, mlx->win, x, y, color(mlx, z1, z2));
	}
}

void	draw_ramps_inf2(t_mlx *mlx, t_env coo, int z1, int z2)
{
	int	x;
	int	y;

	coo.dp = 2 * coo.dy - coo.dx;
	coo.delta_e = 2 * coo.dy;
	coo.delta_ne = 2 * (coo.dy - coo.dx);
	x = coo.x0;
	y = coo.y0;
	mlx_pixel_put(mlx->init, mlx->win, x, y, color(mlx, z1, z2));
	while (x < coo.x1)
	{
		if (coo.dp <= 0)
		{
			coo.dp = coo.dp + coo.delta_e;
			x++;
		}
		else
		{
			coo.dp = coo.dp + coo.delta_ne;
			x++;
			y--;
		}
		mlx_pixel_put(mlx->init, mlx->win, x, y, color(mlx, z1, z2));
	}
}

void	draw_ramps_sup2(t_mlx *mlx, t_env coo, int z1, int z2)
{
	int	x;
	int	y;

	coo.dp = 2 * coo.dx - coo.dy;
	coo.delta_e = 2 * coo.dx;
	coo.delta_ne = 2 * (coo.dx - coo.dy);
	x = coo.x0;
	y = coo.y0;
	mlx_pixel_put(mlx->init, mlx->win, x, y, color(mlx, z1, z2));
	while (y > coo.y1)
	{
		if (coo.dp <= 0)
		{
			coo.dp = coo.dp + coo.delta_e;
			y--;
		}
		else
		{
			coo.dp = coo.dp + coo.delta_ne;
			x++;
			y--;
		}
		mlx_pixel_put(mlx->init, mlx->win, x, y, color(mlx, z1, z2));
	}
}

void	draw_ramps_inf1(t_mlx *mlx, t_env coo, int z1, int z2)
{
	int	x;
	int	y;

	coo.dp = 2 * coo.dy - coo.dx;
	coo.delta_e = 2 * coo.dy;
	coo.delta_ne = 2 * (coo.dy - coo.dx);
	x = coo.x0;
	y = coo.y0;
	mlx_pixel_put(mlx->init, mlx->win, x, y, color(mlx, z1, z2));
	while (x < coo.x1)
	{
		if (coo.dp <= 0)
		{
			coo.dp = coo.dp + coo.delta_e;
			x++;
		}
		else
		{
			coo.dp = coo.dp + coo.delta_ne;
			x++;
			y++;
		}
		mlx_pixel_put(mlx->init, mlx->win, x, y, color(mlx, z1, z2));
	}
}
