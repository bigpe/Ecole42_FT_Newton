/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/01 14:15:05 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/04/10 13:22:33 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>	/* std::string */
# include <array>		/* std::array */
# include "Matrix.hpp"	/* Matrix */
# include "Object.hpp"	/* Object */
# include "Line.hpp"	/* Line */
# include <vector>		/* vector */

namespace Utils
{
	void		error_quit(const std::string &str);
	std::string	read_file(const char *filename);
	float		round(float f, int decimal);
	float		square(float f);
	float		max3(const std::array<float, 3>	&vec);
	unsigned	max3_id(const std::array<float, 3>	&vec);
	void		float_cap(float &f, float min, float max);
	void		unsigned_cap(unsigned &n, unsigned min, unsigned max);
	void		add_sphere(std::vector<Object> &list, vec3 position, float
		diameter);
	void		debug_draw_line(std::vector<Object> &list, const Line &line);
}

#endif
