/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by msmajdor          #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_data(t_sim *sim)
{
	int	i;

	i = -1;
	while (++i < sim->philo_num)
	{
		pthread_mutex_destroy(&sim->philos[i].first_fork->mutex);
		pthread_mutex_destroy(&sim->philos[i].second_fork->mutex);
	}
	pthread_mutex_destroy(&sim->mutex);
	free(sim->philos);
	free(sim->forks);
}
