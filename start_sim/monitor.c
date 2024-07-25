/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by msmajdor          #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	check_starvation(t_sim *sim)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < sim->philo_num)
	{
		philo = &sim->philos[i];
		if (get_timestamp(philo->last_meal) >= (sim->time_to_die / 1e3)
			&& !philo->is_eating)
		{
			printf("%ld %ld died\n", get_timestamp(sim->start_time), philo->id);
			sim->over = true;
		}
		usleep(1000);
	}
}

void	*monitor(void *data)
{
	t_sim *sim;

	sim = (t_sim *)data;
	while (!sim->over)
	{
		check_starvation(sim);
	}
	return (NULL);
}
