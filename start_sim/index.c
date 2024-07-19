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

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->mutex); // protect lock
	printf("Philo %ld has taken a fork\n", philo->id);
	pthread_mutex_lock(&philo->second_fork->mutex); // protect lock
	printf("Philo %ld has taken a fork\n", philo->id);
	printf("Philo %ld is eating\n", philo->id);
	usleep(5000000);
	pthread_mutex_unlock(&philo->first_fork->mutex); // protect unlock
	pthread_mutex_unlock(&philo->second_fork->mutex); // protect unlock
}

static void	think(t_philo *philo)
{
	printf("Philo %ld is thinking\n", philo->id);
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
	i = -1;
	while (++i < sim->philo_num)
		pthread_join(sim->philos[i].thread, NULL); // protect join
}
