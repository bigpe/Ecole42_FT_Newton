/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collider.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/08 19:15:24 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/03/08 22:21:12 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLIDER_HPP
# define COLLIDER_HPP

# include "Object.hpp"

namespace Collider
{
	/* collide ground: plane at [0,0,0] with Y axis as normal */
	void	collide_floor(Object &obj, float g);
	void	collide_object(Object &obj1, Object &obj2);
}

#endif
