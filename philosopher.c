/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:00:12 by pmikada           #+#    #+#             */
/*   Updated: 2022/11/05 15:00:13 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine(void* rule)
{
	t_philo	*r;

	r = (t_philo *)rule;
	return (NULL);
}

void	ft_run(t_rule *rule)
{
	int	i;

	i = -1;
	while (++i < rule->n_philo)
	{
		if (pthread_mutex_init(&rule->fork[i], NULL) != 0)
			return ;
	}
	i = -1;
	while (++i < rule->n_philo)
	{
		if (pthread_create(&rule->p[i], NULL, &routine, &rule->philo[i]) != 0)
			return ;
	}
	i = -1;
	while (++i < rule->n_philo)
	{
		if (pthread_join(rule->p[i], NULL) != 0)
			return ;
	}
	i = -1;
	while (++i < rule->n_philo)
		pthread_mutex_destroy(&rule->fork[i]);
	i = -1;
	while (++i < rule->n_philo)
		pthread_detach(rule->p[i]);
}
