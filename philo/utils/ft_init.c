/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:25 by abenajib          #+#    #+#             */
/*   Updated: 2025/04/24 13:16:21 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init(t_table *table, int ac, char **av)
{
	ft_init_table(table, ac, av);
	ft_init_philos(table);
}

void	ft_init_table(t_table *table, int ac, char **av)
{
	int	i;

	i = -1;
	table->end = FALSE;
	table->nbr_of_philos = ft_atoi(av[NBR_OF_PHILOS_ARG]);
	table->time_to_die = ft_atoi(av[TIME_TO_DIE_ARG]) * 1e3;
	table->time_to_eat = ft_atoi(av[TIME_TO_EAT_ARG]) * 1e3;
	table->time_to_sleep = ft_atoi(av[TIME_TO_SLEEP_ARG]) * 1e3;
	if (ac == 6)
		table->nbr_of_times_to_eat = ft_atoi(av[NBR_OF_TIMES_TO_EAT_ARG]);
	else
		table->nbr_of_times_to_eat = ERROR;

	table->philos = ft_malloc(sizeof(t_philo) * table->nbr_of_philos);
	table->forks = ft_malloc(sizeof(t_mtx) * table->nbr_of_philos);
	while (++i < table->nbr_of_philos)
	{
		ft_mutex_mode(&table->forks[i], INIT);
		ft_pthread_mode(&table->philos[i].t, routine, NULL, CREATE);
	}
}

void	*routine(void *data)
{
	data = NULL;
	printf("Philo Created Successfully \n");
	return (NULL);
}

void	ft_init_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nbr_of_philos)
	{
		table->philos[i].is_full = false;
		table->philos[i].eaten_m = 0;
		table->philos[i].table = table;
		ft_assign_forks(&table->philos[i], table->forks, i);
	}
}

void	ft_assign_forks(t_philo *philo, t_mtx *forks, int i)
{
	if (i == 0)
	{
		philo->first_fork = forks[0];
		philo->second_fork = forks[1];
	}
	else if (i == philo->table->nbr_of_philos - 1)
	{
		philo->first_fork = forks[i];
		philo->second_fork = forks[0];
	}
	else
	{
		philo->first_fork = forks[i];
		philo->second_fork = forks[i + 1];
	}
}
