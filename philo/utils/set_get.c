/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:52:39 by abenajib          #+#    #+#             */
/*   Updated: 2025/04/27 18:09:25 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_setBool(t_mtx *mutex, bool *dest, bool value)
{
	ft_mutex_mode(mutex, LOCK);
	*dest = value;
	ft_mutex_mode(mutex, UNLOCK);
}

bool	ft_getBool(t_mtx *mutex, bool *dest)
{
	bool	ret;

	ft_mutex_mode(mutex, LOCK);
	ret = *dest;
	ft_mutex_mode(mutex, UNLOCK);
	return (ret);
}

void	ft_setLong(t_mtx *mutex, long *dest, long value)
{
	ft_mutex_mode(mutex, LOCK);
	*dest = value;
	ft_mutex_mode(mutex, UNLOCK);
}

long	ft_getLong(t_mtx *mutex, long *dest)
{
	long	ret;

	ft_mutex_mode(mutex, LOCK);
	ret = *dest;
	ft_mutex_mode(mutex, UNLOCK);
	return (ret);
}

long	ft_getTime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (printf("-1"), 0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
