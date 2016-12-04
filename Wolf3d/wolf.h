/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:45:00 by malorin           #+#    #+#             */
/*   Updated: 2016/09/06 16:45:02 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <sys/time.h>
# define SCREENWIDTH 1080
# define SCREENHEIGHT 720
# define STRUCTURENOTIFYMASK (1L<<17)
# define DESTROYNOTIFY 17
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)

typedef struct		s_mess
{
	char			*pos;
	char			*x;
	char			*y;
	int				t;
	int				num_key;
}					t_mess;

typedef struct		s_door
{
	int				open;
	int				lock;
	int				key_x;
	int				key_y;
}					t_door;

typedef struct		s_invt
{
	int				key_b;
	int				key_g;
	int				key_r;
	int				key_p;
}					t_invt;

typedef struct		s_mlx
{
	void			*init;
	void			*win;
	void			*img;
	void			*img_w;
	int				width;
	int				width_w;
	int				height;
	int				height_w;
	int				sizeline;
	int				endian;
	int				bpp;
	int				**texture;
	char			*data;
	char			*data_w;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			oldplane_x;
	double			plane_y;
	double			raypos_x;
	double			raypos_y;
	double			raydir_x;
	double			olddir_x;
	double			raydir_y;
	double			camera_x;
	double			camera_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	double			t;
	double			oldt;
	double			ft;
	double			movespeed;
	double			rotspeed;
	struct timeval	t1;
	struct timeval	t2;
	int				x;
	int				ctm;
	int				ctm_inv;
	int				ctm_hack;
	int				menu;
	int				hack;
	int				hit;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				l_h;
	int				fd;
	int				err;
	int				watch_north;
	int				watch_south;
	int				watch_west;
	int				watch_est;
	int				north_face;
	int				south_face;
	int				est_face;
	int				west_face;
	int				cf;
	int				draw_start;
	int				draw_end;
	int				obj;
	int				num;
	int				loose;
	int				num_hack1;
	int				num_hack2;
	int				num_hack3;
	int				num_hack4;
	int				obj_key;
	struct s_invt	inv;
	struct s_door	blue_d;
	struct s_door	green_d;
	struct s_door	red_d;
	struct s_door	pink_d;
	struct s_mess	mess;
	int				key_ig;
	int				ng;
}					t_mlx;

void				start_raycasting(t_mlx mlx);
void				draw_wolf3d(t_mlx mlx, int x);
void				draw_blue_d(t_mlx *mlx, int x);
void				draw_green_d(t_mlx *mlx, int x);
void				draw_pink_d(t_mlx *mlx, int x);
void				draw_red_d(t_mlx *mlx, int x);
void				draw_menu(t_mlx *mlx);
void				draw_control(t_mlx *mlx);
int					key_hook(int keycode, t_mlx *mlx);
int					map(int x, int y);
int					key_hack(int keycode, t_mlx *mlx);
void				open_door(t_mlx *mlx);
int					nbr_obj(t_mlx *mlx);
void				init_mlx(t_mlx *mlx);
int					expose_hook(t_mlx *mlx);
int					key_move(int keycode, t_mlx *mlx);
int					init_time(t_mlx *mlx);
int					check_door(t_mlx *mlx, int x, int y);
void				open_door(t_mlx *mlx);
void				draw_consol(t_mlx *mlx);
void				draw_inv(t_mlx *mlx);
void				draw_mess(t_mlx *mlx);
void				text_coord(t_mlx *mlx);
int					red_cross(t_mlx *mlx);
void				door_message(t_mlx *mlx, int door);
void				search_key(t_mlx *mlx, int x, int y);
int					search_door(double x, double y);
void				draw_orange_w(t_mlx *mlx, int x);
void				draw_blue_w(t_mlx *mlx, int x);
void				draw_green_w(t_mlx *mlx, int x);
void				draw_red_w(t_mlx *mlx, int x);
void				draw_pink_w(t_mlx *mlx, int x);
void				draw_end_wall(t_mlx *mlx, int x);
void				init_watch(t_mlx *mlx);
void				watch_pos(t_mlx *mlx);
void				key_w_t(t_mlx *mlx);
void				key_rot_t(t_mlx *mlx);
void				key_s_t(t_mlx *mlx);

#endif
