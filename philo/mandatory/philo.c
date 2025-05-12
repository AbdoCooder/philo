/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:41:53 by abenajib          #+#    #+#             */
/*   Updated: 2025/05/12 21:17:35 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
//./philo 150 150 60 60

void	ft_start(t_philo *philo)
{
	ft_set_long(&philo->table->start_mtx, &philo->table->start, ft_get_time());
	ft_set_long(&philo->table->last_mtx, &philo->last_m,
		ft_get_long(&philo->table->start_mtx, &philo->table->start));
	if (philo->id % 2 == 0)
	{
		ft_print(philo, SLEEP);
		ft_usleep(philo, philo->table->time_to_sleep * 1e3);
	}
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	ft_start(philo);
	while (1)
	{
		if (ft_get_bool(&philo->table->end_mtx, &philo->table->end) == true)
			return (NULL);
		ft_print(philo, THINK);
		if (ft_take_forks(philo) == NULL)
			return (NULL);
		if (ft_eat(philo) == 1)
			return (NULL);
		if (ft_get_bool(&philo->table->end_mtx, &philo->table->end) == true)
			return (NULL);
		ft_print(philo, SLEEP);
		if (ft_usleep(philo, philo->table->time_to_sleep * 1e3) == 1)
			return (NULL);
	}
	return (NULL);
}

void	*monitor(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	usleep(1000);
	while (!ft_isfull(table))
		if (ft_isdead(table))
			break ;
	return (NULL);
}

int	main(int ac, char **av)
{
	t_table	table;
	int		i;

	if (!ft_check_args(ac, av))
		return (FAILURE);
	ft_init(&table, ac, av);
	ft_set_long(&table.start_mtx, &table.start, ft_get_time());
	ft_pthread_mode(table.monitor, monitor, &table, CREATE);
	ft_pthread_mode(table.monitor, monitor, &table, JOIN);
	i = -1;
	while (++i < table.nbr_of_philos)
		ft_pthread_mode(&table.philos[i].t, routine, NULL, JOIN);
	free(table.philos);
	free(table.forks);
	free(table.monitor);
	return (SUCCESS);
}

// philos	die		eat		sleep	times_to_eat
// 5		800		200		200		7
// av[1]	av[2]	av[3]	av[4]	av[5]
