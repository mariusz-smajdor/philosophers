/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by msmajdor          #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef pthread_t t_thread;
typedef pthread_mutex_t	t_mtx;

typedef struct s_philo t_philo;
typedef struct s_fork t_fork;
typedef struct s_sim t_sim;

typedef struct s_philo
{
	long		id;
	t_fork		*first_fork;
	t_fork		*second_fork;
	t_sim		*sim;
	t_mtx		mutex;
	t_thread	thread;
}	t_philo;

typedef struct s_fork
{
	long	id;
	t_mtx	mutex;
}	t_fork;

typedef struct s_sim
{
	long	philo_num;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	max_meals;
	long	start_time;
	bool	ready;
	t_fork	*forks;
	t_philo	*philos;
}	t_sim;

long	get_current_time_in_millisec();
void	error_exit(const char *msg);
void	*safe_malloc(size_t size);

bool	is_digit(const char c);
bool	is_space(const char c);
void	init_data(t_sim *sim, char **args);

void	start_sim(t_sim *sim);

#endif


