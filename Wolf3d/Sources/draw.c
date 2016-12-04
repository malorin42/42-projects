/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:14:11 by malorin           #+#    #+#             */
/*   Updated: 2016/09/07 16:14:19 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void		draw_floor(t_mlx *mlx, int x)
{
	while (mlx->draw_start < mlx->height)
	{
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 0] = 150;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 150;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 2] = 150;
		mlx->draw_start++;
	}
}

void			draw_wolf3d(t_mlx mlx, int x)
{
	if (mlx.obj == 1)
		draw_blue_w(&mlx, x);
	if (mlx.obj == 2)
		draw_green_w(&mlx, x);
	if (mlx.obj == 3)
		draw_red_w(&mlx, x);
	if (mlx.obj == 4)
		draw_pink_w(&mlx, x);
	if (mlx.obj >= 5 && mlx.obj <= 8)
		draw_orange_w(&mlx, x);
	if (mlx.obj == 9)
		draw_end_wall(&mlx, x);
	if (mlx.obj == 10)
		draw_blue_d(&mlx, x);
	if (mlx.obj == 11)
		draw_green_d(&mlx, x);
	if (mlx.obj == 12)
		draw_red_d(&mlx, x);
	if (mlx.obj == 13)
		draw_pink_d(&mlx, x);
	draw_floor(&mlx, x);
}
