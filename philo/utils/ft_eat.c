/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:28:25 by abenajib          #+#    #+#             */
/*   Updated: 2025/05/10 19:32:29 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_eat(t_philo *philo)
{
	long	eaten;

	ft_print(philo, EAT);
	if (ft_usleep(philo, philo->table->time_to_eat * 1e3) == 1)
	{
		ft_mutex_mode(philo->first_fork, UNLOCK);
		ft_mutex_mode(philo->second_fork, UNLOCK);
		return (1);
	}
	ft_set_long(&philo->table->last_mtx, &philo->last_m, ft_get_time());
	eaten = ft_get_long(&philo->table->eatmtx, &philo->eaten_m);
	ft_set_long(&philo->table->eatmtx, &philo->eaten_m, eaten + 1);
	ft_mutex_mode(philo->first_fork, UNLOCK);
	ft_mutex_mode(philo->second_fork, UNLOCK);
	return (0);
}

void	*ft_take_forks(t_philo *philo)
{
	ft_mutex_mode(philo->first_fork, LOCK);
	if (ft_get_bool(&philo->table->end_mtx, &philo->table->end) == true)
		return (ft_mutex_mode(philo->first_fork, UNLOCK), NULL);
	ft_print(philo, FORK);
	if (philo->table->nbr_of_philos == 1)
		return (ft_usleep(philo, philo->table->time_to_die * 1e3), NULL);
	ft_mutex_mode(philo->second_fork, LOCK);
	if (ft_get_bool(&philo->table->end_mtx, &philo->table->end) == true)
		return (ft_mutex_mode(philo->second_fork, UNLOCK),
			ft_mutex_mode(philo->first_fork, UNLOCK), NULL);
	ft_print(philo, FORK);
	return ((void *)1);
}
