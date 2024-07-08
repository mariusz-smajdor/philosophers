/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:18:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/08 18:02:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_thread(pthread_t *thread, void *(*philo_routine)(void *),
		void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		if (pthread_create(thread, NULL, &philo_routine, data) != 0)
			error_exit("Thread creation failed!");
	else if (opcode == JOIN)
		if (pthread_join(*thread, NULL) != 0)
			error_exit("Thread join failed!");
	else if (opcode == DETACH)
		if (pthread_detach(*thread) != 0)
			error_exit("Thread detach failed!");
	else
		error_exit("Invalid thread opcode!");
}

void	safe_mutex(t_mutex *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		if (pthread_mutex_lock(mutex) != 0)
			error_exit("Mutex lock failed!");
	else if (opcode == UNLOCK)
		if (pthread_mutex_unlock(mutex) != 0)
			error_exit("Mutex unlock failed!");
	else if (opcode == INIT)
		if (pthread_mutex_init(mutex, NULL) != 0)
			error_exit("Mutex initialization failed!");
	else if (opcode == DESTROY)
		if (pthread_mutex_destroy(mutex) != 0) 
			error_exit("Mutex destruction failed!");
	else
		error_exit("Invalid mutex opcode!");
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_exit("Memory allocation failed!");
	return (ptr);
}
