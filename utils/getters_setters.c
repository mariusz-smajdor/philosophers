/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:34:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/17 21:37:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	set_bool(t_mutex *mutex, bool *var, bool value)
{
	safe_mutex(mutex, LOCK);
	*var = value;
	safe_mutex(mutex, UNLOCK);
}

bool	get_bool(t_mutex *mutex, bool *var)
{
	bool	value;

	safe_mutex(mutex, LOCK);
	value = *var;
	safe_mutex(mutex, UNLOCK);
	return (value);
}

void	set_long(t_mutex *mutex, long *var, long value)
{
	safe_mutex(mutex, LOCK);
	*var = value;
	safe_mutex(mutex, UNLOCK);
}

long	get_long(t_mutex *mutex, long *var)
{
	long	value;

	safe_mutex(mutex, LOCK);
	value = *var;
	safe_mutex(mutex, UNLOCK);
	return (value);
}
