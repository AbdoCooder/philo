/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:55:26 by abenajib          #+#    #+#             */
/*   Updated: 2025/05/10 12:37:17 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print(t_philo *philo, t_action action)
{
	long	time;

	if (ft_get_bool(&philo->table->end_mtx, &philo->table->end) == true
		&& action != DIE)
		return ;

	ft_mutex_mode(&philo->table->printer, LOCK);
	time = ft_get_time() - ft_get_long(&philo->table->start_mtx,
			&philo->table->start);

	if (action == EAT)
		printf("%ld %d is eating\n", time, philo->id);
	else if (action == SLEEP)
		printf("%ld %d is sleeping\n", time, philo->id);
	else if (action == THINK)
		printf("%ld %d is thinking\n", time, philo->id);
	else if (action == FORK)
		printf("%ld %d has taken a fork\n", time, philo->id);
	else
		printf("%ld %d died\n", time, philo->id);
	ft_mutex_mode(&philo->table->printer, UNLOCK);
}
