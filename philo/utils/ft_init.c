/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:25 by abenajib          #+#    #+#             */
/*   Updated: 2025/04/29 10:58:22 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init(t_table *table, int ac, char **av)
{
	int	i;

	i = -1;
	table->end = false;
	table->nbr_of_philos = ft_atoi(av[NBR_OF_PHILOS_ARG]);
	table->time_to_die = ft_atoi(av[TIME_TO_DIE_ARG]);
	table->time_to_eat = ft_atoi(av[TIME_TO_EAT_ARG]);
	table->time_to_sleep = ft_atoi(av[TIME_TO_SLEEP_ARG]);
	if (ac == 6)
		table->nbr_of_times_to_eat = ft_atoi(av[NBR_OF_TIMES_TO_EAT_ARG]);
	else
		table->nbr_of_times_to_eat = ERROR;
	table->philos = ft_malloc(sizeof(t_philo) * table->nbr_of_philos);
	table->forks = ft_malloc(sizeof(t_mtx) * table->nbr_of_philos);
	ft_init_philos(table);
	while (++i < table->nbr_of_philos)
	{
		ft_mutex_mode(&table->forks[i], INIT);
		ft_pthread_mode(&table->philos[i].t, routine, &table->philos[i],
			CREATE);
	}
	ft_mutex_mode(&table->printer, INIT);
	ft_mutex_mode(&table->eatmtx, INIT);
	ft_mutex_mode(&table->deadcheck, INIT);
}

void	ft_init_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nbr_of_philos)
	{
		table->philos[i].id = i + 1;
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
		philo->first_fork = &forks[0];
		philo->second_fork = &forks[1];
	}
	else if (i == philo->table->nbr_of_philos - 1)
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[0];
	}
	else
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[i + 1];
	}
}
