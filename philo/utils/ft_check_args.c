/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:43:19 by abenajib          #+#    #+#             */
/*   Updated: 2025/04/24 12:15:44 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


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
