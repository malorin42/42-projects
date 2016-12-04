/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 20:02:42 by malorin           #+#    #+#             */
/*   Updated: 2016/10/12 20:03:02 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void	next_watch(t_mlx *mlx)
{
	if (mlx->watch_south == 1 && mlx->watch_est == 1)
	{
		if (mlx->side == 1)
			mlx->west_face = 1;
		else
			mlx->north_face = 1;
	}
	if (mlx->watch_south == 1 && mlx->watch_west == 1)
	{
		if (mlx->side == 1)
			mlx->est_face = 1;
		else
			mlx->north_face = 1;
	}
	if (mlx->north_face == 1)
		mlx->cf = 60;
	if (mlx->south_face == 1)
		mlx->cf = 100;
	if (mlx->est_face == 1)
		mlx->cf = 150;
	if (mlx->west_face == 1)
		mlx->cf = 190;
	init_watch(mlx);
}

void		watch_pos(t_mlx *mlx)
{
	if (mlx->pos_x >= mlx->map_x)
		mlx->watch_north = 1;
	if (mlx->pos_x <= mlx->map_x)
		mlx->watch_south = 1;
	if (mlx->pos_y >= mlx->map_y)
		mlx->watch_west = 1;
	if (mlx->pos_y <= mlx->map_y)
		mlx->watch_est = 1;
	if (mlx->watch_north == 1 && mlx->watch_est == 1)
	{
		if (mlx->side == 1)
			mlx->west_face = 1;
		else
			mlx->south_face = 1;
	}
	if (mlx->watch_north == 1 && mlx->watch_west == 1)
	{
		if (mlx->side == 1)
			mlx->est_face = 1;
		else
			mlx->south_face = 1;
	}
	next_watch(mlx);
}
