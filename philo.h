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

typedef pthread_t t_thrd;
typedef pthread_mutex_t	t_mtx;

typedef struct s_philo t_philo;
typedef struct s_fork t_fork;
typedef struct s_sim t_sim;

typedef struct s_philo
{
	long	id;
	long	last_meal;
	long	meals;
	bool	is_eating;
	t_fork	*first_fork;
	t_fork	*second_fork;
	t_sim	*sim;
	t_mtx	mutex;
	t_thrd	thread;
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
	bool	over;
	t_fork	*forks;
	t_philo	*philos;
	t_thrd	monitor;
	t_mtx	mutex;
}	t_sim;

typedef enum e_opcode
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

long	get_timestamp(long time);
long	get_current_time_in_millisec();
void	error_exit(const char *msg);
void	*safe_malloc(size_t size);
void	safe_mutex(t_mtx *mutex, t_opcode opcode);
void	safe_thread(t_thrd *thread, void *(*routine)(void *), void *data, t_opcode opcode);

void	init_data(t_sim *sim, char **args);
bool	is_digit(const char c);
bool	is_space(const char c);

void	start_sim(t_sim *sim);
void	*philo_routine(void *data);
void	*monitor(void *data);

#endif
