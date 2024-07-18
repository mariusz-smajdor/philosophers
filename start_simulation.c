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

static void	print_status(t_status status, t_philo *philo)
{
	long	time_passed;

	if (philo->meals_count == philo->simulation->max_meals)
		return ;
	time_passed = get_time(MILLISECOND) - philo->simulation->start_time;
	safe_mutex(&philo->simulation->print_mutex, LOCK);
	if (status == TAKEN_FORK && !get_bool(&philo->simulation->mutex, &philo->simulation->simulation_over))
		printf("%-6ld %ld has taken a fork\n", time_passed, philo->id);
	if (status == EATING && !get_bool(&philo->simulation->mutex, &philo->simulation->simulation_over))
		printf("%-6ld %ld is eating\n", time_passed, philo->id);
	if (status == SLEEPING && !get_bool(&philo->simulation->mutex, &philo->simulation->simulation_over))
		printf("%-6ld %ld is sleeping\n", time_passed, philo->id);
	if (status == THINKING && !get_bool(&philo->simulation->mutex, &philo->simulation->simulation_over))
		printf("%-6ld %ld is thinking\n", time_passed, philo->id);
	if (status == DIED && !get_bool(&philo->simulation->mutex, &philo->simulation->simulation_over))
	 	printf("%-6ld %ld died\n", time_passed, philo->id);
	safe_mutex(&philo->simulation->print_mutex, UNLOCK);
}

static void eat(t_philo *philo)
{
	printf("123");
	safe_mutex(&philo->left_fork->mutex, LOCK);
	print_status(TAKEN_FORK, philo);
	safe_mutex(&philo->right_fork->mutex, LOCK);
	print_status(TAKEN_FORK, philo);
	set_long(&philo->mutex, &philo->last_meal, get_time(MILLISECOND));
	philo->meals_count++;
	print_status(EATING, philo);
	super_usleep(philo->simulation->time_to_eat, philo->simulation);
	safe_mutex(&philo->left_fork->mutex, UNLOCK);
	safe_mutex(&philo->right_fork->mutex, UNLOCK);
}

static void	*dinner_routine(void *data)
{
	t_philo			*philo;
	t_simulation	*simulation;

	philo = (t_philo *)data;
	simulation = philo->simulation;
	while (!get_bool(&simulation->mutex, &simulation->philos_ready))
		;
	while (!get_bool(&simulation->mutex, &simulation->simulation_over))
	{
		printf("45");
		if (philo->full)
			break ;
		eat(philo);
		//sleeping
		print_status(SLEEPING, philo);
		super_usleep(simulation->time_to_sleep, simulation);
		// think(philo);
	}
	return (NULL);
}

void	start_simulation(t_simulation *simulation)
{
	int	i;

	i = -1;
	while (++i < simulation->philo_count)
		safe_thread(&simulation->philos[i].thread, &dinner_routine, &simulation->philos[i], CREATE);
	simulation->start_time = get_time(MILLISECOND);
	set_bool(&simulation->mutex, &simulation->philos_ready, true);
	i = -1;
	while (++i < simulation->philo_count)
		safe_thread(&simulation->philos[i].thread, NULL, NULL, JOIN);
}
