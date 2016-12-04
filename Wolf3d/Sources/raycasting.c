/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 15:00:46 by malorin           #+#    #+#             */
/*   Updated: 2016/09/07 15:00:48 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void	init_raycasting(t_mlx *mlx, int x)
{
	mlx->camera_x = 2 * x / (double)mlx->width - 1;
	mlx->raypos_x = mlx->pos_x;
	mlx->raypos_y = mlx->pos_y;
	mlx->raydir_x = mlx->dir_x + mlx->plane_x * mlx->camera_x;
	mlx->raydir_y = mlx->dir_y + mlx->plane_y * mlx->camera_x;
	mlx->map_x = (int)mlx->raypos_x;
	mlx->map_y = (int)mlx->raypos_y;
	mlx->deltadist_x = sqrt(1 + (mlx->raydir_y * mlx->raydir_y) /
	(mlx->raydir_x * mlx->raydir_x));
	mlx->deltadist_y = sqrt(1 + (mlx->raydir_x * mlx->raydir_x) /
	(mlx->raydir_y * mlx->raydir_y));
	mlx->hit = 0;
}

static void	search_side(t_mlx *mlx)
{
	if (mlx->raydir_x < 0)
	{
		mlx->step_x = -1;
		mlx->sidedist_x = (mlx->raypos_x - mlx->map_x) * mlx->deltadist_x;
	}
	else
	{
		mlx->step_x = 1;
		mlx->sidedist_x = (mlx->map_x + 1.0 - mlx->raypos_x) * mlx->deltadist_x;
	}
	if (mlx->raydir_y < 0)
	{
		mlx->step_y = -1;
		mlx->sidedist_y = (mlx->raypos_y - mlx->map_y) * mlx->deltadist_y;
	}
	else
	{
		mlx->step_y = 1;
		mlx->sidedist_y = (mlx->map_y + 1.0 - mlx->raypos_y) * mlx->deltadist_y;
	}
}

static void	check_obj(t_mlx *mlx)
{
	if ((mlx->obj == 10 && mlx->blue_d.open == 0) ||
		(mlx->obj == 11 && mlx->green_d.open == 0) ||
		(mlx->obj == 12 && mlx->red_d.open == 0) ||
		(mlx->obj == 13 && mlx->pink_d.open == 0))
		mlx->obj = 0;
	if (mlx->obj > 0)
		mlx->hit = 1;
}

static void	dda_system(t_mlx *mlx)
{
	while (mlx->hit == 0)
	{
		if (mlx->sidedist_x < mlx->sidedist_y)
		{
			mlx->sidedist_x += mlx->deltadist_x;
			mlx->map_x += mlx->step_x;
			mlx->side = 0;
		}
		else
		{
			mlx->sidedist_y += mlx->deltadist_y;
			mlx->map_y += mlx->step_y;
			mlx->side = 1;
		}
		mlx->obj = map(mlx->map_x, mlx->map_y);
		check_obj(mlx);
	}
	if (mlx->side == 0)
		mlx->perpwalldist = (mlx->map_x - mlx->raypos_x +
		(1 - mlx->step_x) / 2) / mlx->raydir_x;
	else
		mlx->perpwalldist = (mlx->map_y - mlx->raypos_y +
		(1 - mlx->step_y) / 2) / mlx->raydir_y;
}

void		start_raycasting(t_mlx mlx)
{
	int		x;

	x = 0;
	while (x < mlx.width)
	{
		init_raycasting(&mlx, x);
		search_side(&mlx);
		mlx.obj = 0;
		dda_system(&mlx);
		watch_pos(&mlx);
		mlx.l_h = (int)(mlx.height / mlx.perpwalldist);
		mlx.draw_start = -mlx.l_h / 2 + mlx.height / 2;
		if (mlx.draw_start < 0)
			mlx.draw_start = 0;
		mlx.draw_end = mlx.l_h / 2 + mlx.height / 2;
		if (mlx.draw_end >= mlx.height)
			mlx.draw_end = mlx.height - 1;
		draw_wolf3d(mlx, x);
		x++;
	}
}
