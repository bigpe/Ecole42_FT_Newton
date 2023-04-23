/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Event.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/07 14:25:15 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/04/07 18:21:44 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HPP
# define EVENT_HPP

# include "SDL.h"

struct Keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	lshift;
	bool	space;

	bool	mouse_right;
	int		mouse_x;		/* only when rmb pressed if mouse_middle = 1 */
	int		mouse_y;
	int		mouse_scroll;

	bool	mouse_middle;	/* toggle, 1 for Locked 0 for Unlocked */

	/* object throw */
	bool		object_thrown;
	bool		object_type;	/* 0 for Cube, 1 for Sphere */
	bool		object_auto;	/* fire every frame */

	unsigned	object_number;	/* for shotgun */
	float		object_speed;
	float		object_mass;
	float		object_size;

	float		wind_speed;

	float		max_distance;	/* objects beyound this will be removed */
	float		time_speed;
	float		gravity;

	bool		debug_display;
	bool		debug_impact;	/* display impacts and rotations */

	bool		init_pile;		/* add pile of spheres */
	bool		init_pool;		/* add bowl pool */
	bool		init_tower;		/* add cube tower */
	bool		reset_all;		/* remove all objects */
};

/*
** Interface to event library, with currently pressed keys
*/
struct Event
{
	public :
		Event(void);
		virtual ~Event(void);

		Keys	key;

		void	update(void);

	protected:
	private:
		void	_keychange(SDL_Keycode kc, bool key_state);
		void	_mousechange(Uint8 button, bool button_state);

		Event(const Event &src);
};

#endif
