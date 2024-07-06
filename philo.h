/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:44:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/05 21:46:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct s_philo
{
	short	id;
	bool	is_eating;
	long	meals;
	long	last_meal;
	t_philo *left;
	t_philo *right;
}	t_philo;

typedef struct s_philos
{
	long 	eat_time;
	long 	sleep_time;
	long 	starve_time;
	short 	max_meals;
	long 	simulation_start;
	bool 	simulation_end;
	t_philo	*philos;
}	t_table;

int	ft_atoi(const char *str);

#endif