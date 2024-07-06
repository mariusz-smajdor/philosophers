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
# include <stdlib.h>
# include <pthread.h>

typedef pthread_mutex_t t_mutex;
typedef unsigned short ushort;
typedef unsigned long ulong;

typedef struct s_fork t_fork;
typedef struct s_philo t_philo;
typedef struct s_philos t_philos;

typedef struct s_fork
{
	ushort	id;
	t_mutex	mutex;
}	t_fork;

typedef struct s_philo
{
	ushort	id;
	ushort	meals;
	ulong	last_meal_time;
	bool	is_eating;
	t_philo *left;
	t_philo *right;
}	t_philo;

typedef struct s_philos
{
	ushort 	max_meals;
	ulong 	eat_time;
	ulong 	sleep_time;
	ulong 	starve_time;
	ulong 	simulation_start;
	bool 	simulation_end;
	t_philo	*philos;
}	t_philos;

bool	is_digit(char c);
bool	is_space(char c);
void	error_exit(char *error);

#endif