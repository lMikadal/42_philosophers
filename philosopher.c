/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:11:06 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/10 10:11:08 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	*routine(void *rule)
{
	t_rule	*r;
	int		i;

	r = (t_rule *)rule;
	i = r->index;
	while (1)
	{
		if (ft_eat(r, i))
			break ;
		if (r->philo[i].n_eat == 0)
			r->philo_full += 1;
		if (r->philo_full >= r->n_philo)
			break ;
		if (ft_sleep(r, i))
			break ;
	}
	return (NULL);
}

static int	ft_create(t_rule *r)
{
	int	i;

	i = -1;
	while (++i < r->n_philo)
	{
		if (pthread_mutex_init(&r->fork[i], NULL) != 0)
		{
			printf("%sCan't mutex init fork%s\n", RED, WHITE);
			return (0);
		}
	}
	if (pthread_mutex_init(&r->print, NULL) != 0)
	{
		printf("%sCan't mutex init print%s\n", RED, WHITE);
		return (0);
	}
	if (pthread_mutex_init(&r->p_die, NULL) != 0)
	{
		printf("%sCan't mutex init p_die%s\n", RED, WHITE);
		return (0);
	}
	return (1);
}

static void	ft_destory(t_rule *r)
{
	int	i;

	i = -1;
	while (++i < r->n_philo)
		pthread_mutex_destroy(&r->fork[i]);
	pthread_mutex_destroy(&r->print);
	pthread_mutex_destroy(&r->p_die);
}

void	ft_thread(t_rule *r)
{
	int	i;

	if (ft_create(r) == 0)
		return ;
	i = 0;
	while (i < r->n_philo)
	{
		r->index = i;
		pthread_create(&r->thread[i], NULL, &routine, r);
		i += 2;
		if (i >= r->n_philo && i % 2 == 0)
		{
			usleep(50);
			i = 1;
		}
		usleep(5);
	}
	i = -1;
	while (++i < r->n_philo)
		pthread_join(r->thread[i], NULL);
	ft_destory(r);
}
