/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/06 22:15:08 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/04/10 22:15:01 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

# include "General.hpp"
# include <iostream>
# include <array>

/*
** 4x4 32 bit floating point matrix
*/
struct Matrix : public std::array<float, 16>
{
	public :
		Matrix(void);	/* set matrix as identity */
		Matrix(const Matrix &src);
		virtual ~Matrix(void);

		Matrix	&transpose(void);
		void	set_projection(float fov, float near, float far, float aspect);
		
		Matrix	&rotate(float x, float y, float z);
		Matrix	&translate(float x, float y, float z);
		Matrix	&scale(float x, float y, float z);
		
		Matrix	&rotate(const vec3 &rotation);
		Matrix	&rotate_euler(const vec3 &euler_vector);
		Matrix	&translate(const vec3 &translation);
		Matrix	&scale(const vec3 &scaling);

		Matrix	operator*(const Matrix &rhs) const;
		Matrix	operator*(float rhs) const;

	private :
		void	_rotate_x(float angle);
		void	_rotate_y(float angle);
		void	_rotate_z(float angle);
};

std::ostream	&operator<<(std::ostream &lhs, const Matrix &rhs);

#endif
