/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_end_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 20:01:45 by malorin           #+#    #+#             */
/*   Updated: 2016/10/10 20:02:01 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void	end_wall_blue(t_mlx *mlx, int x, int blue)
{
	while (mlx->draw_start != blue)
	{
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 0] = 150;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 2] = 0;
		mlx->draw_start++;
	}
}

static void	end_wall_green(t_mlx *mlx, int x, int green)
{
	while (mlx->draw_start != green)
	{
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 150;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 2] = 0;
		mlx->draw_start++;
	}
}

static void	end_wall_red(t_mlx *mlx, int x, int red)
{
	while (mlx->draw_start != red)
	{
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 2] = 150;
		mlx->draw_start++;
	}
}

static void	end_wall_pink(t_mlx *mlx, int x)
{
	while (mlx->draw_start != mlx->draw_end)
	{
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 0] = 100;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 1] = 0;
		mlx->data[mlx->draw_start * mlx->sizeline + x * mlx->bpp / 8 + 2] = 100;
		mlx->draw_start++;
	}
}

void		draw_end_wall(t_mlx *mlx, int x)
{
	int		blue;
	int		green;
	int		red;

	blue = mlx->draw_start + ((mlx->draw_end - mlx->draw_start) / 4);
	green = blue + ((mlx->draw_end - mlx->draw_start) / 4);
	red = green + ((mlx->draw_end - mlx->draw_start) / 4);
	end_wall_blue(mlx, x, blue);
	end_wall_green(mlx, x, green);
	end_wall_red(mlx, x, red);
	end_wall_pink(mlx, x);
}
