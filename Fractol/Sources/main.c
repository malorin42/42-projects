/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 08:21:57 by malorin           #+#    #+#             */
/*   Updated: 2016/08/25 19:42:59 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int				expose_hook(t_mlx *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	mlx->img = mlx_new_image(mlx->win, mlx->width, mlx->height);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline,
		&mlx->endian);
	if (mlx->map == 0)
		draw_menu(mlx);
	if (mlx->map == 1)
	{
		draw_julia(mlx);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	}
	if (mlx->map == 2)
	{
		draw_mandelbrot(mlx);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	}
	if (mlx->map == 3)
	{
		draw_burning_ship(mlx);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	}
	return (0);
}

static int		mouse_hook(int mouse_code, int x, int y, t_mlx *mlx)
{
	if (mlx->map >= 0)
	{
		if (mouse_code == 5)
		{
			mlx->zoom *= 1.1;
			y > mlx->height / 2 ? (mlx->my += 0.1 / mlx->zoom)
				: (mlx->my -= 0.1 / mlx->zoom);
			x > mlx->width / 2 ? (mlx->mx += 0.1 / mlx->zoom)
				: (mlx->mx -= 0.1 / mlx->zoom);
			mlx->imax += 50 + mlx->zoom;
		}
		if (mouse_code == 4)
			mlx->zoom /= 1.1;
	}
	ft_bzero(mlx->data, (sizeof(char) * 600 * 400 * (mlx->bpp / 8)));
	expose_hook(mlx);
	return (0);
}

static int		motion_hook(int x, int y, t_mlx *mlx)
{
	if (mlx->motion_off == 0)
	{
		if (x >= 0 && x < mlx->width && y >= 0 && y < mlx->height)
		{
			mlx->c_x = 0.27015 + 0.002 * x;
			mlx->c_y = -1 * (0.7) + 0.002 * y;
		}
	}
	expose_hook(mlx);
	return (0);
}

static void		start_mlx(t_mlx mlx)
{
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, mlx.width, mlx.height, "fract_ol");
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 6, 64, &motion_hook, &mlx);
	mlx_mouse_hook(mlx.win, &mouse_hook, &mlx);
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_loop(mlx.init);
}

int				main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2 || (ft_strcmp(av[1], "mandelbrot") != 0 &&
		ft_strcmp(av[1], "julia") != 0 && ft_strcmp(av[1], "burningship") != 0))
	{
		ft_putstr("Wrong parameter.\nDo : ./fractole [mandelbrot/julia");
		ft_putendl("/burningship]");
		return (0);
	}
	mlx.width = 600;
	mlx.height = 400;
	mlx.color = 0;
	mlx.imax = 100;
	if (ft_strcmp(av[1], "julia") == 0)
		mlx.map = 1;
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		mlx.map = 2;
	if (ft_strcmp(av[1], "burningship") == 0)
		mlx.map = 3;
	struct_init(&mlx);
	start_mlx(mlx);
}
