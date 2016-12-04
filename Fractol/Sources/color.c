/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:51:30 by malorin           #+#    #+#             */
/*   Updated: 2016/09/05 16:51:31 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static void		ft_put_pixel_one(t_mlx *mlx, int x, int y, int i)
{
	if (i <= mlx->imax % 40)
	{
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 0] = i % 256;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 1] = i % 256;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 2] = 0;
	}
	else if (i >= mlx->imax)
	{
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 1] = i % 256;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 2] = i % 256;
	}
	else
	{
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 0] = i % 256;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 1] = 0;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 2] = i % 256;
	}
}

static void		ft_put_pixel_two(t_mlx *mlx, int x, int y, int i)
{
	if (i <= mlx->imax % 40)
	{
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 0] = i % 256;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 1] = i % 256;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 2] = 0;
	}
	else if (i >= mlx->imax)
	{
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 1] = i % 256;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 2] = 0;
	}
	else
	{
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 1] = i % 256;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 2] = 0;
	}
}

static void		ft_put_pixel_three(t_mlx *mlx, int x, int y, int i)
{
	if (i <= mlx->imax % 40)
	{
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 1] = 0;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 2] = i % 256;
	}
	else if (i >= mlx->imax)
	{
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 1] = i % 256 / 4;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 2] = i % 256;
	}
	else
	{
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 1] = 0;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 2] = i % 256;
	}
}

static void		ft_put_pixel_four(t_mlx *mlx, int x, int y, int i)
{
	if (i <= mlx->imax % 40)
	{
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 0] = i % 256;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 1] = 0;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 2] = 0;
	}
	else if (i >= mlx->imax)
	{
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 1] = i % 256;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 2] = i % 256;
	}
	else
	{
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 0] = 0;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 1] = i % 256;
		mlx->data[y * mlx->sizeline + x * mlx->bpp / 8 + 2] = i % 256;
	}
}

void			choose_color(t_mlx *mlx, int x, int y, int i)
{
	if (i > mlx->imax)
		ft_put_pixel_one(mlx, x, y, 0);
	if (mlx->color == 0)
		ft_put_pixel_one(mlx, x, y, i);
	if (mlx->color == 1)
		ft_put_pixel_two(mlx, x, y, i);
	if (mlx->color == 2)
		ft_put_pixel_three(mlx, x, y, i);
	if (mlx->color == 3)
		ft_put_pixel_four(mlx, x, y, i);
}
