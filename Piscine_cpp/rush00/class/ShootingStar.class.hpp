/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShootingStar.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:25:03 by malorin           #+#    #+#             */
/*   Updated: 2018/04/01 21:25:04 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOTINGSTAR_CLASS_HPP
# define SHOOTINGSTAR_CLASS_HPP

#include "GameEntities.class.hpp"

class ShootingStar : public GameEntities
{
public:
	ShootingStar();
	ShootingStar(Game *game);
	virtual ~ShootingStar();
	virtual ShootingStar 	& operator=(ShootingStar const & rhs);

	virtual void			update();
	virtual int		ft_z(void);
	int				getPosX();
	int				getPosY();
	void			setPosX(int newpos);
	void			setPosY(int newpos);
	void			draw(WINDOW *win);

	int				i;
	std::string		c;
private:
	int				_posX;
	int				_posY;
};

#endif
