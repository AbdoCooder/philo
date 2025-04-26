/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:15:09 by codespace         #+#    #+#             */
/*   Updated: 2025/04/22 18:07:25 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(char *error, char *warning)
{
	if (error)
		printf(RED"Error: %s\n"DEF_COLOR, error);
	if (warning)
		printf(MAGENTA"%s\n"DEF_COLOR, warning);
}

void	ft_mutex_errors(int status, t_mode mode)
{
	if (status == SUCCESS)
		return ;
	else
	{
		if (mode == LOCK)
			ft_error("Error: pthread_mutex_lock\n", NULL);
		else if (mode == UNLOCK)
			ft_error("Error: pthread_mutex_unlock\n", NULL);
		else if (mode == DESTROY)
			ft_error("Error: pthread_mutex_destroy\n", NULL);
		else if (mode == INIT)
			ft_error("Error: pthread_mutex_init\n", NULL);
		return ;
	}
}

void	ft_thread_errors(int status, t_mode mode)
{
	if (status == SUCCESS)
		return ;
	else
	{
		if (mode == CREATE)
			ft_error("Error: pthread_create\n", NULL);
		else if (mode == DETACH)
			ft_error("Error: pthread_detach\n", NULL);
		else if (mode == JOIN)
			ft_error("Error: pthread_join\n", NULL);
		return ;
	}
}
