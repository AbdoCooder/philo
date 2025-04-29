/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsGets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:52:39 by abenajib          #+#    #+#             */
/*   Updated: 2025/04/29 10:48:03 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_set_bool(t_mtx *mutex, bool *dest, bool value)
{
	ft_mutex_mode(mutex, LOCK);
	*dest = value;
	ft_mutex_mode(mutex, UNLOCK);
}

bool	ft_get_bool(t_mtx *mutex, bool *dest)
{
	bool	ret;

	ft_mutex_mode(mutex, LOCK);
	ret = *dest;
	ft_mutex_mode(mutex, UNLOCK);
	return (ret);
}

void	ft_set_long(t_mtx *mutex, long *dest, long value)
{
	ft_mutex_mode(mutex, LOCK);
	*dest = value;
	ft_mutex_mode(mutex, UNLOCK);
}

long	ft_get_long(t_mtx *mutex, long *dest)
{
	long	ret;

	ft_mutex_mode(mutex, LOCK);
	ret = *dest;
	ft_mutex_mode(mutex, UNLOCK);
	return (ret);
}

long	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (printf("-1"), 0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
