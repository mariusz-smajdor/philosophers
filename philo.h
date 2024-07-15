/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:34:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/05 21:37:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>

typedef struct s_simulation	t_simulation;
typedef struct s_philo		t_philo;
typedef struct s_fork		t_fork;

typedef pthread_mutex_t	t_mutex;

typedef struct s_fork
{
	int		id;
	t_mutex	fork;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				meals_count;
	long			last_meal;
	bool			is_eating;
	pthread_t		thread;
	t_fork			*left_fork;
	t_fork			*right_fork;
	s_simulation	*simulation;
}	t_philo;

typedef struct s_simulation
{
	int		philo_count;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		max_meals;
	t_philo	*philos;
	t_fork	*forks;
}	t_simulation;

bool	is_digit(const char c);
bool	is_space(const char c);
void	error_exit(const char *msg);
void	initiate_data(t_simulation *simulation, char **av);

#endif


