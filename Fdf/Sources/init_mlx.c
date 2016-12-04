/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:04:07 by malorin           #+#    #+#             */
/*   Updated: 2016/04/05 15:04:11 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		mlx_setup(t_mlx *mlx, int xmax, int ymax, int ***tab)
{
	mlx->tab = *tab;
	mlx->t = 20;
	mlx->ori_x = 0;
	mlx->ori_y = 0;
	mlx->color = 1;
	mlx->xmax = xmax;
	mlx->ymax = ymax;
	mlx->zmax = search_highest(mlx);
}

static int		key_hook(int keycode, t_mlx *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	if (keycode == 53)
		exit(0);
	if (keycode == 69 && mlx->t <= 50)
		mlx->t = mlx->t + 10;
	if (keycode == 78 && mlx->t > 10)
		mlx->t = mlx->t - 10;
	if (keycode == 124)
		mlx->ori_x = mlx->ori_x + 20;
	if (keycode == 123)
		mlx->ori_x = mlx->ori_x - 20;
	if (keycode == 126)
		mlx->ori_y = mlx->ori_y - 20;
	if (keycode == 125)
		mlx->ori_y = mlx->ori_y + 20;
	if (keycode > 82 && keycode < 87)
		mlx->color = keycode - 82;
	draw_fdf(mlx);
	return (0);
}

static int		expose_hook(t_mlx *mlx)
{
	draw_fdf(mlx);
	return (0);
}

void			init_mlx(int ymax, int xmax, int ***tab)
{
	t_mlx	mlx;

	mlx.width = 1000;
	mlx.height = 1000;
	mlx_setup(&mlx, xmax, ymax, tab);
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, mlx.width, mlx.height, "FdF");
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.init);
}
