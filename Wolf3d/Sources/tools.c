/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:11:25 by malorin           #+#    #+#             */
/*   Updated: 2016/10/10 19:11:34 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void			search_key(t_mlx *mlx, int x, int y)
{
	if (x == mlx->green_d.key_x && y == mlx->green_d.key_y &&
		mlx->inv.key_g == 0)
	{
		mlx->inv.key_g = 1;
		mlx->mess.num_key = 1;
		mlx->mess.t = 150;
		return ;
	}
	if (x == mlx->red_d.key_x && y == mlx->red_d.key_y && mlx->inv.key_r == 0)
	{
		mlx->inv.key_r = 1;
		mlx->mess.num_key = 2;
		mlx->mess.t = 150;
		return ;
	}
	if (x == mlx->pink_d.key_x && y == mlx->pink_d.key_y && mlx->inv.key_p == 0)
	{
		mlx->inv.key_p = 1;
		mlx->mess.num_key = 3;
		mlx->mess.t = 150;
		return ;
	}
}

int				nbr_obj(t_mlx *mlx)
{
	int		i;

	i = 0;
	if (mlx->inv.key_g == 1)
		i++;
	if (mlx->inv.key_r == 1)
		i++;
	if (mlx->inv.key_p == 1)
		i++;
	return (i);
}

void			text_coord(t_mlx *mlx)
{
	char	*tmp;

	mlx->mess.pos = "Pos : (x : ";
	mlx->mess.x = ft_itoa((int)mlx->pos_x);
	mlx->mess.y = ft_itoa((int)mlx->pos_y);
	mlx->mess.pos = ft_strjoin(mlx->mess.pos, mlx->mess.x);
	tmp = mlx->mess.pos;
	mlx->mess.pos = ft_strjoin(mlx->mess.pos, " ; y : ");
	free(tmp);
	tmp = mlx->mess.pos;
	mlx->mess.pos = ft_strjoin(mlx->mess.pos, mlx->mess.y);
	free(tmp);
	tmp = mlx->mess.pos;
	mlx->mess.pos = ft_strjoin(mlx->mess.pos, " )");
	free(tmp);
	free(mlx->mess.x);
	free(mlx->mess.y);
}

void			draw_mess(t_mlx *mlx)
{
	if (mlx->mess.num_key == 1)
		mlx_string_put(mlx->init, mlx->win, mlx->width / 2, mlx->height / 2,
		0xFFFFFFF, "New key (green)");
	if (mlx->mess.num_key == 2)
		mlx_string_put(mlx->init, mlx->win, mlx->width / 2, mlx->height / 2,
		0xFFFFFFF, "New key (red)");
	if (mlx->mess.num_key == 3)
		mlx_string_put(mlx->init, mlx->win, mlx->width / 2, mlx->height / 2,
		0xFFFFFFF, "New key (pink)");
	mlx->mess.t -= 1;
}

int				red_cross(t_mlx *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	exit(0);
	return (0);
}
