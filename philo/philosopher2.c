/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:14:25 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/16 23:14:28 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_chk_die(t_rule *r)
{
	int	i;

	i = -1;
	while (++i < r->n_philo)
	{
		if (ft_mil_print(r->time_start) - r->philo[i].l_eat > (long)r->time_die \
			&& (r->philo[i].c_eat < r->count_eat || r->count_eat == -1))
		{
			pthread_mutex_lock(&r->print_die);
			ft_print(ft_mil_print(r->time_start), DIE, \
				r->philo[i].id, r->alive);
			r->alive = 0;
			pthread_mutex_unlock(&r->print_die);
			return (1);
		}
	}
	return (0);
}

int	ft_philo_eat(t_philo *p)
{
	pthread_mutex_lock(&p->r->table);
	if (p->r->alive == 0)
		return (1);
	pthread_mutex_lock(&p->r->fork[p->forkleft]);
	if (p->r->alive == 0)
		return (1);
	ft_print(ft_mil_print(p->r->time_start), FORK, p->id, p->r->alive);
	pthread_mutex_lock(&p->r->fork[p->forkright]);
	if (p->r->alive == 0)
		return (1);
	ft_print(ft_mil_print(p->r->time_start), FORK, p->id, p->r->alive);
	pthread_mutex_unlock(&p->r->table);
	ft_print(ft_mil_print(p->r->time_start), EAT, p->id, p->r->alive);
	p->l_eat = ft_mil_print(p->r->time_start);
	p->c_eat += 1;
	ft_sleep(p->r->time_eat);
	if (p->r->alive == 0)
		return (1);
	pthread_mutex_unlock(&p->r->fork[p->forkright]);
	pthread_mutex_unlock(&p->r->fork[p->forkleft]);
	return (0);
}

void	ft_philo_sleep(t_philo *p)
{
	ft_print(ft_mil_print(p->r->time_start), SLEEP, p->id, p->r->alive);
	ft_sleep(p->r->time_sleep);
	ft_print(ft_mil_print(p->r->time_start), THINK, p->id, p->r->alive);
}
