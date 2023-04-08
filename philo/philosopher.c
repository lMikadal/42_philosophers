/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:09:43 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/12 21:09:57 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	ft_create_mutex_thread(t_rule *r)
{
	int	i;

	i = -1;
	while (++i < r->n_philo)
	{
		if (pthread_mutex_init(&r->fork[i], NULL) != 0)
		{
			printf("%sCan't mutex init fork%s\n", RED, WHITE);
			return (1);
		}
	}
	if (pthread_mutex_init(&r->table, NULL) != 0)
	{
		printf("%sCan't mutex init table%s\n", RED, WHITE);
		return (1);
	}
	if (pthread_mutex_init(&r->print_die, NULL) != 0)
	{
		printf("%sCan't mutex init print_die%s\n", RED, WHITE);
		return (1);
	}
	return (0);
}

static void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		if (ft_philo_eat(p))
			break ;
		if (p->c_eat == p->r->count_eat)
		{
			p->r->full_philo += 1;
			break ;
		}
		ft_philo_sleep(p);
	}
	return (NULL);
}

static void	*ft_time(void *rule)
{
	t_rule	*r;

	r = (t_rule *)rule;
	while (1)
	{
		ft_chk_die(r);
		if (r->alive == 0 || r->n_philo == r->full_philo)
			break ;
	}
	while (r->alive == 0)
		ft_unlock_fork(r);
	return (NULL);
}

static void	ft_destory(t_rule *r)
{
	int	i;

	i = -1;
	while (++i < r->n_philo)
		pthread_mutex_destroy(&r->fork[i]);
	pthread_mutex_destroy(&r->table);
	pthread_mutex_destroy(&r->print_die);
}

void	ft_run(t_rule *r)
{
	int	i;

	if (ft_create_mutex_thread(r))
		return ;
	i = 0;
	while (i < r->n_philo)
	{
		pthread_create(&r->thread[i], NULL, &routine, &r->philo[i]);
		i += 2;
		if (i >= r->n_philo && i % 2 == 0)
			i = 1;
		usleep(5);
	}
	pthread_create(&r->time, NULL, &ft_time, r);
	i = -1;
	while (++i < r->n_philo)
		pthread_join(r->thread[i], NULL);
	r->alive = 1;
	pthread_join(r->time, NULL);
	ft_destory(r);
}
