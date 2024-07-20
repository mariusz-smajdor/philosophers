/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
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
// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
// 5 800 200 200 4
static void	eat(t_philo *philo)
{
	t_sim	*sim;

	sim = philo->sim;
	pthread_mutex_lock(&philo->first_fork->mutex); // protect lock
	printf("%ld Philo %ld has taken a fork\n", get_timestamp(sim->start_time), philo->id);
	pthread_mutex_lock(&philo->second_fork->mutex); // protect lock
	printf("%ld Philo %ld has taken a fork\n", get_timestamp(sim->start_time), philo->id);
	printf("%ld Philo %ld is eating\n", get_timestamp(sim->start_time), philo->id);
	usleep(sim->time_to_eat * 5); // * 5 for testing
	pthread_mutex_unlock(&philo->first_fork->mutex); // protect unlock
	pthread_mutex_unlock(&philo->second_fork->mutex); // protect unlock
}

static void	nap(t_philo *philo)
{
	t_sim	*sim;

	sim = philo->sim;
	printf("%ld Philo %ld is sleeping\n", get_timestamp(sim->start_time), philo->id);
	usleep(philo->sim->time_to_sleep * 5); // * 5 for testing
}

static void	think(t_philo *philo)
{
	t_sim	*sim;

	sim = philo->sim;
	printf("%ld Philo %ld is thinking\n", get_timestamp(sim->start_time), philo->id);
}

static void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!philo->sim->ready)
		;
	while (1)
	{
		think(philo);
		eat(philo);
		nap(philo);
	}
	return (NULL);
}

void	start_sim(t_sim *sim)
{
	int	i;

	i = -1;
	while (++i < sim->philo_num)
	{
		if (pthread_create(&sim->philos[i].thread, NULL, philo_routine, &sim->philos[i]) != 0)
			error_exit("Thread creation failed!\n");
	}
	sim->ready = true;
	sim->start_time = get_current_time_in_millisec();
	i = -1;
	while (++i < sim->philo_num)
		pthread_join(sim->philos[i].thread, NULL); // protect join
}
