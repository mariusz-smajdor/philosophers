/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:34:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/12 21:37:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_digit(const char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_space(const char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

void	error_exit(const char *msg)
{
	printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}
