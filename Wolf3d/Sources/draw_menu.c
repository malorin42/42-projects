/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 19:39:51 by malorin           #+#    #+#             */
/*   Updated: 2016/10/06 19:39:54 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		draw_control(t_mlx *mlx)
{
	mlx_string_put(mlx->init, mlx->win, 500, 50, 0xFFF8C00, "Controls");
	mlx_string_put(mlx->init, mlx->win, 100, 100, 0xFFF8C00, "Avancer : ");
	mlx_string_put(mlx->init, mlx->win, 200, 100, 0xFFFFFFF, "z");
	mlx_string_put(mlx->init, mlx->win, 100, 150, 0xFFF8C00, "Reculer : ");
	mlx_string_put(mlx->init, mlx->win, 200, 150, 0xFFFFFFF, "s");
	mlx_string_put(mlx->init, mlx->win, 100, 200, 0xFFF8C00,
	"Strafe vers la droite : ");
	mlx_string_put(mlx->init, mlx->win, 340, 200, 0xFFFFFFF, "d");
	mlx_string_put(mlx->init, mlx->win, 100, 250, 0xFFF8C00,
	"Strafe vers la gauche : q");
	mlx_string_put(mlx->init, mlx->win, 340, 250, 0xFFFFFFF, "q");
	mlx_string_put(mlx->init, mlx->win, 100, 300, 0xFFF8C00,
	"Deplacement Camera : ");
	mlx_string_put(mlx->init, mlx->win, 310, 300, 0xFFFFFFF,
	"fleches directionnelles");
	mlx_string_put(mlx->init, mlx->win, 100, 350, 0xFFF8C00,
	"Voir les FPS : ");
	mlx_string_put(mlx->init, mlx->win, 250, 350, 0xFFFFFFF, "f");
	mlx_string_put(mlx->init, mlx->win, 100, 400, 0xFFF8C00,
	"Inventaire : ");
	mlx_string_put(mlx->init, mlx->win, 230, 400, 0xFFFFFFF, "i");
}

static void	check_file(t_mlx *mlx)
{
	if ((mlx->fd = open("images/Wolfenstein_3d.xpm", O_RDONLY)) > 0)
	{
		close(mlx->fd);
		mlx->img_w = mlx_xpm_file_to_image(mlx->win,
		"images/Wolfenstein_3d.xpm", &mlx->width_w, &mlx->height_w);
		mlx_put_image_to_window(mlx->init, mlx->win,
		mlx->img_w, mlx->width_w / 2, mlx->height_w / 2);
	}
	else
	{
		if (mlx->err == 1)
			ft_putendl("Warning - File error : Image not Found.");
		mlx->err = 0;
	}
	close(mlx->fd);
}

void		draw_menu(t_mlx *mlx)
{
	check_file(mlx);
	if (mlx->ctm == 0)
		mlx_string_put(mlx->init, mlx->win, 480, 250, 0xFFF8C00,
		"Nouvelle Partie");
	else
		mlx_string_put(mlx->init, mlx->win, 480, 250, 0xFFFFFFF,
		"Nouvelle Partie");
	if (mlx->ctm == 1 && mlx->ng == 1)
		mlx_string_put(mlx->init, mlx->win, 460, 300, 0xFFF8C00,
		"Reprendre la Partie");
	else if (mlx->ng == 0)
		mlx_string_put(mlx->init, mlx->win, 460, 300, 0xF393939,
		"Reprendre la Partie");
	else
		mlx_string_put(mlx->init, mlx->win, 460, 300, 0xFFFFFFF,
		"Reprendre la Partie");
	if (mlx->ctm == 2)
		mlx_string_put(mlx->init, mlx->win, 510, 350, 0xFFF8C00,
		"Control");
	else
		mlx_string_put(mlx->init, mlx->win, 510, 350, 0xFFFFFFF, "Control");
	mlx_string_put(mlx->init, mlx->win, 10, 670, 0xFFFFFFF,
	"Auteur  : Malorin");
	mlx_string_put(mlx->init, mlx->win, 10, 690, 0xFFFFFFF, "Version : 1.0");
}
