/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 17:12:55 by malorin           #+#    #+#             */
/*   Updated: 2016/10/10 17:13:13 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void	key_echap(t_mlx *mlx)
{
	if (mlx->menu == 0)
		exit(0);
	else if (mlx->menu == 5 && mlx->loose == 0)
	{
		init_mlx(mlx);
		mlx->menu = 0;
		mlx->ng = 0;
	}
	else if (mlx->menu == 5 && mlx->loose == 1)
		mlx->menu = 1;
	else
		mlx->menu = 0;
}

static void	key_enter(t_mlx *mlx)
{
	if (mlx->menu == 0 && mlx->ctm == 0)
	{
		init_mlx(mlx);
		mlx->menu = 1;
		mlx->ng = 1;
	}
	if (mlx->menu == 0 && mlx->ctm == 1 && mlx->ng == 1)
		mlx->menu = 1;
	if (mlx->menu == 0 && mlx->ctm == 2)
		mlx->menu = 2;
	if (mlx->menu == 4 && mlx->num_hack1 == 1 && mlx->num_hack2 == 9 &&
		mlx->num_hack3 == 7 && mlx->num_hack4 == 9)
	{
		mlx->menu = 5;
		mlx->loose = 0;
	}
	if (mlx->menu == 4 && (mlx->num_hack1 != 1 || mlx->num_hack2 != 9 ||
		mlx->num_hack3 != 7 || mlx->num_hack4 != 9))
	{
		mlx->menu = 5;
		mlx->loose = 1;
	}
}

static void	key_ctm(int keycode, t_mlx *mlx)
{
	if (keycode == 126 && mlx->menu == 0 && mlx->ctm > 0)
	{
		if (mlx->ng == 1)
			mlx->ctm--;
		else
			mlx->ctm = 0;
	}
	if (keycode == 125 && mlx->menu == 0 && mlx->ctm < 2)
	{
		if (mlx->ng == 1)
			mlx->ctm++;
		else
			mlx->ctm = 2;
	}
	if (keycode == 126 && mlx->menu == 3 && mlx->ctm_inv > 0)
		mlx->ctm_inv--;
	if (keycode == 125 && mlx->menu == 3 && mlx->ctm_inv < nbr_obj(mlx))
		mlx->ctm_inv++;
}

static void	key_tools(int keycode, t_mlx *mlx)
{
	if (keycode == 34 && (mlx->menu == 1 || mlx->menu == 3))
	{
		if (mlx->menu == 1)
			mlx->menu = 3;
		else
			mlx->menu = 1;
	}
}

int			key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		key_echap(mlx);
	if (keycode == 36)
		key_enter(mlx);
	if ((keycode == 126 || keycode == 125) &&
		(mlx->menu == 0 || mlx->menu == 3))
		key_ctm(keycode, mlx);
	if (keycode == 34)
		key_tools(keycode, mlx);
	if (keycode == 14 && mlx->hack == 1)
		mlx->menu = 4;
	if (keycode == 14 && mlx->key_ig == 1)
		open_door(mlx);
	if (mlx->menu == 4)
		key_hack(keycode, mlx);
	return (0);
}
