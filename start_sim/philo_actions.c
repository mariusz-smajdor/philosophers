/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by msmajdor          #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

inline static long get_timestamp(long start_time)
{
	return (get_current_time_in_millisec() - start_time);
}

void	think(t_philo *philo, long start_time)
{
	printf("%ld Philo %ld is thinking\n", get_timestamp(start_time), philo->id);
}


void	eat(t_philo *philo, t_sim *sim)
{
	pthread_mutex_lock(&philo->first_fork->mutex); // protect lock
	printf("%ld Philo %ld has taken a fork\n", get_timestamp(sim->start_time), philo->id);
	pthread_mutex_lock(&philo->second_fork->mutex); // protect lock
	printf("%ld Philo %ld has taken a fork\n", get_timestamp(sim->start_time), philo->id);
	printf("%ld Philo %ld is eating\n", get_timestamp(sim->start_time), philo->id);
	usleep(sim->time_to_eat * 5); // * 5 for testing
	pthread_mutex_unlock(&philo->first_fork->mutex); // protect unlock
	pthread_mutex_unlock(&philo->second_fork->mutex); // protect unlock
}

void	nap(t_philo *philo, t_sim *sim)
{
	printf("%ld Philo %ld is sleeping\n", get_timestamp(sim->start_time), philo->id);
	usleep(philo->sim->time_to_sleep * 5); // * 5 for testing
}
