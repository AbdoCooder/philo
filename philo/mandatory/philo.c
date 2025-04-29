/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:41:53 by abenajib          #+#    #+#             */
/*   Updated: 2025/04/29 12:01:26 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_eat(t_philo *philo)
{
	if (ft_get_bool(&philo->table->deadcheck, &philo->table->end) == true)
		return (1);
	ft_print(philo, EAT);
	ft_usleep(philo, philo->table->time_to_eat * 1e3);
	ft_set_long(&philo->table->eatmtx, &philo->last_m, ft_get_time());
	ft_set_long(&philo->table->eatmtx, &philo->eaten_m, philo->eaten_m + 1);
	ft_mutex_mode(philo->first_fork, UNLOCK);
	ft_mutex_mode(philo->second_fork, UNLOCK);
	return (0);
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
		ft_usleep(philo, philo->table->time_to_sleep * 1e3);
	}
	while (1)
	{
		if (ft_get_bool(&philo->table->deadcheck, &philo->table->end) == true)
			return (NULL);
		ft_print(philo, THINK);

		if (ft_get_bool(&philo->table->deadcheck, &philo->table->end) == true)
			return (NULL);
		ft_mutex_mode(philo->first_fork, LOCK);
		ft_print(philo, FORK);

		if (ft_get_bool(&philo->table->deadcheck, &philo->table->end) == true)
			return (NULL);
		ft_mutex_mode(philo->second_fork, LOCK);
		ft_print(philo, FORK);

		if (ft_eat(philo) == 1)
			return (NULL);

		if (ft_get_bool(&philo->table->deadcheck, &philo->table->end) == true)
			return (NULL);
		ft_print(philo, SLEEP);
		ft_usleep(philo, philo->table->time_to_sleep * 1e3);
	}
	return (NULL);
}

int	ft_isdead(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nbr_of_philos)
		if (table->time_to_die <= (ft_get_time() - ft_get_long(&table->eatmtx, &table->philos[i].last_m)))
			return (ft_set_bool(&table->deadcheck, &table->end, true),
				ft_print(&table->philos[i], DIE), 1);
	return (0);
}

int	ft_isfull(t_table *table)
{
	int	i;

	if (table->nbr_of_times_to_eat == -1)
		return (0);
	i = -1;
	while (++i < table->nbr_of_philos)
		if (ft_get_long(&table->eatmtx, &table->philos[i].eaten_m) >= table->nbr_of_times_to_eat)
			return (ft_set_bool(&table->deadcheck, &table->end, true),
				ft_print(&table->philos[i], DIE), 1);
	return (0);
}

void	*monitor(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (1)
		if (ft_isdead(table) || ft_isfull(table))
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
	ft_pthread_mode(table.monitor, monitor, &table, CREATE);
	i = -1;
	while (++i < table.nbr_of_philos)
		ft_pthread_mode(&table.philos[i].t, routine, NULL, JOIN);
	ft_pthread_mode(table.monitor, monitor, &table, JOIN);
	free(table.philos);
	free(table.forks);
	free(table.monitor);
	return (SUCCESS);
}

// philos	die		eat		sleep	times_to_eat
// 5		800		200		200		7
// av[1]	av[2]	av[3]	av[4]	av[5]
