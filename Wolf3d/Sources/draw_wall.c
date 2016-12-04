/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_special_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:57:11 by malorin           #+#    #+#             */
/*   Updated: 2016/10/10 19:57:19 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		draw_blue_w(t_mlx *mlx, int x)
{
	while (mlx->draw_start != mlx->draw_end)
	{
		mlx->data[mlx->draw_start * mlx->sizeline
		+ x * mlx->bpp / 8 + 0] = mlx->cf;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 2] = 0;
		mlx->draw_start++;
	}
}

void		draw_green_w(t_mlx *mlx, int x)
{
	while (mlx->draw_start != mlx->draw_end)
	{
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline
		+ x * mlx->bpp / 8 + 1] = mlx->cf;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 2] = 0;
		mlx->draw_start++;
	}
}

void		draw_red_w(t_mlx *mlx, int x)
{
	while (mlx->draw_start != mlx->draw_end)
	{
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline
		+ x * mlx->bpp / 8 + 2] = mlx->cf;
		mlx->draw_start++;
	}
}

void		draw_pink_w(t_mlx *mlx, int x)
{
	while (mlx->draw_start != mlx->draw_end)
	{
		mlx->data[mlx->draw_start * mlx->sizeline
		+ x * mlx->bpp / 8 + 0] = mlx->cf;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline
		+ x * mlx->bpp / 8 + 2] = mlx->cf;
		mlx->draw_start++;
	}
}

void		draw_orange_w(t_mlx *mlx, int x)
{
	while (mlx->draw_start != mlx->draw_end)
	{
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 140;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 2] = 255;
		mlx->draw_start++;
	}
}
