/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   All.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/08 14:38:15 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/04/07 20:21:31 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_HPP
# define ALL_HPP

# include "General.hpp"
# include "Display.hpp"
# include "Event.hpp"
# include "Time.hpp"
# include "OpenGL.hpp"
# include "Game.hpp"

struct All
{
	public :
		Time	time;
		Display	disp;
		Event	event;
		OpenGL	gl;
		Game	game;

		All(void);
		virtual ~All(void);

		void	init(void);

	protected:
	private:
		All(const All &);
		void	operator=(const All &);
};

extern All	all;

#endif
