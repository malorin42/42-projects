/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:02:58 by malorin           #+#    #+#             */
/*   Updated: 2016/04/05 15:02:59 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_env
{
	int	x;
	int	y;
	int	yp;
	int	xp;
	int	xmax;
	int	ymax;
	int	ori_x;
	int	ori_y;
	int	dx;
	int	dy;
	int	dp;
	int	delta_e;
	int	delta_ne;
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}				t_env;

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	int		width;
	int		height;
	int		t;
	int		xmax;
	int		ymax;
	int		**tab;
	int		ori_x;
	int		ori_y;
	int		zmax;
	int		color;
}				t_mlx;

typedef struct	s_map
{
	int			x;
	int			y;
	int			z;
}				t_map;

void			search_size(char **ac);
int				search_highest(t_mlx *mlx);
int				color(t_mlx *mlx, int z1, int z2);
void			fill_tab(char *map, int ymax, int xmax);
void			init_mlx(int ymax, int xmax, int ***tab);
void			draw_fdf(t_mlx *mlx);
void			draw_ramps_sup1(t_mlx *mlx, t_env coo, int z1, int z2);
void			draw_ramps_inf1(t_mlx *mlx, t_env coo, int z1, int z2);
void			draw_ramps_sup2(t_mlx *mlx, t_env coo, int z1, int z2);
void			draw_ramps_inf2(t_mlx *mlx, t_env coo, int z1, int z2);
void			draw_ramps_inf1_re(t_mlx *mlx, t_env coo, int z1, int z2);
void			draw_ramps_sup2_re(t_mlx *mlx, t_env coo, int z1, int z2);
void			draw_ramps_inf2_re(t_mlx *mlx, t_env coo, int z1, int z2);
void			draw_ramps_sup1_re(t_mlx *mlx, t_env coo, int z1, int z2);

#endif
