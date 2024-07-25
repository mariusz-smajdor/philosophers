/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by msmajdor          #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void print_status(const char *msg, t_philo *philo, t_sim *sim)
{
	safe_mutex(&sim->mutex, LOCK);
	if (!sim->over)
		printf("%ld %ld %s\n", get_timestamp(sim->start_time), philo->id, msg);
	safe_mutex(&sim->mutex, UNLOCK);
}

static void	think(t_philo *philo, t_sim *sim)
{
	print_status("is thinking", philo, sim);
}

static void	nap(t_philo *philo, t_sim *sim)
{
	print_status("is sleeping", philo, sim);
	usleep(sim->time_to_sleep);
}

static void	eat(t_philo *philo, t_sim *sim)
{
	safe_mutex(&philo->first_fork->mutex, LOCK);
	print_status("has taken a fork", philo, sim);
	safe_mutex(&philo->second_fork->mutex, LOCK);
	print_status("has taken a fork", philo, sim);
	philo->is_eating = true;
	print_status("is eating", philo, sim);
	usleep(sim->time_to_eat);
	philo->is_eating = false;
	philo->last_meal = get_current_time_in_millisec();
    philo->meals++;
	safe_mutex(&philo->first_fork->mutex, UNLOCK);
	safe_mutex(&philo->second_fork->mutex, UNLOCK);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;
	t_sim	*sim;

	philo = (t_philo *)data;
	sim = philo->sim;
	while (!sim->ready)
		;
	while (!sim->over)
    {
		eat(philo, sim);
		nap(philo, sim);
		think(philo, sim);
    }
	return (NULL);
}
