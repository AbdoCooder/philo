/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:43:19 by abenajib          #+#    #+#             */
/*   Updated: 2025/02/12 17:50:49 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_table(t_table *table, int ac, char **av)
{
	int	i;

	i = -1;
	table->nbr_of_philos = ft_atoi(av[NBR_OF_PHILOS_ARG]);
	table->time_to_die = ft_atoi(av[TIME_TO_DIE_ARG]) * 1e3;
	table->time_to_eat = ft_atoi(av[TIME_TO_EAT_ARG]) * 1e3;
	table->time_to_sleep = ft_atoi(av[TIME_TO_SLEEP_ARG]) * 1e3;
	table->end = FALSE;
	table->all_threads_ready = FALSE;
	ft_mutex_mode(&table->table_mutex, INIT);
	if (ac == 6)
	table->nbr_of_times_to_eat = ft_atoi(av[NBR_OF_TIMES_TO_EAT_ARG]);
	else
	table->nbr_of_times_to_eat = ERROR;
	table->philos = ft_malloc(sizeof(t_philo) * table->nbr_of_philos);
	table->forks = ft_malloc(sizeof(t_fork) * table->nbr_of_philos);
	while (++i < table->nbr_of_philos)
	{
		table->forks[i].id = i;
		ft_mutex_mode(&table->forks[i].fork, INIT);
	}
}

bool	fancy_typing(int ac)
{
	if (ac == 1)
		return (ft_error("Invalid Arguments", "\nNo Args? Really!"), FALSE);
	return (ft_error("Invalid Arguments", "\nHint! : five Arguments"),
		FALSE);
}

bool	ft_check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (fancy_typing(ac));
	if (ft_atoi(av[NBR_OF_PHILOS_ARG]) < 2
		|| ft_atoi(av[NBR_OF_PHILOS_ARG]) > 200)
		return (ft_error("Invalid Arguments", "\nHint! :number_of_philosophers \
[2~200]"),
			FALSE);
	if (ft_atoi(av[TIME_TO_DIE_ARG]) < 60
		|| ft_atoi(av[TIME_TO_DIE_ARG]) > INT_MAX)
		return (ft_error("Invalid Arguments", "\nHint! : time_to_die [>60]"),
			FALSE);
	if (ft_atoi(av[TIME_TO_EAT_ARG]) < 60
		|| ft_atoi(av[TIME_TO_EAT_ARG]) > INT_MAX)
		return (ft_error("Invalid Arguments", "\nHint! : time_to_eat [>60]"),
			FALSE);
	if (ft_atoi(av[TIME_TO_SLEEP_ARG]) < 60
		|| ft_atoi(av[TIME_TO_SLEEP_ARG]) > INT_MAX)
		return (ft_error("Invalid Arguments", "\nHint! : time_to_sleep [>60]"),
			FALSE);
	if (ac == 6 && (ft_atoi(av[NBR_OF_TIMES_TO_EAT_ARG]) < 1
			|| ft_atoi(av[NBR_OF_TIMES_TO_EAT_ARG]) > INT_MAX))
		return (ft_error("Invalid Arguments", "\nHint! : number_of_times_each_\
philosopher_must_eat [>1]"), FALSE);
	return (TRUE);
}
