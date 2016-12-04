/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_inv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:08:28 by malorin           #+#    #+#             */
/*   Updated: 2016/10/10 19:08:39 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static int	ctm_color(t_mlx *mlx, int key)
{
	if (mlx->ctm_inv == key)
	{
		if (key == 1 && mlx->inv.key_g == 1)
			mlx_string_put(mlx->init, mlx->win, 550, 250, 0xFFFFFFF,
			"Found in : 1 ; 5");
		if (key == 2 && mlx->inv.key_r == 1)
			mlx_string_put(mlx->init, mlx->win, 550, 300, 0xFFFFFFF,
			"Found in : 3 ; 14");
		if (key == 3 && mlx->inv.key_p == 1)
			mlx_string_put(mlx->init, mlx->win, 550, 350, 0xFFFFFFF,
			"Found in : 16 ; 14");
		return (255 + (255 * 256) + (255 * 256 * 256));
	}
	return (0 + (140 * 256) + (255 * 256 * 256));
}

void		draw_inv(t_mlx *mlx)
{
	mlx_string_put(mlx->init, mlx->win, 500, 70, 0xFFFFFFF, "Inventory");
	mlx_string_put(mlx->init, mlx->win, 200, 200, 0xF0900FF, "Blue Key : ");
	mlx_string_put(mlx->init, mlx->win, 310, 200, ctm_color(mlx, 0),
	"Open The Blue Door");
	if (mlx->inv.key_g == 1)
	{
		mlx_string_put(mlx->init, mlx->win, 200, 250, 0xF00FF44,
		"Green Key : ");
		mlx_string_put(mlx->init, mlx->win, 315, 250, ctm_color(mlx, 1),
		"Open The Green Door");
	}
	if (mlx->inv.key_r == 1)
	{
		mlx_string_put(mlx->init, mlx->win, 200, 300, 0xFFF0000, "Red Key : ");
		mlx_string_put(mlx->init, mlx->win, 305, 300, ctm_color(mlx, 2),
		"Open The Red Door");
	}
	if (mlx->inv.key_p == 1)
	{
		mlx_string_put(mlx->init, mlx->win, 200, 350, 0xFEF00FF, "Pink Key : ");
		mlx_string_put(mlx->init, mlx->win, 310, 350, ctm_color(mlx, 3),
		"Open The Pink Door");
	}
}
