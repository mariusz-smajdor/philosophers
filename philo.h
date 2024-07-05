/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:44:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/07/05 21:46:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>

typedef struct s_philo
{
	int		id;
	bool	is_eating;
	long	meals;
	long	last_meal;
	t_philo *left;
	t_philo *right;
}	t_philo;

#endif