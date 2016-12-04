/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 18:24:09 by malorin           #+#    #+#             */
/*   Updated: 2016/10/10 18:24:20 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void	init_inv(t_mlx *mlx)
{
	t_invt inv;
	t_mess mess;

	inv.key_b = 1;
	inv.key_g = 0;
	inv.key_r = 0;
	inv.key_p = 0;
	mess.pos = "";
	mess.num_key = 0;
	mlx->mess = mess;
	mlx->inv = inv;
}

static void	init_door(t_mlx *mlx)
{
	t_door blue_d;
	t_door green_d;
	t_door red_d;
	t_door pink_d;

	blue_d.open = 1;
	blue_d.lock = 0;
	blue_d.key_x = 0;
	blue_d.key_y = 0;
	green_d.open = 1;
	green_d.lock = 1;
	green_d.key_x = 1;
	green_d.key_y = 5;
	red_d.open = 1;
	red_d.lock = 1;
	red_d.key_x = 3;
	red_d.key_y = 14;
	pink_d.open = 1;
	pink_d.lock = 1;
	pink_d.key_x = 16;
	pink_d.key_y = 14;
	mlx->blue_d = blue_d;
	mlx->green_d = green_d;
	mlx->red_d = red_d;
	mlx->pink_d = pink_d;
}

void		init_mlx(t_mlx *mlx)
{
	mlx->pos_x = 3;
	mlx->pos_y = 2;
	mlx->dir_x = -1;
	mlx->dir_y = 0;
	mlx->plane_x = 0;
	mlx->plane_y = 0.66;
	mlx->oldt = 0;
	mlx->t = 0;
	mlx->num = 0;
	mlx->num_hack1 = 0;
	mlx->num_hack2 = 0;
	mlx->num_hack3 = 0;
	mlx->num_hack4 = 0;
	mlx->err = 1;
	mlx->width_w = mlx->width;
	mlx->height_w = mlx->height;
	mlx->ctm = 1;
	mlx->ctm_inv = 0;
	mlx->hack = 0;
	mlx->ctm_hack = 0;
	init_inv(mlx);
	init_door(mlx);
	init_watch(mlx);
}

void		init_watch(t_mlx *mlx)
{
	mlx->north_face = 0;
	mlx->south_face = 0;
	mlx->est_face = 0;
	mlx->west_face = 0;
	mlx->watch_north = 0;
	mlx->watch_south = 0;
	mlx->watch_est = 0;
	mlx->watch_west = 0;
}

int			init_time(t_mlx *mlx)
{
	mlx->t = (mlx->t2.tv_sec - mlx->t1.tv_sec) * 1000;
	mlx->t += (mlx->t2.tv_usec - mlx->t1.tv_usec) / 1000;
	mlx->ft = mlx->t / 1000;
	mlx->movespeed = mlx->ft * 12.0;
	mlx->rotspeed = mlx->ft * 12.0;
	return (0);
}
