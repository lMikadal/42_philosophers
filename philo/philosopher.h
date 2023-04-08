/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:10:12 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/15 15:05:46 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define WHITE "\033[0m"

typedef struct s_rule	t_rule;

typedef struct s_arg
{
	int		ac;
	char	**av;
}	t_arg;

typedef struct s_philo
{
	int		id;
	int		forkleft;
	int		forkright;
	int		c_eat;
	long	l_eat;
	t_rule	*r;
}	t_philo;

typedef struct s_rule
{
	int				n_philo;
	t_philo			*philo;
	long			time_start;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				count_eat;
	int				full_philo;
	pthread_t		*thread;
	pthread_t		time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	table;
	pthread_mutex_t	print_die;
	int				alive;
}	t_rule;

void	ft_run(t_rule *r);
int		ft_chk_die(t_rule *r);
int		ft_philo_eat(t_philo *p);
void	ft_philo_sleep(t_philo *p);
int		ft_atoi(char *s);
long	ft_mil_now(void);
long	ft_mil_print(long time_start);
void	ft_print(long time, int mode, int id, int print);
void	ft_free(t_rule *r);
void	ft_sleep(int time_eat);
void	ft_unlock_fork(t_rule *r);
#endif
