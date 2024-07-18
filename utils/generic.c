/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:34:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/17 21:37:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	super_usleep(long sec, t_simulation *simulation)
{
	long	start_time;
	long	passed_time;
	long	left_time;

	start_time = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start_time < sec)
	{
		if (simulation->simulation_over)
			break ;
		passed_time = get_time(MICROSECOND) - start_time;
		left_time = sec - passed_time;

		if (left_time > 1000)
			usleep(left_time / 2);
		else
			while (get_time(MICROSECOND) - start_time < sec)
				;
	}
}

long	get_time(t_time_unit unit)
{
	struct timeval	time;
	long			timestamp;

	if (gettimeofday(&time, NULL) != 0)
		error_exit("Failed to get time!");
	timestamp = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (unit == SECOND)
		return (timestamp / 1000);
	if (unit == MILLISECOND)
		return (timestamp);
	if (unit == MICROSECOND)
		return (timestamp * 1000);
	if (!(unit >= SECOND && unit <= MICROSECOND))
		error_exit("Invalid time unit!");
	return (0);
}

void	error_exit(const char *msg)
{
	printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}
