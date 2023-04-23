/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/05 22:13:22 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/04/08 12:18:55 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_HPP
# define OBJECT_HPP

# include "General.hpp"
# include "Line.hpp"
# include <array>

enum	e_type
{
	Cube,
	Sphere
};

class Object
{
	public :
		Object(void);
		Object(const Object &src);
		virtual ~Object(void);

		Object	&operator=(const Object &rhs);	/* REMEMBER TO UPDATE */

		enum e_type	type;
		vec3		position;
		vec3		velocity;
		float		mass;

		vec3		angular_position;	/* for cubes */
		vec3		angular_velocity;	/* for cubes */
		vec3		dimension;			/* for cubes */
		float		radius;				/* for all */

		/* for physical engine */
		bool					rest;		/* is rested on ground */
		std::array<vec3, 8>		points;		/* points of cube */
		std::array<Line, 12>	edges;		/* edges of cube */
		std::array<vec3, 3>		normals;	/* normals of all cube faces */

		void	compute_points(void);
};

#endif
