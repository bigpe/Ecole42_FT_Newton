/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   General.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/08 22:15:33 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/04/10 10:21:41 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include <array>

# define OPENGL_VERSION_MAJOR	4
# define OPENGL_VERSION_MINOR	1

# define WIN_TITLE		"BoWlz' sim"
# define WIN_SIZEX		1920
# define WIN_SIZEY		1080
# define WIN_POSX		100
# define WIN_POSY		50

# define BASE_FPS				60		/* 0 for unlimited */

# define MOUSE_SENSITIVITY_X	200		/* 1 = 100000 pixels/radian locked camera */
# define MOUSE_SENSITIVITY_Y	200
# define SCROLL_SENSITIVITY		300		/* 1 = 1000 scroll unit/meter */

# define LOOK_CAP_PITCH			1.55f	/* in radian */
# define LOOK_CAP_PITCH_LOCK	0.02f
# define POS_CAP_Y				0.1f	/* in m */
# define CAMERA_SPEED			15.5f	/* in m/s */

# define MAX_DELTA				0.03f	/* maximum allowed frame duration */
# define INELASTIC_SPEED		1.5f	/* ground inelastic threshold */
# define ELASTIC_SPEED			1.0f	/* object elastic threshold */
# define COEFF_OF_RESTITUTION	0.7f
# define COEFF_OF_FRICTION		0.05f	/* speed decrease over a single frame */

# define DEFAULT_OBJ_SPEED	20.0f
# define DEFAULT_OBJ_MASS	10.0f
# define DEFAULT_OBJ_SIZE	1.0f
# define DEFAULT_OBJ_NB		1
# define DEFAULT_GRAVITY	9.80665f
# define DEFAULT_MAX_DIST	500.0f	/* value for inc/dec, default is +inf */
# define DEFAULT_TIME		1.0f
# define DEFAULT_WIND_SPEED	50.0f

# define BASE_CX			0.5f	/* subsonic drag coefficient */
# define AIR_DENSITY		1.22f	/* air density at sea level in kg/m^3 */
# define AIR_TEMPERATURE	293.15f	/* temperature at sea level in kelvins */
# define MAX_DRAG_FRAME		0.1f	/* minimum final_mult value */

typedef std::array<float, 3>	vec3;

std::ostream	&operator<<(std::ostream &lhs, const vec3 &rhs);
vec3			&operator+=(vec3 &lhs, const vec3 &rhs);
vec3			&operator-=(vec3 &lhs, const vec3 &rhs);
vec3			&operator*=(vec3 &lhs, float rhs);
float			operator*(const vec3 &lhs, const vec3 &rhs);

vec3			operator*(const vec3 &lhs, float rhs);
vec3			operator/(const vec3 &lhs, float rhs);
vec3			operator-(const vec3 &lhs, const vec3 &rhs);
vec3			operator+(const vec3 &lhs, const vec3 &rhs);

vec3			vec3_cross_product(const vec3 &lhs, const vec3 &rhs);
float			vec3_length(const vec3 &vec);
vec3			&vec3_normalize(vec3 &vec);

void			vec3_rotate(vec3 &vec, float x, float y, float z);
void			vec3_rotate(vec3 &vec, const vec3 &rotation);
void			vec3_rotate_euler(vec3 &vec, const vec3 &euler_vector);
void			vec3_rotate_inverse(vec3 &vec, const vec3 &rotation);

#endif
