/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 20:18:07 by malorin           #+#    #+#             */
/*   Updated: 2016/10/20 20:18:11 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	key_w_t(t_mlx *mlx)
{
	if (map((int)(mlx->pos_x + mlx->dir_x * mlx->movespeed),
				(int)(mlx->pos_y)) >= 10)
	{
		if (check_door(mlx, mlx->pos_x + mlx->dir_x *
					mlx->movespeed, mlx->pos_y) == 0)
			mlx->pos_x += mlx->dir_x * mlx->movespeed;
	}
	else
		mlx->pos_x += mlx->dir_x * mlx->movespeed;
}

void	key_s_t(t_mlx *mlx)
{
	if (map((int)(mlx->pos_x - mlx->dir_x * mlx->movespeed),
				(int)(mlx->pos_y)) >= 10)
	{
		if (check_door(mlx, mlx->pos_x - mlx->dir_x *
					mlx->movespeed, mlx->pos_y))
			mlx->pos_x -= mlx->dir_x * mlx->movespeed;
	}
	else
		mlx->pos_x -= mlx->dir_x * mlx->movespeed;
}

void	key_rot_t(t_mlx *mlx)
{
	mlx->olddir_x = mlx->dir_x;
	mlx->dir_x = mlx->dir_x * cos(mlx->rotspeed) - mlx->dir_y *
		sin(mlx->rotspeed);
	mlx->dir_y = mlx->olddir_x * sin(mlx->rotspeed) + mlx->dir_y *
		cos(mlx->rotspeed);
	mlx->oldplane_x = mlx->plane_x;
	mlx->plane_x = mlx->plane_x * cos(mlx->rotspeed) - mlx->plane_y *
		sin(mlx->rotspeed);
	mlx->plane_y = mlx->oldplane_x * sin(mlx->rotspeed) + mlx->plane_y *
		cos(mlx->rotspeed);
}
