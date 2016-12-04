/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:10:07 by malorin           #+#    #+#             */
/*   Updated: 2016/09/06 16:10:11 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void	start_mlx(t_mlx mlx)
{
	int i;

	i = 0;
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, mlx.width, mlx.height, "Wolf3D");
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, key_move, &mlx);
	mlx_hook(mlx.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, red_cross, &mlx);
	mlx_loop_hook(mlx.init, expose_hook, &mlx);
	mlx_loop(mlx.init);
}

int			main(int argv, char **argc)
{
	t_mlx	mlx;

	if (argv > 1)
		ft_putendl("Warning - Wrong number of arguments.");
	mlx.width = SCREENWIDTH;
	mlx.height = SCREENHEIGHT;
	mlx.menu = 0;
	mlx.ng = 0;
	init_mlx(&mlx);
	start_mlx(mlx);
	return (0);
}
