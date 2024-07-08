/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:55:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/07 18:56:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static ulong	process_arg(char *arg)
{
	ulong	num;
	short	i;

	while (is_space(*arg))
		arg++;
	while (*arg == '+')
		arg++;
	if (!is_digit(*arg))
		error_exit("Argument is not a valid number!");
	num = 0;
	i = -1;
	while (++i, is_digit(*arg))
		num = num * 10 + (*arg++ - '0');
	if (num > INT_MAX || i > 10)
		error_exit("Argument number cannot be greater than INT_MAX!");
	return (num);
}

static void	assign_forks(t_philo *philo, t_fork *forks, short philos_num, short pos)
{
	philo->left = &forks[(pos + 1) % philos_num];
	philo->right = &forks[pos];
	if (philo->id % 2 == 0)
	{
		philo->left = &forks[pos];
		philo->right = &forks[(pos + 1) % philos_num];
	}
}

static void init_philosophers(t_philos *philos, int philos_num)
{
	t_philo	*philo;
	short	i;

	i = -1;
	while (++i < philos_num)
	{
		philo = &philos->philosophers[i];
		philo->id = i + 1;
		philo->meals = 0;
		philo->is_full = false;
		assign_forks(philo, philos->forks, philos_num, i);
	}
}

static void	init_forks(t_fork *forks, int philos_num)
{
	short	i;

	i = -1;
	while (++i < philos_num)
	{
		forks[i].id = i;
		safe_mutex(forks[i].mutex, INIT);
	}
}

void	init_philos(t_philos *philos, char **args)
{
	ushort	philos_num;

	philos_num = process_arg(args[0]);
	philos->starve_time = process_arg(args[1]);
	philos->eat_time = process_arg(args[2]) * 1e3; 
	philos->sleep_time = process_arg(args[3]) * 1e3;
	philos->min_meals = process_arg(args[4]) * 1e3;
	if (philos->starve_time <= philos->eat_time + philos->sleep_time)
		error_exit("Starve time must be greater than eat and sleep time!");
	if (philos->starve_time < 6e4
		|| philos->eat_time < 6e4
		|| philos->sleep_time < 6e4)
		error_exit("Time must be greater than 60ms!");
	if (args[5])
		philos->min_meals = process_arg(args[5]);
	else
		philos->min_meals = -1;
	philos->simulation_end = false;
	philos->philosophers = safe_malloc(sizeof(t_philo) * philos_num);
	philos->forks = safe_malloc(sizeof(t_fork) * philos_num);
	init_forks(philos->forks, philos_num); 
	init_philosophers(philos, philos_num);
}