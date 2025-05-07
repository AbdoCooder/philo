/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:04:35 by abenajib          #+#    #+#             */
/*   Updated: 2025/05/07 20:39:40 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	ft_atoi(const char *str)
{
	long long			sign;
	unsigned long long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((result * sign));
}

int	ft_usleep(t_philo *philo, useconds_t t)
{
	struct timeval start, current;
	long int elapsed;

	gettimeofday(&start, NULL);
	while (1)
	{
		if (ft_get_bool(&philo->table->deadcheck, &philo->table->end))
			return (1);
		gettimeofday(&current, NULL);
		// 1 second = 1,000,000 microseconds
		elapsed = (current.tv_sec - start.tv_sec) * 1000000L +
				(current.tv_usec - start.tv_usec);
		if (elapsed >= t)
			break;
		usleep(100);
	}
	return (0);
}
