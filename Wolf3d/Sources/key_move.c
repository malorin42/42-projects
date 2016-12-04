/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 18:10:34 by malorin           #+#    #+#             */
/*   Updated: 2016/10/20 20:12:54 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void	key_w(t_mlx *mlx)
{
	init_time(mlx);
	if (map((int)(mlx->pos_x + mlx->dir_x * mlx->movespeed),
				(int)(mlx->pos_y)) == 0 || map((int)(mlx->pos_x + mlx->dir_x *
					mlx->movespeed), (int)(mlx->pos_y)) >= 10)
		key_w_t(mlx);
	if (map((int)(mlx->pos_x), (int)(mlx->pos_y + mlx->dir_y *
	mlx->movespeed)) == 0 || map((int)(mlx->pos_x), (int)(mlx->pos_y +
	mlx->dir_y * mlx->movespeed)) >= 10)
	{
		if (map((int)(mlx->pos_x),
					(int)(mlx->pos_y + mlx->dir_y * mlx->movespeed)) >= 10)
		{
			if (check_door(mlx, mlx->pos_x,
						mlx->pos_y + mlx->dir_y * mlx->movespeed) == 0)
				mlx->pos_y += mlx->dir_y * mlx->movespeed;
		}
		else
			mlx->pos_y += mlx->dir_y * mlx->movespeed;
	}
}

static void	key_s(t_mlx *mlx)
{
	init_time(mlx);
	if (map((int)(mlx->pos_x - mlx->dir_x * mlx->movespeed),
		(int)(mlx->pos_y)) == 0 || map((int)(mlx->pos_x - mlx->dir_x *
		mlx->movespeed), (int)(mlx->pos_y)) >= 10)
		key_s_t(mlx);
	if (map((int)(mlx->pos_x), (int)(mlx->pos_y - mlx->dir_y *
		mlx->movespeed)) == 0 || map((int)(mlx->pos_x),
		(int)(mlx->pos_y - mlx->dir_y * mlx->movespeed)) == 10)
	{
		if (map((int)(mlx->pos_x),
		(int)(mlx->pos_y - mlx->dir_y * mlx->movespeed)) >= 10)
		{
			if (check_door(mlx, mlx->pos_x,
				mlx->pos_y - mlx->dir_y * mlx->movespeed))
				mlx->pos_y -= mlx->dir_y * mlx->movespeed;
		}
		else
			mlx->pos_y -= mlx->dir_y * mlx->movespeed;
	}
}

static void	key_straf(int keycode, t_mlx *mlx)
{
	if (keycode == 2)
	{
		init_time(mlx);
		if (map((int)(mlx->pos_x + mlx->plane_x * mlx->movespeed),
					(int)(mlx->pos_y)) == 0)
			mlx->pos_x += mlx->plane_x * mlx->movespeed;
		if (map((int)(mlx->pos_x),
					(int)(mlx->pos_y + mlx->plane_y * mlx->movespeed)) == 0)
			mlx->pos_y += mlx->plane_y * mlx->movespeed;
	}
	if (keycode == 0)
	{
		init_time(mlx);
		if (map((int)(mlx->pos_x - mlx->plane_x * mlx->movespeed),
					(int)(mlx->pos_y)) == 0)
			mlx->pos_x -= mlx->plane_x * mlx->movespeed;
		if (map((int)(mlx->pos_x),
			(int)(mlx->pos_y - mlx->plane_y * mlx->movespeed)) == 0)
			mlx->pos_y -= mlx->plane_y * mlx->movespeed;
	}
}

static void	key_rot(int keycode, t_mlx *mlx)
{
	if (keycode == 124)
	{
		init_time(mlx);
		mlx->olddir_x = mlx->dir_x;
		mlx->dir_x = mlx->dir_x * cos(-mlx->rotspeed) -
		mlx->dir_y * sin(-mlx->rotspeed);
		mlx->dir_y = mlx->olddir_x * sin(-mlx->rotspeed) +
		mlx->dir_y * cos(-mlx->rotspeed);
		mlx->oldplane_x = mlx->plane_x;
		mlx->plane_x = mlx->plane_x * cos(-mlx->rotspeed) -
		mlx->plane_y * sin(-mlx->rotspeed);
		mlx->plane_y = mlx->oldplane_x * sin(-mlx->rotspeed) +
		mlx->plane_y * cos(-mlx->rotspeed);
	}
	if (keycode == 123)
	{
		init_time(mlx);
		key_rot_t(mlx);
	}
}

int			key_move(int keycode, t_mlx *mlx)
{
	if (mlx->menu == 1 && keycode == 13)
		key_w(mlx);
	if (mlx->menu == 1 && keycode == 1)
		key_s(mlx);
	if (mlx->menu == 1 && (keycode == 2 || keycode == 0))
		key_straf(keycode, mlx);
	if (mlx->menu == 1 && (keycode == 124 || keycode == 123))
		key_rot(keycode, mlx);
	return (0);
}
