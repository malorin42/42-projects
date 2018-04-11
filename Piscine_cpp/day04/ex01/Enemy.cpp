/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:07:12 by malorin           #+#    #+#             */
/*   Updated: 2018/03/30 23:07:13 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Enemy.hpp"

Enemy::Enemy() : _type(""), _HP(0){

}

Enemy::Enemy(Enemy const & src) : _type(src._type), _HP(src._HP){

}

Enemy::Enemy(int hp, std::string const & type) : _type(type), _HP(hp){

}

Enemy::~Enemy(){

}

std::string  const &	Enemy::getType() const{
	return _type;
}

int 				Enemy::getHP() const{
	return _HP;
}

void 		Enemy::takeDamage(int damage){
	if (_HP > 0 && damage > 0)
	{
		if (_HP - damage <= 0)
			_HP = 0;
		else
			_HP -= damage;
	}
}

Enemy & 			Enemy::operator=(Enemy const & src) {
	if (this != &src)
	{
		_HP = src._HP;
	}
	return *this;
}