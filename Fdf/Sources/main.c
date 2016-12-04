/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 14:59:48 by malorin           #+#    #+#             */
/*   Updated: 2016/04/05 14:59:53 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			main(int av, char **ac)
{
	if (av != 2)
		return (0);
	ft_putendl("Commandes :");
	ft_putendl("- Fleches Directionnelles pour déplacer la map.");
	ft_putendl("- Zoomer : PavNum '+'");
	ft_putendl("-Dezoomer : PavNum '-'");
	ft_putendl("Choix des couleurs :");
	ft_putendl("	PavNum '1' : RGB");
	ft_putendl("	PavNum '2' : Terrestre");
	ft_putendl("	PavNum '3' : Moon");
	ft_putendl("	PavNum '4' : Marin");
	search_size(ac);
	return (0);
}
