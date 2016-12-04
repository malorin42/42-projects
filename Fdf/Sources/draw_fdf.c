/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:01:10 by malorin           #+#    #+#             */
/*   Updated: 2016/04/05 15:01:12 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		draw_line_left(t_mlx *mlx, t_env coo, int z1, int z2)
{
	int		i;

	i = coo.xp - mlx->t;
	coo.x0 = coo.xp;
	coo.x1 = coo.xp - mlx->t;
	coo.y0 = coo.yp - z1;
	coo.y1 = coo.yp + mlx->t - z2;
	coo.dx = (coo.x0 - coo.x1) < 0 ? -(coo.x0 - coo.x1) : (coo.x0 - coo.x1);
	coo.dy = (coo.y0 - coo.y1) < 0 ? -(coo.y0 - coo.y1) : (coo.y0 - coo.y1);
	if (coo.y0 >= coo.y1)
	{
		if (coo.dx >= coo.dy)
			draw_ramps_inf2_re(mlx, coo, z1, z2);
		else
			draw_ramps_sup2_re(mlx, coo, z1, z2);
	}
	if (coo.y0 < coo.y1)
	{
		if (coo.dx >= coo.dy)
			draw_ramps_inf1_re(mlx, coo, z1, z2);
		else
			draw_ramps_sup1_re(mlx, coo, z1, z2);
	}
}

static void		draw_line_right(t_mlx *mlx, t_env coo, int z1, int z2)
{
	coo.x0 = coo.xp;
	coo.x1 = coo.xp + mlx->t;
	coo.y0 = coo.yp - z1;
	coo.y1 = coo.yp + mlx->t - z2;
	coo.dx = (coo.x0 - coo.x1) < 0 ? -(coo.x0 - coo.x1) : (coo.x0 - coo.x1);
	coo.dy = (coo.y0 - coo.y1) < 0 ? -(coo.y0 - coo.y1) : (coo.y0 - coo.y1);
	if (coo.y0 >= coo.y1)
	{
		if (coo.dx >= coo.dy)
			draw_ramps_inf2(mlx, coo, z1, z2);
		else
			draw_ramps_sup2(mlx, coo, z1, z2);
	}
	if (coo.y0 < coo.y1)
	{
		if (coo.dx >= coo.dy)
			draw_ramps_inf1(mlx, coo, z1, z2);
		else
			draw_ramps_sup1(mlx, coo, z1, z2);
	}
}

static void		draw_ymax_line(t_mlx *mlx, t_env coo)
{
	while (coo.x < mlx->xmax - 1)
	{
		draw_line_right(mlx, coo, mlx->tab[mlx->ymax - 1][coo.x],
			mlx->tab[mlx->ymax - 1][coo.x + 1]);
		coo.x++;
		coo.xp = coo.xp + mlx->t;
		coo.yp = coo.yp + mlx->t;
	}
}

static t_env	init_coo(t_mlx *mlx)
{
	t_env	coo;

	coo = (t_env){.y = 0, .x = 0, .ori_x = mlx->width / 2 + mlx->ori_x,
			.ori_y = mlx->height / 4 + mlx->ori_y, .xmax = mlx->xmax,
			.ymax = mlx->ymax};
	coo.yp = coo.ori_y;
	coo.xp = coo.ori_x;
	return (coo);
}

void			draw_fdf(t_mlx *mlx)
{
	t_env	coo;

	coo = init_coo(mlx);
	while (coo.y < mlx->ymax - 1)
	{
		while (coo.x < mlx->xmax - 1)
		{
			draw_line_right(mlx, coo, mlx->tab[coo.y][coo.x],
				mlx->tab[coo.y][coo.x + 1]);
			draw_line_left(mlx, coo, mlx->tab[coo.y][coo.x],
				mlx->tab[coo.y + 1][coo.x++]);
			coo.xp += mlx->t;
			coo.yp += mlx->t;
		}
		draw_line_left(mlx, coo, mlx->tab[coo.y][mlx->xmax],
			mlx->tab[++coo.y][mlx->xmax]);
		coo.x = 0;
		coo.ori_x = coo.ori_x - mlx->t;
		coo.xp = coo.ori_x;
		coo.ori_y = coo.ori_y + mlx->t;
		coo.yp = coo.ori_y;
	}
	draw_ymax_line(mlx, coo);
}
