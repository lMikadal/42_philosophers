/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:08:25 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/10 13:08:26 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	ft_die(t_rule *r, int i, int unlock)
{
	pthread_mutex_lock(&r->p_die);
	usleep(50 * r->n_philo);
	ft_print(ft_gettime(r->s_eat), DIE, r->philo[i].id, r->p);
	r->p = 0;
	pthread_mutex_unlock(&r->p_die);
	if (unlock == 1)
	{
		pthread_mutex_unlock(&r->fork[r->philo[i].forkright]);
		pthread_mutex_unlock(&r->fork[r->philo[i].forkleft]);
	}
}

static void	ft_update_time(t_rule *r, int i)
{
	long	old;
	long	new;

	old = ft_getmil_value(r->philo[i].l_eat);
	gettimeofday(&r->philo[i].l_eat, NULL);
	new = ft_getmil_value(r->philo[i].l_eat);
	if (new - old >= (long)r->philo[i].t_die)
		r->die = 1;
}

int	ft_eat(t_rule *r, int i)
{
	pthread_mutex_lock(&r->print);
	pthread_mutex_lock(&r->fork[r->philo[i].forkleft]);
	ft_print(ft_gettime(r->s_eat), FORK, r->philo[i].id, r->p);
	pthread_mutex_lock(&r->fork[r->philo[i].forkright]);
	ft_print(ft_gettime(r->s_eat), FORK, r->philo[i].id, r->p);
	pthread_mutex_unlock(&r->print);
	ft_print(ft_gettime(r->s_eat), EAT, r->philo[i].id, r->p);
	ft_update_time(r, i);
	if (r->die == 1)
	{
		ft_die(r, i, 1);
		return (1);
	}
	ft_usleep(r->philo[i].t_eat, r->philo[i].t_die, &r->die);
	if (r->die == 1)
	{
		ft_die(r, i, 1);
		return (1);
	}
	r->philo[i].n_eat -= 1;
	pthread_mutex_unlock(&r->fork[r->philo[i].forkright]);
	pthread_mutex_unlock(&r->fork[r->philo[i].forkleft]);
	return (0);
}

int	ft_sleep(t_rule *r, int i)
{
	ft_print(ft_gettime(r->s_eat), SLEEP, r->philo[i].id, r->p);
	ft_usleep(r->philo[i].t_sleep, r->philo[i].t_die - r->philo[i].t_eat, &r->die);
	if (r->die == 1)
	{
		ft_die(r, i, 0);
		return (1);
	}
	ft_print(ft_gettime(r->s_eat), THINK, r->philo[i].id, r->p);
	return (0);
}
