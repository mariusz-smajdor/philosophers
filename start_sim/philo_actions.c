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

void	think(t_philo *philo, long start_time)
{
	printf("%ld Philo %ld is thinking\n", get_timestamp(start_time), philo->id);
}

void	eat(t_philo *philo, t_sim *sim)
{
	safe_mutex(&philo->first_fork->mutex, LOCK);
	printf("%ld Philo %ld has taken a fork\n", get_timestamp(sim->start_time), philo->id);
	safe_mutex(&philo->second_fork->mutex, LOCK);
	printf("%ld Philo %ld has taken a fork\n", get_timestamp(sim->start_time), philo->id);
	printf("%ld Philo %ld is eating\n", get_timestamp(sim->start_time), philo->id);
	usleep(sim->time_to_eat);
	safe_mutex(&philo->first_fork->mutex, UNLOCK);
	safe_mutex(&philo->second_fork->mutex, UNLOCK);
}

void	nap(t_philo *philo, t_sim *sim)
{
	printf("%ld Philo %ld is sleeping\n", get_timestamp(sim->start_time), philo->id);
	usleep(philo->sim->time_to_sleep);
}
