/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 19:45:59 by malorin           #+#    #+#             */
/*   Updated: 2016/08/25 19:46:19 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void			draw_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->init, mlx->win, mlx->width / 3,
		mlx->height / 8, 0xFFFFFFF, "Fractol");
	mlx_string_put(mlx->init, mlx->win, mlx->width / 6,
		mlx->height / 3, 0xFFFFFFF, "1 = Julia");
	mlx_string_put(mlx->init, mlx->win, mlx->width / 6,
		mlx->height / 3 + 20, 0xFFFFFFF, "2 = Mandelbrot");
	mlx_string_put(mlx->init, mlx->win, mlx->width / 6,
		mlx->height / 3 + 40, 0xFFFFFFF, "3 = Burning Ship");
}

void			struct_init(t_mlx *mlx)
{
	if (mlx->map == 1)
	{
		mlx->c_x = 0.27015;
		mlx->c_y = 0.7;
		mlx->zoom = 0.933015;
		mlx->mx = 0;
		mlx->my = 0;
		mlx->motion_off = 0;
	}
	if (mlx->map == 2)
	{
		mlx->zoom = 1;
		mlx->mx = -0.4;
		mlx->my = 0;
	}
	if (mlx->map == 3)
	{
		mlx->zoom = 0.84;
		mlx->mx = -0.357143;
		mlx->my = -0.535714;
	}
	mlx->imax = 100;
}

static void		key_color(t_mlx *mlx, int keycode)
{
	if (keycode == 21)
		mlx->color = 0;
	if (keycode == 23)
		mlx->color = 1;
	if (keycode == 22)
		mlx->color = 2;
	if (keycode == 26)
		mlx->color = 3;
	if (keycode == 1)
	{
		if (mlx->motion_off == 0)
			mlx->motion_off = 1;
		else
			mlx->motion_off = 0;
	}
}

static int		keyboard(int keycode, t_mlx *mlx)
{
	if (keycode == 69)
	{
		mlx->zoom += 0.5 * 1.2;
		mlx->imax += 100;
	}
	if (keycode == 78)
		mlx->zoom += -0.5 / 1.5;
	if (keycode == 123)
		mlx->mx -= 0.05 / mlx->zoom;
	if (keycode == 125)
		mlx->my += 0.05 / mlx->zoom;
	if (keycode == 124)
		mlx->mx += 0.05 / mlx->zoom;
	if (keycode == 126)
		mlx->my -= 0.05 / mlx->zoom;
	return (0);
}

int				key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53 && mlx->map == 0)
	{
		mlx_destroy_image(mlx->init, mlx->img);
		mlx_destroy_window(mlx->init, mlx->win);
		mlx->win = NULL;
		exit(0);
	}
	if (keycode == 53 && mlx->map != 0)
	{
		mlx->map = 0;
		mlx_clear_window(mlx->init, mlx->win);
		draw_menu(mlx);
	}
	choose_map(mlx, keycode);
	key_color(mlx, keycode);
	if (keycode != 0)
		keyboard(keycode, mlx);
	expose_hook(mlx);
	return (0);
}
