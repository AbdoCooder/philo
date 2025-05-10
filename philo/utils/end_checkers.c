/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:29:38 by abenajib          #+#    #+#             */
/*   Updated: 2025/05/10 19:29:52 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
		if (ft_get_long(&table->eatmtx,
				&table->philos[i].eaten_m) >= table->nbr_of_times_to_eat)
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
		elapsed = ft_get_time() - ft_get_long(&table->last_mtx,
				&table->philos[i].last_m);
		if (elapsed >= table->time_to_die)
		{
			ft_set_bool(&table->end_mtx, &table->end, true);
			ft_print(&table->philos[i], DIE);
			return (1);
		}
	}
	return (0);
}
