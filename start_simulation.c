/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:34:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/15 20:37:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*dinner_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
    while (!get_bool(&simulation->mutex, &simulation->philos_ready))
		;
	return (NULL);
}

void	start_simulation(t_simulation *simulation)
{
    int i;

    i = -1;
    while (++i < simulation->philo_count)
        safe_thread(&simulation->philos[i].thread, dinner_routine, &simulation->philos[i], CREATE);
    set_bool(&simulation->mutex, &simulation->philos_ready, true);
}
