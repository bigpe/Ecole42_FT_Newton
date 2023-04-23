/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/01/04 11:22:50 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/04/19 20:25:10 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "All.hpp"

All	all;

static void	loop(void)
{
	all.event.update();
	all.game.update(all.time.delta / 1000000000.0f, all.event.key);
	all.disp.update(all.game);
	all.time.update();
}

int			main(void)
{
	all.init();

	while (1)
		loop();
	return (0);
}

