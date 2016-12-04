#ifndef PARSING_H
# define PARSING_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct 		s_vect
{
	double			x;
	double			y;
	double			z;				
}					t_vect;

typedef struct 		s_sphere
{
 	t_vect			vec;
	double			r;
}					t_sphere;

typedef struct  	s_scene
{
	int				nbr_obj;
	t_tab 			*tab_s;
	t_tab			*tab_p;
	t_tab			*tab_l;
}					t_scene;

typedef struct 		s_pars
{
	int				fd;
	int				nbr_l;
	int				i;
	int				j;
	char			*txt;
	char			*line;
	char			*obj;
}					t_pars;

#endif
