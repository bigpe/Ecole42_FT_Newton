/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Line.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/13 19:14:12 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/03/10 21:21:54 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_HPP
# define LINE_HPP

# include "General.hpp"	/* vec3 */
# include <iostream>	/* ostream */

class Line
{
	public :
		Line(void);
		Line(const vec3 &p1, const vec3 &p2);
		Line(const Line &src);
		virtual ~Line(void);

		vec3	origin;
		vec3	dir;
		float	length;

		Line	&operator=(const Line &rhs);

	protected:
	private:
};

std::ostream	&operator<<(std::ostream &lhs, const Line &rhs);

#endif
