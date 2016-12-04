/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 17:37:06 by malorin           #+#    #+#             */
/*   Updated: 2016/10/10 17:37:20 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void	add_num(t_mlx *mlx)
{
	if (mlx->ctm_hack == 0)
		mlx->num_hack1 = mlx->num;
	if (mlx->ctm_hack == 1)
		mlx->num_hack2 = mlx->num;
	if (mlx->ctm_hack == 2)
		mlx->num_hack3 = mlx->num;
	if (mlx->ctm_hack == 3)
		mlx->num_hack4 = mlx->num;
}

static void	key_num(int keycode, t_mlx *mlx)
{
	if (keycode == 29)
	{
		mlx->num = 0;
		add_num(mlx);
	}
	if (keycode == 18)
	{
		mlx->num = 1;
		add_num(mlx);
	}
	if (keycode == 19)
	{
		mlx->num = 2;
		add_num(mlx);
	}
	if (keycode == 20)
	{
		mlx->num = 3;
		add_num(mlx);
	}
	if (keycode == 21)
	{
		mlx->num = 4;
		add_num(mlx);
	}
}

static void	key_num2(int keycode, t_mlx *mlx)
{
	if (keycode == 23)
	{
		mlx->num = 5;
		add_num(mlx);
	}
	if (keycode == 22)
	{
		mlx->num = 6;
		add_num(mlx);
	}
	if (keycode == 26)
	{
		mlx->num = 7;
		add_num(mlx);
	}
	if (keycode == 28)
	{
		mlx->num = 8;
		add_num(mlx);
	}
	if (keycode == 25)
	{
		mlx->num = 9;
		add_num(mlx);
	}
}

int			key_hack(int keycode, t_mlx *mlx)
{
	if (keycode == 124 && mlx->ctm_hack < 3)
		mlx->ctm_hack++;
	if (keycode == 123 && mlx->ctm_hack > 0)
		mlx->ctm_hack--;
	key_num(keycode, mlx);
	key_num2(keycode, mlx);
	if (keycode == 36 && mlx->num_hack1 == 1 && mlx->num_hack2 == 9 &&
		mlx->num_hack3 == 7 && mlx->num_hack4 == 9)
	{
		mlx->menu = 5;
		mlx->loose = 0;
	}
	if (keycode == 36 && (mlx->num_hack1 != 1 || mlx->num_hack2 != 9 ||
		mlx->num_hack3 != 7 || mlx->num_hack4 != 9))
	{
		mlx->menu = 5;
		mlx->loose = 1;
	}
	return (0);
}
