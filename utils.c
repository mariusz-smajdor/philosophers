/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:57:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/06 17:58:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(char *error)
{
	printf("Error: %s\n", error);
	exit(EXIT_FAILURE);
}

inline bool	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
