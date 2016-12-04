/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 18:53:04 by malorin           #+#    #+#             */
/*   Updated: 2016/10/10 18:53:15 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void	do_open(t_mlx *mlx, int door)
{
	if (door == 10)
		mlx->blue_d.open = 0;
	if (door == 11)
		mlx->green_d.open = 0;
	if (door == 12)
		mlx->red_d.open = 0;
	if (door == 13)
		mlx->pink_d.open = 0;
}

static void	check_key(t_mlx *mlx, int door)
{
	if (door == 10 && mlx->inv.key_b == 1)
		do_open(mlx, door);
	if (door == 11 && mlx->inv.key_g == 1)
		do_open(mlx, door);
	if (door == 12 && mlx->inv.key_r == 1)
		do_open(mlx, door);
	if (door == 13 && mlx->inv.key_p == 1)
		do_open(mlx, door);
}

static void	check_lock(t_mlx *mlx, int lock, int door)
{
	if (lock == 0)
		do_open(mlx, door);
	else
		check_key(mlx, door);
}

static void	open_part_1(t_mlx *mlx, int x, int y)
{
	if ((map((int)(x + 1), (int)(y)) == 10)
		|| (map((int)(x + 1), (int)(y + 1)) == 10)
		|| (map((int)(x), (int)(y + 1)) == 10)
		|| (map((int)(x), (int)(y - 1)) == 10)
		|| (map((int)(x - 1), (int)(y + 1)) == 10)
		|| (map((int)(x - 1), (int)(y)) == 10)
		|| (map((int)(x - 1), (int)(y - 1)) == 10)
		|| (map((int)(x + 1), (int)(y - 1)) == 10))
		check_lock(mlx, mlx->blue_d.lock, 10);
	if ((map((int)(x + 1), (int)(y)) == 11)
		|| (map((int)(x + 1), (int)(y + 1)) == 11)
		|| (map((int)(x), (int)(y + 1)) == 11)
		|| (map((int)(x), (int)(y - 1)) == 11)
		|| (map((int)(x - 1), (int)(y + 1)) == 11)
		|| (map((int)(x - 1), (int)(y)) == 11)
		|| (map((int)(x - 1), (int)(y - 1)) == 11)
		|| (map((int)(x + 1), (int)(y - 1)) == 11))
		check_lock(mlx, mlx->green_d.lock, 11);
}

void		open_door(t_mlx *mlx)
{
	double	x;
	double	y;

	x = mlx->pos_x;
	y = mlx->pos_y;
	open_part_1(mlx, x, y);
	if ((map((int)(x + 1), (int)(y)) == 12)
		|| (map((int)(x + 1), (int)(y + 1)) == 12)
		|| (map((int)(x), (int)(y + 1)) == 12)
		|| (map((int)(x), (int)(y - 1)) == 12)
		|| (map((int)(x - 1), (int)(y + 1)) == 12)
		|| (map((int)(x - 1), (int)(y)) == 12)
		|| (map((int)(x - 1), (int)(y - 1)) == 12)
		|| (map((int)(x + 1), (int)(y - 1)) == 12))
		check_lock(mlx, mlx->green_d.lock, 12);
	if ((map((int)(x + 1), (int)(y)) == 13)
		|| (map((int)(x + 1), (int)(y + 1)) == 13)
		|| (map((int)(x), (int)(y + 1)) == 13)
		|| (map((int)(x), (int)(y - 1)) == 13)
		|| (map((int)(x - 1), (int)(y + 1)) == 13)
		|| (map((int)(x - 1), (int)(y)) == 13)
		|| (map((int)(x - 1), (int)(y - 1)) == 13)
		|| (map((int)(x + 1), (int)(y - 1)) == 13))
		check_lock(mlx, mlx->green_d.lock, 13);
}
