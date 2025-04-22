/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:59:26 by codespace         #+#    #+#             */
/*   Updated: 2025/02/12 18:03:52 by abenajib         ###   ########.fr       */
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

//Enums
typedef enum e_mode
{
	CREATE,
	LOCK,
	UNLOCK,
	DESTROY,
	INIT
}	t_mode;

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

//aliases
typedef pthread_mutex_t	t_mtx;
typedef pthread_t		t_trd;
typedef struct s_philo	t_philo;

//structures
typedef struct s_fork
{
	t_mtx	fork;
	int		id;
}			t_fork;

typedef struct s_table
{
	t_fork	*forks;
	t_philo	*philos;
	long	start;
	long	end;
	long	nbr_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_of_times_to_eat;
	bool	all_threads_ready;
	t_mtx	table_mutex;
}			t_table;

struct s_philo
{
	int				id;
	t_trd			t;
	t_table			*table;
	t_fork			*first_fork;
	t_fork			*second_fork;
	long			eaten_m;
	long			last_m;
	bool			is_full;
	struct s_philo	*next;
};

//functions

//checkers
bool		ft_check_args(int ac, char **av);
bool		fancy_typing(int ac);

//error
void		ft_error(char *error, char *warning);
void		ft_mutex_errors(int status, t_mode mode);

//mutex
void		ft_mutex_mode(t_mtx *mtx, t_mode mode);

//initiation
void		ft_init_table(t_table *table, int ac, char **av);
void		ft_init(t_table *table, int ac, char **av);
void		ft_init_philos(t_table *table);
void		ft_assign_forks(t_philo *philo, t_fork *forks, int i);

//utils
long long	ft_atoi(const char *str);
void		*ft_malloc(size_t bytes);

//setters_getters
void		set_bool(t_mtx *mutex, bool *dest, bool value);
bool		get_bool(t_mtx *mutex, bool *dest);
void		set_long(t_mtx *mutex, long *dest, long value);
long		get_long(t_mtx *mutex, long *dest);

#endif
