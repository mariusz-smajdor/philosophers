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
		safe_thread(&sim->philos[i].thread, philo_routine, &sim->philos[i], CREATE);
	update_sim_data(sim);
	safe_thread(&sim->monitor, monitor, sim, CREATE);
	i = -1;
	while (++i < sim->philo_num)
		safe_thread(&sim->philos[i].thread, NULL, NULL, JOIN);
}
