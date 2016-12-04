/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_kack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:01:13 by malorin           #+#    #+#             */
/*   Updated: 2016/10/10 19:01:23 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void	draw_square(t_mlx *mlx, int width, int c)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	j = 0;
	if (mlx->ctm_hack == c)
		color = 255 + (255 * 256) + (255 * 256 * 256);
	else
		color = 0 + (140 * 256) + (255 * 256 * 256);
	while (i <= 40)
	{
		mlx_pixel_put(mlx->init, mlx->win, width + i, mlx->height / 2, color);
		mlx_pixel_put(mlx->init, mlx->win, width + i,
		mlx->height / 2 + 40, color);
		i++;
	}
	while (j <= 40)
	{
		mlx_pixel_put(mlx->init, mlx->win, width, mlx->height / 2 + j, color);
		mlx_pixel_put(mlx->init, mlx->win, width + 40,
		mlx->height / 2 + j, color);
		j++;
	}
}

static void	draw_number(t_mlx *mlx)
{
	char	*num1;
	char	*num2;
	char	*num3;
	char	*num4;

	num1 = ft_itoa(mlx->num_hack1);
	num2 = ft_itoa(mlx->num_hack2);
	num3 = ft_itoa(mlx->num_hack3);
	num4 = ft_itoa(mlx->num_hack4);
	mlx_string_put(mlx->init, mlx->win, 435, mlx->height / 2 + 10,
	0xFFFFFFF, num1);
	mlx_string_put(mlx->init, mlx->win, 495, mlx->height / 2 + 10,
	0xFFFFFFF, num2);
	mlx_string_put(mlx->init, mlx->win, 575, mlx->height / 2 + 10,
	0xFFFFFFF, num3);
	mlx_string_put(mlx->init, mlx->win, 635, mlx->height / 2 + 10,
	0xFFFFFFF, num4);
	free(num1);
	free(num2);
	free(num3);
	free(num4);
}

void		draw_consol(t_mlx *mlx)
{
	mlx_string_put(mlx->init, mlx->win, 450, 150, 0xFFFFFFF,
	"Can You Hack this ?");
	draw_square(mlx, 420, 0);
	draw_square(mlx, 480, 1);
	draw_square(mlx, 560, 2);
	draw_square(mlx, 620, 3);
	mlx_string_put(mlx->init, mlx->win, 430, 550, 0xFFFFFFF,
	"Press Enter to finish");
	draw_number(mlx);
}
