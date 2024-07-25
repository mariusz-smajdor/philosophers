/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/25 20:03:56 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	update_sim_data(t_sim *sim)
{
	int	i;

	i = -1;
	sim->start_time = get_current_time_in_millisec();
	while (++i < sim->philo_num)
		sim->philos[i].last_meal = sim->start_time;
	sim->ready = true;
}

void	start_sim(t_sim *sim)
{
	int	i;

	i = -1;
	if (sim->max_meals == 0)
		return ;
	while (++i < sim->philo_num)
		pthread_create(&sim->philos[i].thread, NULL,
			philo_routine, &sim->philos[i]);
	update_sim_data(sim);
	pthread_create(&sim->monitor, NULL, monitor, sim);
	i = -1;
	while (++i < sim->philo_num)
		pthread_join(sim->philos[i].thread, NULL);
	pthread_join(sim->monitor, NULL);
}
