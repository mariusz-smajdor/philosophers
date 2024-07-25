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

// void	think(t_philo *philo, long start_time);
// void	eat(t_philo *philo, t_sim *sim);
// void	nap(t_philo *philo, t_sim *sim);

// increase the number of meals eaten by the philosopher
// add is_eating



static void	nap(t_philo *philo, t_sim *sim)
{
    printf("%ld %ld is sleeping\n", get_timestamp(sim->start_time), philo->id);
    usleep(sim->time_to_sleep);
}

static void	eat(t_philo *philo, t_sim *sim)
{
	safe_mutex(&philo->first_fork->mutex, LOCK);
	printf("%ld %ld has taken a fork\n", get_timestamp(sim->start_time), philo->id);
	safe_mutex(&philo->second_fork->mutex, LOCK);
	printf("%ld %ld has taken a fork\n", get_timestamp(sim->start_time), philo->id);
	philo->is_eating = true;
	printf("%ld %ld is eating\n", get_timestamp(sim->start_time), philo->id);
	usleep(sim->time_to_eat);
	philo->is_eating = false;
	philo->last_meal = get_current_time_in_millisec();
    philo->meals++;
	safe_mutex(&philo->first_fork->mutex, UNLOCK);
	safe_mutex(&philo->second_fork->mutex, UNLOCK);
}

static void await_philos(t_sim *sim)
{
	while (!sim->ready)
		;
}

void	*philo_routine(void *data)
{
	t_philo	*philo;
	t_sim	*sim;

	philo = (t_philo *)data;
	sim = philo->sim;
	await_philos(sim);
	while (!sim->over)
    {
		eat(philo, sim);
		nap(philo, sim);
    }
	return (NULL);
}
