/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:41:53 by abenajib          #+#    #+#             */
/*   Updated: 2025/04/27 18:18:12 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *data)
{
	t_philo *philo = (t_philo *)data;

	philo->table->start = ft_getTime();
	philo->last_m = ft_getTime();
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat * 1e3 / 2);
	while (1)
	{
		ft_print(philo, THINK);
		ft_mutex_mode(philo->first_fork, LOCK);
		ft_print(philo, FORK);
		ft_mutex_mode(philo->second_fork, LOCK);
		ft_print(philo, FORK);

		ft_print(philo, EAT);
		ft_usleep(philo->table->time_to_eat * 1e3);
		ft_setLong(&philo->table->eatmtx, philo->last_m, ft_getTime());
		ft_setLong(&philo->table->eatmtx, philo->eaten_m, philo->eaten_m + 1);
		ft_mutex_mode(philo->first_fork, UNLOCK);
		ft_mutex_mode(philo->second_fork, UNLOCK);

		ft_print(philo, SLEEP);
		ft_usleep(philo->table->time_to_sleep * 1e3);
	}
	return (NULL);
}

void	*monitor(void *data)
{
	t_philo *philo = (t_philo *)data;
	return (NULL);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (!ft_check_args(ac, av))
		return (FAILURE);

	ft_init(&table, ac, av);

	ft_pthread_mode(table.monitor, monitor, &table, CREATE);

	int i = -1;
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
