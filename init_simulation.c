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

static void init_philos(t_simulation *simulation)
{
	t_philo	*philo;
	short	i;

	i = -1;
	while (++i < simulation->philos_number)
	{
		philo = &simulation->philos[i];
		philo->id = i + 1;
		philo->meals = 0;
		philo->is_full = false;
		philo->simulation = simulation;
		assign_forks(philo, simulation->forks, simulation->philos_number, i);
	}
}

static void	init_forks(t_simulation *simulation)
{
	short	i;

	i = -1;
	while (++i < simulation->philos_number)
	{
		simulation->forks[i].id = i;
		safe_mutex(simulation->forks[i].mutex, INIT);
	}
}

void	init_simulation(t_simulation *simulation, char **args)
{
	simulation->philos_number = process_arg(args[0]);
	simulation->starve_time = process_arg(args[1]);
	simulation->eat_time = process_arg(args[2]) * 1e3; 
	simulation->sleep_time = process_arg(args[3]) * 1e3;
	simulation->min_meals = process_arg(args[4]) * 1e3;
	if (simulation->starve_time <= simulation->eat_time + simulation->sleep_time)
		error_exit("Starve time must be greater than eat and sleep time!");
	if (simulation->starve_time < 6e4
		|| simulation->eat_time < 6e4
		|| simulation->sleep_time < 6e4)
		error_exit("Time must be greater than 60ms!");
	if (args[5])
		simulation->min_meals = process_arg(args[5]);
	else
		simulation->min_meals = -1;
	simulation->simulation_end = false;
	simulation->simulation_ready = false;
	simulation->philos = safe_malloc(sizeof(t_philo) * simulation->philos_number);
	simulation->forks = safe_malloc(sizeof(t_fork) * simulation->philos_number);
	init_forks(simulation); 
	init_philos(simulation);
}