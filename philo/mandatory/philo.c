/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:41:53 by abenajib          #+#    #+#             */
/*   Updated: 2025/04/27 18:51:42 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_eat(t_philo *philo)
{
	ft_print(philo, EAT);
	usleep(philo->table->time_to_eat * 1e3);
	ft_set_long(&philo->table->eatmtx, &philo->last_m, ft_get_time());
	ft_set_long(&philo->table->eatmtx, &philo->eaten_m, philo->eaten_m + 1);
	ft_mutex_mode(philo->first_fork, UNLOCK);
	ft_mutex_mode(philo->second_fork, UNLOCK);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->table->start = ft_get_time();
	philo->last_m = ft_get_time();
	if (philo->id % 2 == 0)
	{
		ft_print(philo, SLEEP);
		usleep(philo->table->time_to_sleep * 1e3);
	}
	while (1)
	{
		ft_mutex_mode(philo->first_fork, LOCK);
		ft_print(philo, FORK);
		ft_mutex_mode(philo->second_fork, LOCK);
		ft_print(philo, FORK);
		ft_eat(philo);
		ft_print(philo, SLEEP);
		usleep(philo->table->time_to_sleep * 1e3);
		ft_print(philo, THINK);
	}
	return (NULL);
}

void	*monitor(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	ft_usleep(philo->id);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_table	table;
	int		i;

	if (!ft_check_args(ac, av))
		return (FAILURE);
	ft_init(&table, ac, av);
	ft_pthread_mode(table.monitor, monitor, &table, CREATE);
	i = -1;
	while (++i < table.nbr_of_philos)
		ft_pthread_mode(&table.philos[i].t, routine, NULL, JOIN);
	ft_pthread_mode(table.monitor, monitor, &table, JOIN);
	free(table.philos);
	free(table.forks);
	return (SUCCESS);
}

// philos	die		eat		sleep	times_to_eat
// 5		800		200		200		7
// av[1]	av[2]	av[3]	av[4]	av[5]
