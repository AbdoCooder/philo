/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:25 by abenajib          #+#    #+#             */
/*   Updated: 2025/02/12 17:15:53 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_assign_forks(t_philo *philo, t_fork *forks, int i)
{
	int	philo_nbr;

	philo_nbr = philo->table->nbr_of_philos;
	philo->second_fork = &forks[i];
	philo->first_fork = &forks[(i + 1) % philo_nbr];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[(i + 1) % philo_nbr];
	}
}

void	ft_init_philos(t_table *table)
{
	int	i;
	t_philo	*philo;

	i = -1;
	while (++i < table->nbr_of_philos)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->is_full = false;
		philo->eaten_m = 0;
		philo->table = table;
		ft_assign_forks(philo, table->forks, i);
	}
}

void	ft_init(t_table *table, int ac, char **av)
{
	ft_init_table(table, ac, av);
	ft_init_philos(table);
}
