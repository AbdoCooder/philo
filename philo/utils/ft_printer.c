/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:55:26 by abenajib          #+#    #+#             */
/*   Updated: 2025/04/27 17:55:49 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print(t_philo *philo, t_action action)
{
	ft_mutex_mode(&philo->table->printer, LOCK);
	if (action == EAT)
		printf("%ld %d is eating\n", ft_getTime() - philo->table->start, philo->id);
	else if (action == SLEEP)
		printf("%ld %d is sleeping\n", ft_getTime() - philo->table->start, philo->id);
	else if (action == THINK)
		printf("%ld %d is thinking\n", ft_getTime()-philo->table->start, philo->id);
	else if (action == FORK)
		printf("%ld %d has taken a fork\n", ft_getTime()-philo->table->start, philo->id);
	else
		printf("%ld %d died\n", ft_getTime()-philo->table->start, philo->id);
	ft_mutex_mode(&philo->table->printer, UNLOCK);
}
