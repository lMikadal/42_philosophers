/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:52:05 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/10 09:52:07 by pmikada          ###   ########.fr       */
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
# define DIED 5

# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define WHITE "\033[0m"

typedef struct s_philo
{
	int				id;
	int				forkleft;
	int				forkright;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	struct timeval	l_eat;
}	t_philo;

typedef struct s_rule
{
	int				n_philo;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*thread;
	pthread_mutex_t	print;
	pthread_mutex_t	p_die;
	struct timeval	s_eat;
	int				index;
	int				philo_full;
}	t_rule;

int		ft_atoi(char *str);
void	ft_print(long time, int mode, int id, int print);
long	ft_getmil(void);
long	ft_gettime(struct timeval start);
void	ft_usleep(int time);
void	ft_free(t_rule *rule);

#endif
