/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ramps_re.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 19:09:22 by malorin           #+#    #+#             */
/*   Updated: 2016/04/14 19:09:26 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	reverse_pos(t_env *coo)
{
	int	tmp_x0;
	int	tmp_x1;
	int	tmp_y0;
	int	tmp_y1;

	tmp_x0 = coo->x0;
	tmp_x1 = coo->x1;
	tmp_y0 = coo->y0;
	tmp_y1 = coo->y1;
	coo->x0 = tmp_x1;
	coo->x1 = tmp_x0;
	coo->y0 = tmp_y1;
	coo->y1 = tmp_y0;
}

void		draw_ramps_sup1_re(t_mlx *mlx, t_env coo, int z1, int z2)
{
	int	x;
	int	y;

	reverse_pos(&coo);
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

void		draw_ramps_inf2_re(t_mlx *mlx, t_env coo, int z1, int z2)
{
	int	x;
	int	y;

	reverse_pos(&coo);
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

void		draw_ramps_sup2_re(t_mlx *mlx, t_env coo, int z1, int z2)
{
	int	x;
	int	y;

	reverse_pos(&coo);
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

void		draw_ramps_inf1_re(t_mlx *mlx, t_env coo, int z1, int z2)
{
	int	x;
	int	y;

	reverse_pos(&coo);
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
