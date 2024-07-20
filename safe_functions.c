/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by msmajdor          #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_thread(pthread_t *thread, void *(*routine)(void *), void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		if (pthread_create(thread, NULL, routine, data) != 0)
			error_exit("Thread creation failed!");
	if (opcode == JOIN)
		if (pthread_join(*thread, NULL) != 0)
			error_exit("Thread join failed!");
	if (opcode == DETACH)
		if (pthread_detach(*thread) != 0)
			error_exit("Thread detach failed!");
	if (!(opcode >= CREATE && opcode <= DETACH))
		error_exit("Invalid thread opcode!");
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_exit("Memory allocation failed!");
	return (ptr);
}
