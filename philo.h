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
# include <unistd.h>
# include <sys/time.h>

typedef enum e_status
{
	THINKING,
	SLEEPING,
	TAKEN_FORK,
	EATING,
	DIED,
}	t_status;

typedef enum e_time_unit
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}	t_time_unit;

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

typedef struct s_simulation	t_simulation;
typedef struct s_philo		t_philo;
typedef struct s_fork		t_fork;

typedef pthread_mutex_t	t_mutex;

typedef struct s_fork
{
	long	id;
	t_mutex	mutex;
}	t_fork;

typedef struct s_philo
{
	long			id;
	long			meals_count;
	long			last_meal;
	bool			is_eating;
	bool			full;
	pthread_t		thread;
	t_mutex			mutex;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_simulation	*simulation;
}	t_philo;

typedef struct s_simulation
{
	long	philo_count;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	max_meals;
	long	start_time;
	bool	philos_ready;
	bool	simulation_over;
	t_philo	*philos;
	t_fork	*forks;
	t_mutex	mutex;
	t_mutex print_mutex;
}	t_simulation;

bool	is_digit(const char c);
bool	is_space(const char c);
void	set_bool(t_mutex *mutex, bool *var, bool value);
bool	get_bool(t_mutex *mutex, bool *var);
void	set_long(t_mutex *mutex, long *var, long value);
long	get_long(t_mutex *mutex, long *var);
void	error_exit(const char *msg);
long	get_time(t_time_unit unit);
void	super_usleep(long sec, t_simulation *simulation);
void	*safe_malloc(size_t size);
void	safe_thread(pthread_t *thread, void *(*routine)(void *), void *data, t_opcode opcode);
void	safe_mutex(t_mutex *mutex, t_opcode opcode);

void	initiate_data(t_simulation *simulation, char **av);
void	start_simulation(t_simulation *simulation);

#endif


