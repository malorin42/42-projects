/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 08:26:17 by malorin           #+#    #+#             */
/*   Updated: 2016/07/10 08:26:20 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <math.h>

typedef struct	s_mlx
{
	void		*init;
	void		*win;
	void		*img;
	int			width;
	int			height;
	double		zoom;
	int			bpp;
	int			imax;
	double		mx;
	double		my;
	int			sizeline;
	int			endian;
	double		c_x;
	double		c_y;
	char		*data;
	int			map;
	int			f;
	int			color;
	int			motion_off;
}				t_mlx;

typedef struct	s_coo
{
	double		xd;
	double		re;
	double		im;
	double		yd;
	double		tmp;
	double		xmax;
	double		ymax;
}				t_coo;

void			draw_julia(t_mlx *mlx);
void			draw_mandelbrot(t_mlx *mlx);
void			draw_burning_ship(t_mlx *mlx);
int				key_hook(int keycode, t_mlx *mlx);
void			struct_init(t_mlx *mlx);
void			draw_menu(t_mlx *mlx);
void			choose_color(t_mlx *mlx, int x, int y, int i);
int				expose_hook(t_mlx *mlx);
void			choose_map(t_mlx *mlx, int keycode);

#endif
