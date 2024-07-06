/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:55:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/06 18:56:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static ulong	process_arg(char *arg)
{
	ulong	num;
	short	i;

	while (is_space(*arg))
		arg++;
	while (*arg == '+')
		arg++;
	if (!is_digit(*arg))
		error_exit("Argument is not a valid number!");
	num = 0;
	i = -1;
	while (++i, is_digit(*arg))
		num = num * 10 + (*arg++ - '0');
	if (num > INT_MAX || i > 10)
		error_exit("Argument number cannot be greater than INT_MAX!");
	return (num);
}	

void	init_philos(t_philos *philos, char **args)
{
	printf("%d\n", process_arg(args[0]));
	printf("%d\n", process_arg(args[1]));
	printf("%d\n", process_arg(args[2]));
	printf("%d\n", process_arg(args[3]));
}