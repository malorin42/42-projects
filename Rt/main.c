#include "../libft/libft.h"
#include "parsing.h"

int			size_line(t_pars pars, int i)
{
	int 	size;

	size = 0;
	while (pars.txt[i] != '\n')
	{
		size++;
		i++;
	}
	return (size);
}

int			ft_get_num(t_pars *pars, int start)
{
	t_buff	*buff;
	char	tmp[50];
	int 	i;

	i = 0;
	buff = (t_buff*)malloc(sizeof(t_buff));
	while (pars->line[start] != '\0')
	{
		tmp[i] = pars->line[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	buff->data = tmp;
	buff->i = 0;
	buff->length = ft_strlen(tmp);
	return (ft_parse_double(buff));
}

void		add_sphere_value(t_pars *pars)
{
	if (pars->nbr_l == 4)
		pars->sphere_p->vec.x = ft_get_num(pars, 4);
	else if (pars->nbr_l == 3)
		pars->sphere_p->vec.y = ft_get_num(pars, 4);
	else if (pars->nbr_l == 2)
		pars->sphere_p->vec.z = ft_get_num(pars, 4);
	else
		pars->sphere_p->r = ft_get_num(pars, 4);
}

void		pars_value(t_pars *pars)
{
	if (ft_strcmp(pars->obj, "sphere") == 0)
		add_sphere_value(pars);
/*	if (ft_strcmp(pars->obj, "plane") == 0)
		add_plane_value(pars);
	if (ft_strcmp(pars->obj, "spotlight") == 0)
		add_spotlight_value(pars);*/
}

void		pars_obj(t_pars *pars)
{
	pars->j = 0;
	while (pars->txt[pars->i] != '#' && pars->txt[pars->i] != '&')
	{
		pars->line = (char*)malloc(sizeof(char) * size_line(*pars, pars->i));
		while (pars->txt[pars->i] != '\n')
		{
			pars->line[pars->j] = pars->txt[pars->i];
			pars->j++;
			pars->i++;
		}
		if (pars->nbr_l > 0)
			pars_value(pars);
		pars->i++;
		pars->j = 0;
		pars->nbr_l--;
	}
}

void		pars_scn(t_pars *pars, t_scene *scn)
{
	if (ft_strcmp(pars->obj, "sphere") == 0)
	{
		pars_obj(pars);
		ft_tab_add(scn->tab_s, pars->sphere_p);
	}
/*	if (ft_strcmp(pars->obj, "plane") == 0)
	{
		pars_obj(pars);
		ft_tab_add(scn->tab_p, pars->plane);
	}*/
}

int			read_line(t_pars *pars, t_scene *scn)
{	
	if (ft_strcmp(pars->line, "sphere") == 0)
	{
		scn->nbr_obj++;
		pars->nbr_l = 4;
		pars->obj = "sphere";
		pars->i += 2;
		return(1);
	}
	return(0);
}

void		start_parsing(t_pars *pars, t_scene *scn)
{
	while (pars->txt[pars->i] != '&')
	{
		pars->line = (char*)malloc(sizeof(char) * size_line(*pars, pars->i));
		while (pars->txt[pars->i] != '\n' && pars->txt[pars->i] != '&')
		{
			pars->line[pars->j] = pars->txt[pars->i];
			pars->j++;
			pars->i++;
		}
		if (read_line(pars, scn) == 1)
			pars_scn(pars, scn);
		pars->i++;
	}
}

void		init_parsing(t_pars *pars)
{
	t_sphere		*sphere;
	t_vect			*vec;

	sphere = (t_sphere*)malloc(sizeof(t_sphere*));
	vec = (t_vect*)malloc(sizeof(t_vect));
	pars->sphere_p = sphere;
	pars->sphere_p->vec = *vec;
	pars->nbr_l = 0;
	pars->i = 0;
	pars->j = 0;
}

void		init_scene(t_scene *scn)
{
	scn->nbr_obj = 0;
	scn->tab_s = ft_tab_new(sizeof(t_sphere*));
}

void		read_scene(char *ac, t_pars *pars, t_scene *scn)
{
	pars->fd = open(ac, O_RDONLY);
	init_parsing(pars);
	init_scene(scn);
	while (get_next_line(pars->fd, &pars->line) > 0)
	{
		if (read_line(pars, scn) == 1)
			pars_scn(pars, scn);
	}
}

int			main(int av, char **ac)
{
	t_pars		*pars;
	t_scene		*scn;
	t_sphere	*tmp;
	
	if (av != 2)
	{
		ft_putendl("ERROR : wrong number of Argument");
		return (0);
	}
	pars = (t_pars*)malloc(sizeof(t_pars));
	scn = (t_scene*)malloc(sizeof(t_scene));
	tmp = (t_sphere*)malloc(sizeof(t_sphere));
	read_scene(ac[1], pars, scn);
	ft_putstr("sphere xc : ");
	tmp = TG(t_sphere*, scn->tab_s, 0);
	return (0);
}