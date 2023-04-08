/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:05:04 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/17 10:05:05 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_sleep(int time_eat)
{
	long	now;

	now = ft_mil_now();
	while (ft_mil_now() - now < (long)time_eat)
		usleep(1);
}

void	ft_unlock_fork(t_rule *r)
{
	int	i;

	i = -1;
	while (++i < r->n_philo)
	{
		pthread_mutex_unlock(&r->table);
		pthread_mutex_unlock(&r->fork[i]);
	}
}
