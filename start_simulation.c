/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:57:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/08 17:52:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	await_threads(void)
{
	// TODO
}

void	*philo_routine(t_philo *philo)
{
	// t_philo *philo;

	// philo = (t_philo *)philo;
	// await_threads(philo-); // TODO
	// while (1)
	// {
	// 	// TODO
	// }
}

void	start_simulation(t_simulation *simulation)
{
	short	i;

	if (simulation->min_meals == 0)
		return ;
	if (simulation->min_meals == 1)
	{
		// TODO
	}
	i = -1;
	while (++i < simulation->philos_number)
	{
		safe_thread(&simulation->philos[i], philo_routine, &simulation->philos[i], CREATE);
	}
}