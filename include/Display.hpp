/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/08 19:15:24 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/03/08 22:21:12 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include "Game.hpp"	/* Game */
# include "SDL.h"		/* SDL_Window */

/*
** Interface to the graphic library
*/
struct Display
{
	public :
		Display(void);
		virtual ~Display(void);

		SDL_Window	*window;

		unsigned	res_x;
		unsigned	res_y;

		void		init(void);
		void		update(const Game &game);

	protected:
	private:
		Display(const Display &);
};

#endif
