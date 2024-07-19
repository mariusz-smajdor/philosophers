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

static int	process_input(char *arg)
{
	long	res;

	res = 0;
	while (is_space(*arg))
		arg++;
	while (*arg == '+')
		arg++;
	if (!is_digit(*arg))
		error_exit("Every argument must be a positive number!");
	else
		while (is_digit(*arg))
			res = res * 10 + *arg++ - '0';
	if (res > INT_MAX)
		error_exit("Every argument must be less or equal to INT_MAX!");
	return (res);
}

static void	init_philos(t_sim *sim)
{
	int	i;
	t_philo	*philo;

	sim->philos = safe_malloc(sizeof(t_philo) * sim->philo_num);
	i = -1;
	while (++i < sim->philo_num)
	{
		philo = &sim->philos[i];
		philo->id = i + 1;
		philo->left_fork = &sim->forks[i];
		philo->right_fork = &sim->forks[(i + 1) % sim->philo_num];
		philo->sim = sim;
		if (pthread_mutex_init(&philo->mutex, NULL) != 0)
			error_exit("Mutex initialization failed!");
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
		if (pthread_mutex_init(&sim->forks[i].mutex, NULL) != 0)
			error_exit("Mutex initialization failed!");
	}
}

void	init_data(t_sim *sim, char **av)
{
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
}
