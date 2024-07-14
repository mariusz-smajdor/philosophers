/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:34:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/13 16:37:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	initiate_data(t_simulation *simulation, char **av)
{
	simulation->philo_count = process_input(av[0]);
	simulation->time_to_die = process_input(av[1]) * 1e3;
	simulation->time_to_eat = process_input(av[2]) * 1e3;
	simulation->time_to_sleep = process_input(av[3]) * 1e3;
	if (av[4])
		simulation->max_meals = process_input(av[4]);
	else
		simulation->max_meals = -1;
}