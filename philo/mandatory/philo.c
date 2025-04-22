/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:41:53 by abenajib          #+#    #+#             */
/*   Updated: 2025/02/12 22:16:24 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_for_threads(philo->table); //TODO:
	return (NULL);
}

bool	sim_finished(t_table t)
{
	return (get_bool(&t.table_mutex, t.end));
}

int	ft_safe_threads(pthread_t *thread, void *(*start_routine)(void *), void *arg, t_mode mode); //TODO:

void	ft_start_simulation(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_of_times_to_eat == 0)
		return ;
	else if (table->philos == 1)
	{
		//TODO:
	}
	else
	{
		while (++i < table->nbr_of_philos)
			ft_safe_threads(&table->philos[i].t, dinner, &table->philos[i], CREATE);
	}
}

int	main(int ac, char **av)
{
	t_table	table;

	if (!ft_check_args(ac, av))
		return (FAILURE);
	ft_init(&table, ac, av);
	ft_start_simulation(&table);
	free(table.philos);
	free(table.forks);
	return (SUCCESS);
}

// philos	die		eat		sleep	times_to_eat
// 5		800		200		200		7
// av[1]	av[2]	av[3]	av[4]	av[5]
