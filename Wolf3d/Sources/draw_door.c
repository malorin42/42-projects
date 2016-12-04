/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:34:21 by malorin           #+#    #+#             */
/*   Updated: 2016/10/06 18:34:27 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	draw_blue_d(t_mlx *mlx, int x)
{
	while (mlx->draw_start != mlx->draw_end)
	{
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 0] = 25;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 2] = 0;
		mlx->draw_start++;
	}
}

void	draw_green_d(t_mlx *mlx, int x)
{
	while (mlx->draw_start != mlx->draw_end)
	{
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 25;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 2] = 0;
		mlx->draw_start++;
	}
}

void	draw_red_d(t_mlx *mlx, int x)
{
	while (mlx->draw_start != mlx->draw_end)
	{
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 2] = 25;
		mlx->draw_start++;
	}
}

void	draw_pink_d(t_mlx *mlx, int x)
{
	while (mlx->draw_start != mlx->draw_end)
	{
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 0] = 100;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 100;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 2] = 150;
		mlx->draw_start++;
	}
}
