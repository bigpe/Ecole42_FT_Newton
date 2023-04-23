/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   All.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/05 12:13:55 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/03/15 22:10:08 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "All.hpp"
#include "General.hpp"

All::All(void) { }
All::All(const All &) { }
All::~All(void) { }

void	All::init(void)
{
	this->disp.init();
	this->gl.init(this->disp.window);
	this->time.set_fps(BASE_FPS);
	this->game.init();
}

void	All::operator=(const All &) { }
