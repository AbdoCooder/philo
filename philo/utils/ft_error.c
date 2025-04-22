/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:15:09 by codespace         #+#    #+#             */
/*   Updated: 2025/02/11 20:27:33 by abenajib         ###   ########.fr       */
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
		exit(1);
	}
}
