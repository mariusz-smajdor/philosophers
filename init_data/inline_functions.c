/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inline_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by msmajdor          #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	is_digit(const char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_space(const char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
