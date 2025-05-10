/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:41:53 by abenajib          #+#    #+#             */
/*   Updated: 2025/05/10 12:39:45 by abenajib         ###   ########.fr       */
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

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	ft_set_long(&philo->table->start_mtx, &philo->table->start, ft_get_time());
	ft_set_long(&philo->table->last_mtx, &philo->last_m, ft_get_long(&philo->table->start_mtx, &philo->table->start));
	if (philo->id % 2 == 0)
	{
		ft_print(philo, SLEEP);
		ft_usleep(philo, philo->table->time_to_sleep * 1e3);
	}
	while (1)
	{
		if (ft_get_bool(&philo->table->end_mtx, &philo->table->end) == true)
			return (NULL);

		ft_print(philo, THINK);
		ft_mutex_mode(philo->first_fork, LOCK);
		if (ft_get_bool(&philo->table->end_mtx, &philo->table->end) == true)
			return (ft_mutex_mode(philo->first_fork, UNLOCK), NULL);

		ft_print(philo, FORK);
		if (philo->table->nbr_of_philos == 1)
			return (ft_usleep(philo, philo->table->time_to_die * 1e3), NULL);

		ft_mutex_mode(philo->second_fork, LOCK);
		if (ft_get_bool(&philo->table->end_mtx, &philo->table->end) == true)
			return (ft_mutex_mode(philo->second_fork, UNLOCK), ft_mutex_mode(philo->first_fork, UNLOCK), NULL);

		ft_print(philo, FORK);
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

int	ft_isfull(t_table *table)
{
	int	i;
	int	counter;

	if (table->nbr_of_times_to_eat == -1)
		return (0);
	i = -1;
	counter = 0;
	while (++i < table->nbr_of_philos)
	{
		if (ft_get_long(&table->eatmtx, &table->philos[i].eaten_m) >= table->nbr_of_times_to_eat)
			counter++;
		if (counter == table->nbr_of_philos)
			return (ft_set_bool(&table->end_mtx, &table->end, true), 1);
	}
	return (0);
}

int	ft_isdead(t_table *table)
{
	int		i;
	long	elapsed;

	i = -1;
	while (++i < table->nbr_of_philos)
	{
		elapsed = ft_get_time() - ft_get_long(&table->last_mtx, &table->philos[i].last_m);
		if (elapsed >= table->time_to_die)
		{
			ft_set_bool(&table->end_mtx, &table->end, true);
			ft_print(&table->philos[i], DIE);
			return (1);
		}
	}
	return (0);
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
