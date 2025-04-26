/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:17:07 by abenajib          #+#    #+#             */
/*   Updated: 2025/02/11 20:18:26 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_mutex_mode(t_mtx *mtx, t_mode mode)
{
	if (mode == LOCK)
		ft_mutex_errors(pthread_mutex_lock(mtx), mode);
	else if (mode == UNLOCK)
		ft_mutex_errors(pthread_mutex_unlock(mtx), mode);
	else if (mode == DESTROY)
		ft_mutex_errors(pthread_mutex_destroy(mtx), mode);
	else if (mode == INIT)
		ft_mutex_errors(pthread_mutex_init(mtx, NULL), mode);
	else
		ft_error("Error: invalid mode\n", NULL);
}

void	ft_pthread_mode(t_pthread *thread, void *(*routine)(void* data), void *data, t_mode mode)
{
	if (mode == CREATE)
		ft_thread_errors(pthread_create(thread, NULL, routine, data), mode);
	else if (mode == DETACH)
		ft_thread_errors(pthread_detach(*thread), mode);
	else if (mode == JOIN)
		ft_thread_errors(pthread_join(*thread, NULL), mode);
	else
		ft_error("Error: invalid mode\n", NULL);
}

