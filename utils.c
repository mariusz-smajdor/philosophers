/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by msmajdor          #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp(long time)
{
	return (get_current_time_in_millisec() - time);
}

long	get_current_time_in_millisec()
{
	struct timeval	time;
	long			res;

	gettimeofday(&time, NULL);
	res = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (res);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}
