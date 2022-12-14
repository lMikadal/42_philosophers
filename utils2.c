/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:25:09 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/10 12:25:11 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_free(t_rule *rule)
{
	free(rule->philo);
	free(rule->fork);
	free(rule->thread);
}

long	ft_getmil_value(struct timeval now)
{
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	ft_unlock_fork(t_rule *r)
{
	int	i;

	i = -1;
	while (++i < r->n_philo)
	{
		pthread_mutex_unlock(&r->print);
		pthread_mutex_unlock(&r->fork[r->philo[i].forkright]);
		pthread_mutex_unlock(&r->fork[r->philo[i].forkleft]);
	}
}
