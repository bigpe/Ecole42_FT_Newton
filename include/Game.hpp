/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/09 19:10:11 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/03/08 23:15:10 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "General.hpp"	/* vec3 */
# include "Event.hpp"	/* Keys */
# include "Object.hpp"	/* Object */
# include <vector>

enum e_camera
{
	Unlocked,
	Locked
};

struct Game
{
	public :
		Game(void);
		virtual ~Game(void);

		void	init(void);
		void	update(float delta, const Keys &key);

		enum e_camera	camera_lock;
		vec3			pos;
		float			pos_locked;

		float			look_yaw;	/* applied before pitch */
		float			look_pitch;

		float			wind_speed;	/* wind speed in m/s */

		std::vector<Object>	obj;	/* Game objects */
		std::vector<Object>	debug;	/* Debug spheres */
		std::vector<Object>	sling;	/* catapult 3d model */


	private :
		void	_update_camera(float delta, const Keys &key);
		void	_throw_object(const Keys &key);
		void	_update_objects(float delta, const Keys &key);
};

#endif
