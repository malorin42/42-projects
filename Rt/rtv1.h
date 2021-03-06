#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"

// # define WIDTH 1280
// # define HEIGHT 720

typedef struct	s_double3
{
	double		x;
	double		y;
	double		z;
}				t_double3;

typedef struct	s_plane
{
	t_double3	pos;
}				t_plane;

typedef struct	s_sphere
{
	t_double3	pos;
	double		radius;
	// t_color		color;
}				t_sphere;

typedef struct	s_env
{
	// void		*mlx;
	// void		*win;
	// t_image		*img;
	t_tab		*sphere;
	t_tab		*plane;
	// int			render;
}				t_env;

void			ft_load_file(int fd, t_env *env);

#endif