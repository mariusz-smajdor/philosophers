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

static void	*monitor(void *data)
{
	t_sim	*sim;
	t_philo *philo;
	int i;

	sim = (t_sim *)data;
	while (1)
	{
		i = -1;
		while (++i < sim->philo_num)
		{
			philo = &sim->philos[i];
			if (get_timestamp(philo->last_meal) >= sim->time_to_die)
			{
				printf("%ld Philo %ld died\n", get_timestamp(sim->start_time), philo->id);
				sim->over = true;
				return (NULL);
			}
		}
	}
}

static void await_philos(t_sim *sim)
{
	while (!sim->ready)
		;
}

static void	*philo_routine(void *data)
{
	t_philo	*philo;
	t_sim	*sim;

	philo = (t_philo *)data;
	sim = philo->sim;
	await_philos(sim);
	while (!sim->over)
	{
		think(philo, sim->start_time);
		eat(philo, sim);
		nap(philo, sim);
	}
	return (NULL);
}

void	start_sim(t_sim *sim)
{
	int	i;

	i = -1;
	while (++i < sim->philo_num)
		safe_thread(&sim->philos[i].thread, philo_routine, &sim->philos[i], CREATE);
	sim->ready = true;
	sim->start_time = get_current_time_in_millisec();
	safe_thread(&sim->monitor, monitor, sim, CREATE);
	i = -1;
	while (++i < sim->philo_num)
		safe_thread(&sim->philos[i].thread, NULL, NULL, JOIN);
	safe_thread(&sim->monitor, NULL, NULL, JOIN);
}
