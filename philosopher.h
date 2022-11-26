/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:00:00 by pmikada           #+#    #+#             */
/*   Updated: 2022/11/05 15:00:02 by pmikada          ###   ########.fr       */
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

typedef struct s_philo
{
	int	id;
	int	fork;
}	t_philo;

typedef struct s_rule
{
	int		n_philo;
	int		die;
	int		eat;
	int		sleep;
	int		c_eat;
	t_philo	*philo;
}	t_rule;

int		ft_atoi(char *str);
void	ft_print(int time, int mode, int philo);
void	ft_free(t_rule *rule);

#endif
