/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2022/02/10 23:22:53 by lrorscha         ###   ########.fr       */
/*   Updated: 2023/04/22 20:25:05 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_HPP
# define TIME_HPP

# include <iostream>	/* std::string */

# define MAX_SAMPLE_AVERAGE 1000

/*
** All times are in nanoseconds
*/
struct	Time
{
	public :
		Time(void);
		virtual ~Time(void);

		unsigned long	delta;

		std::string		fps_average(void);
		std::string		time_to_frame(void);
		void			set_average_sample(unsigned nb);
		void			set_fps(unsigned long fps);	/* fps cap, 0 for no cap */
		void			update(void);

		unsigned long	elapsed_frame(void);

		static void	nsleep(unsigned long nsec);

	protected:
	private:
		unsigned long	_min_delta;		/* min time delta */
		unsigned long	_pure_delta;	/* delta without sleep */
		unsigned long	_old_ts;

		unsigned long	_sample_average;
		unsigned long	_sample_current;
		unsigned long	_delta_sample[MAX_SAMPLE_AVERAGE];

		unsigned long	_elapsed_frame;

		static unsigned long	timestamp(void);

		Time(const Time &src);
		void	operator=(const Time &rhs);
};

std::ostream	&operator<<(std::ostream &lhs, const Time &vec);

#endif
