/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/25 20:03:07 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	process_input(char *arg)
{
	long	res;

	res = 0;
	while (is_space(*arg))
		arg++;
	while (*arg == '+')
		arg++;
	while (is_digit(*arg))
		res = res * 10 + *arg++ - '0';
	return (res);
}

static void	assign_forks(t_sim *sim, t_philo *philo, int pos)
{
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &sim->forks[pos];
		philo->second_fork = &sim->forks[(pos + 1) % sim->philo_num];
	}
	else
	{
		philo->first_fork = &sim->forks[(pos + 1) % sim->philo_num];
		philo->second_fork = &sim->forks[pos];
	}
}

static void	init_philos(t_sim *sim)
{
	int		i;
	t_philo	*philo;

	sim->philos = safe_malloc(sizeof(t_philo) * sim->philo_num);
	i = -1;
	while (++i < sim->philo_num)
	{
		philo = &sim->philos[i];
		philo->id = i + 1;
		philo->sim = sim;
		philo->is_eating = false;
		philo->meals = 0;
		assign_forks(sim, philo, i);
		pthread_mutex_init(&philo->mutex, NULL);
	}
}

static void	init_forks(t_sim *sim)
{
	int	i;

	sim->forks = safe_malloc(sizeof(t_fork) * sim->philo_num);
	i = -1;
	while (++i < sim->philo_num)
	{
		sim->forks[i].id = i;
		pthread_mutex_init(&sim->forks[i].mutex, NULL);
	}
}

void	init_data(t_sim *sim, char **av)
{
	sim->over = false;
	sim->ready = false;
	sim->philo_num = process_input(av[0]);
	sim->time_to_die = process_input(av[1]) * 1e3;
	sim->time_to_eat = process_input(av[2]) * 1e3;
	sim->time_to_sleep = process_input(av[3]) * 1e3;
	if (av[4])
		sim->max_meals = process_input(av[4]);
	else
		sim->max_meals = -1;
	init_forks(sim);
	init_philos(sim);
	pthread_mutex_init(&sim->mutex, NULL);
}
