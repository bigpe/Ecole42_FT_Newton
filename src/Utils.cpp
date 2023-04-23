/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/10 23:02:43 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/04/20 20:26:15 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include <iostream>		/* cerr, string */
#include <fstream>		/* ifstream */
#include <sstream>		/* stringstream */
#include <cstdlib>		/* exit */
#include <cmath>		/* round */


namespace Utils
{
	void		error_quit(const std::string &str)
	{
		std::cerr << str << std::endl;
		exit(0);
	}

	std::string	read_file(const char *filename)
	{
		std::ifstream		fs;
		std::stringstream	ss;

		fs.open(filename);
		if (!fs.is_open())
			error_quit("Cannot open source file");
		ss << fs.rdbuf();
		return (ss.str());
	}

	float		round(float f, int decimal)
	{
		float	n;

		n = (float)std::pow(10.0f, decimal);
		return (std::round(f * n) / n);
	}

	float		square(float f)
	{
		return (f * f);
	}

	float		max3(const std::array<float, 3>	&vec)
	{
		if (vec[0] >= vec[1] && vec[0] >= vec[2])
			return (vec[0]);
		if (vec[1] >= vec[0] && vec[1] >= vec[2])
			return (vec[1]);
		return (vec[2]);
	}

	unsigned	max3_id(const std::array<float, 3>	&vec)
	{
		if (vec[0] >= vec[1] && vec[0] >= vec[2])
			return (0);
		if (vec[1] >= vec[0] && vec[1] >= vec[2])
			return (1);
		return (2);
	}

	void		float_cap(float &f, float min, float max)
	{
		if (f < min)
			f = min;
		if (f > max)
			f = max;
	}

	void		unsigned_cap(unsigned &n, unsigned min, unsigned max)
	{
		if (n < min)
			n = min;
		if (n > max)
			n = max;
	}

	void		add_sphere(std::vector<Object> &list, vec3 position, float
		diameter)
	{
		Object	tmp;

		tmp.type = Sphere;
		tmp.position = position;
		tmp.dimension = {0, 0, 0};
		tmp.angular_position = {0, 0, 0};
		tmp.mass = 1.0f;
		tmp.angular_velocity = {0, 0, 0};
		tmp.velocity = {0, 0, 0};
		tmp.radius = diameter / 2.0f;
		list.push_back(tmp);
	}

	void		debug_draw_line(std::vector<Object> &list, const Line &line)
	{
		for (unsigned i = 0; i <= 100; ++i)
			add_sphere(list, line.origin + line.dir * line.length * i / 100.0f,
				0.15f);
	}
}
