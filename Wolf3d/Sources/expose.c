/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:17:22 by malorin           #+#    #+#             */
/*   Updated: 2016/10/10 19:17:32 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static int	search_wall(int x, int y)
{
	if (map(x + 1, y) <= 9 && map(x + 1, y) >= 5)
		return (map(x + 1, y));
	if (map(x + 1, y + 1) <= 9 && map(x + 1, y + 1) >= 5)
		return (map(x + 1, y + 1));
	if (map(x, y + 1) <= 9 && map(x, y + 1) >= 5)
		return (map(x, y + 1));
	if (map(x, y - 1) <= 9 && map(x, y - 1) >= 5)
		return (map(x, y - 1));
	if (map(x - 1, y + 1) <= 9 && map(x - 1, y + 1) >= 5)
		return (map(x - 1, y + 1));
	if (map(x - 1, y) <= 9 && map(x - 1, y) >= 5)
		return (map(x - 1, y));
	if (map(x - 1, y - 1) <= 9 && map(x - 1, y - 1) >= 5)
		return (map(x - 1, y - 1));
	if (map(x + 1, y - 1) <= 9 && map(x + 1, y - 1) >= 5)
		return (map(x + 1, y - 1));
	return (0);
}

static void	wall_message(t_mlx *mlx, int s_wall)
{
	if (s_wall == 5)
		mlx_string_put(mlx->init, mlx->win, mlx->width / 2,
			mlx->height / 2, 0xFFFFFFF, "Green Key : 1 ; 5");
	if (s_wall == 6)
		mlx_string_put(mlx->init, mlx->win, mlx->width / 2,
			mlx->height / 2, 0xFFFFFFF, "Red Key : 3 ; 14");
	if (s_wall == 7)
		mlx_string_put(mlx->init, mlx->win, mlx->width / 2,
			mlx->height / 2, 0xFFFFFFF, "Pink Key : 16 ; 14");
	if (s_wall == 8)
		mlx_string_put(mlx->init, mlx->win, mlx->width / 2,
			mlx->height / 2, 0xFFFFFFF, "Le guide du voyageur galactique");
	if (s_wall == 9)
	{
		mlx_string_put(mlx->init, mlx->win, mlx->width / 2,
			mlx->height / 2, 0xFFFFFFF, "Press 'E' to Hack this door");
		mlx->hack = 1;
	}
}

static void	check_position(t_mlx *mlx)
{
	double	x;
	double	y;
	int		door;
	int		s_wall;

	x = mlx->pos_x;
	y = mlx->pos_y;
	if ((s_wall = search_wall(x, y)) != 0)
		wall_message(mlx, s_wall);
	if ((door = search_door(x, y)) >= 10)
		door_message(mlx, door);
	search_key(mlx, x, y);
}

static void	draw_game(t_mlx *mlx)
{
	start_raycasting(*mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	gettimeofday(&mlx->t2, NULL);
	check_position(mlx);
	if (mlx->mess.t > 0)
		draw_mess(mlx);
	text_coord(mlx);
	mlx_string_put(mlx->init, mlx->win, 10, 10, 0xFFFFFFF, mlx->mess.pos);
	free(mlx->mess.pos);
}

int			expose_hook(t_mlx *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	mlx->img = mlx_new_image(mlx->win, mlx->width, mlx->height);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp,
	&mlx->sizeline, &mlx->endian);
	gettimeofday(&mlx->t1, NULL);
	if (mlx->menu == 1)
		draw_game(mlx);
	if (mlx->menu == 0)
		draw_menu(mlx);
	if (mlx->menu == 2)
		draw_control(mlx);
	if (mlx->menu == 3)
		draw_inv(mlx);
	if (mlx->menu == 4)
		draw_consol(mlx);
	if (mlx->menu == 5)
	{
		if (mlx->loose == 0)
			mlx_string_put(mlx->init, mlx->win, 500, 300, 0xFFFFFFF, "GG");
		else
			mlx_string_put(mlx->init, mlx->win, 500, 300, 0xFFFFFFF, "NOOB.");
	}
	free(mlx->img);
	free(mlx->data);
	return (0);
}
