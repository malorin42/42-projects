/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:22:20 by malorin           #+#    #+#             */
/*   Updated: 2016/10/10 19:22:31 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int			search_door(double x, double y)
{
	if (map((int)(x + 1), (int)(y)) >= 10)
		return (map((int)(x + 1), (int)(y)));
	if (map((int)(x + 1), (int)(y + 1)) >= 10)
		return (map((int)(x + 1), (int)(y + 1)));
	if (map((int)(x), (int)(y + 1)) >= 10)
		return (map((int)(x), (int)(y + 1)));
	if (map((int)(x), (int)(y - 1)) >= 10)
		return (map((int)(x), (int)(y - 1)));
	if (map((int)(x - 1), (int)(y + 1)) >= 10)
		return (map((int)(x - 1), (int)(y + 1)));
	if (map((int)(x - 1), (int)(y)) >= 10)
		return (map((int)(x - 1), (int)(y)));
	if (map((int)(x - 1), (int)(y - 1)) >= 10)
		return (map((int)(x - 1), (int)(y - 1)));
	if (map((int)(x + 1), (int)(y - 1)) >= 10)
		return (map((int)(x + 1), (int)(y - 1)));
	return (0);
}

int			check_door(t_mlx *mlx, int x, int y)
{
	int		door;

	door = map(x, y);
	if (door == 10 && mlx->blue_d.open == 0)
		return (0);
	if (door == 11 && mlx->green_d.open == 0)
		return (0);
	if (door == 12 && mlx->red_d.open == 0)
		return (0);
	if (door == 13 && mlx->pink_d.open == 0)
		return (0);
	return (1);
}

static int	check_if_open(t_mlx *mlx, int door)
{
	if (door == 10)
		if (mlx->blue_d.open == 1)
			return (1);
	if (door == 11)
		if (mlx->green_d.open == 1)
			return (1);
	if (door == 12)
		if (mlx->red_d.open == 1)
			return (1);
	if (door == 13)
		if (mlx->pink_d.open == 1)
			return (1);
	return (0);
}

static int	check_if_lock(t_mlx *mlx, int door)
{
	if (door == 10)
		if (mlx->blue_d.lock == 1)
			return (1);
	if (door == 11)
		if (mlx->green_d.lock == 1 && mlx->inv.key_g == 0)
			return (1);
	if (door == 12)
		if (mlx->red_d.lock == 1 && mlx->inv.key_r == 0)
			return (1);
	if (door == 13)
		if (mlx->pink_d.lock == 1 && mlx->inv.key_p == 0)
			return (1);
	return (0);
}

void		door_message(t_mlx *mlx, int door)
{
	if (check_if_open(mlx, door) == 1)
	{
		if (check_if_lock(mlx, door) == 1)
		{
			mlx_string_put(mlx->init, mlx->win, mlx->width / 3,
			mlx->height / 2, 0xFFFFFFF, "Door is lock");
			mlx->key_ig = 0;
		}
		else
		{
			mlx_string_put(mlx->init, mlx->win, mlx->width / 3,
			mlx->height / 2, 0xFFFFFFF, "Press 'E' to open");
			mlx->key_ig = 1;
		}
	}
	else
		mlx->key_ig = 0;
}
