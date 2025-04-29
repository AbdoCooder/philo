/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:59:26 by codespace         #+#    #+#             */
/*   Updated: 2025/04/29 10:42:46 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//includes
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

//colors
# define DEF_COLOR "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

//Macros
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define FAILURE 1
# define SUCCESS 0
# define PROGRAM_ARG 0
# define NBR_OF_PHILOS_ARG 1
# define TIME_TO_DIE_ARG 2
# define TIME_TO_EAT_ARG 3
# define TIME_TO_SLEEP_ARG 4
# define NBR_OF_TIMES_TO_EAT_ARG 5

//Enums
typedef enum e_mode
{
	CREATE,
	LOCK,
	UNLOCK,
	DESTROY,
	DETACH,
	JOIN,
	INIT
}	t_mode;

typedef enum e_action
{
	EAT,
	SLEEP,
	THINK,
	FORK,
	DIE
}	t_action;

//types
typedef pthread_mutex_t	t_mtx;
typedef pthread_t		t_pthread;
typedef struct s_philo	t_philo;

//structures
// typedef struct s_fork
// {
// 	t_mtx	fork;
// 	int		id;
// }			t_fork;

typedef struct s_table
{
	t_mtx		*forks;
	t_philo		*philos;
	t_pthread	*monitor;
	long		start;
	bool		end;
	long		nbr_of_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_of_times_to_eat;
	t_mtx		printer;
	t_mtx		eatmtx;
	t_mtx		deadcheck;
}			t_table;

struct s_philo
{
	int				id;
	t_pthread		t;
	t_table			*table;
	t_mtx			*first_fork;
	t_mtx			*second_fork;
	long			eaten_m;
	long			last_m;
	bool			is_full;
};

//checkers
bool		ft_check_args(int ac, char **av);
bool		fancy_typing(int ac);

//error
void		ft_error(char *error, char *warning);
void		ft_mutex_errors(int status, t_mode mode);
void		ft_thread_errors(int status, t_mode mode);

//modes
void		ft_mutex_mode(t_mtx *mtx, t_mode mode);
void		ft_pthread_mode(t_pthread *thread, void *(*routine)(void *data),
				void *data, t_mode mode);

//inits
void		ft_init(t_table *table, int ac, char **av);
void		ft_init_philos(t_table *table);
void		ft_assign_forks(t_philo *philo, t_mtx *forks, int i);

//utils
long long	ft_atoi(const char *str);
void		*ft_malloc(size_t bytes);
void		ft_print(t_philo *philo, t_action action);
int			ft_usleep(t_philo *philo, useconds_t t);

//setters_getters
void		ft_set_bool(t_mtx *mutex, bool *dest, bool value);
bool		ft_get_bool(t_mtx *mutex, bool *dest);
void		ft_set_long(t_mtx *mutex, long *dest, long value);
long		ft_get_long(t_mtx *mutex, long *dest);
long		ft_get_time(void);

// simulation
void		*routine(void *data);

#endif
