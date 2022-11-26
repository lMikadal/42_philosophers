/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:12:10 by pmikada           #+#    #+#             */
/*   Updated: 2022/11/26 16:12:12 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(char *str)
{
	int	i;
	int	m;
	int	sum;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	m = 1;
	if (str[i] == '-')
		m = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	sum = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (sum * m);
}

void	ft_print(int time, int mode, int philo)
{
	if (mode == 1)
		printf("%d %d has taken a fork\n", time, philo);
	else if (mode == 2)
		printf("%d %d is eating\n", time, philo);
	else if (mode == 3)
		printf("%d %d is sleeping\n", time, philo);
	else if (mode == 4)
		printf("%d %d is thinking\n", time, philo);
	else if (mode == 5)
		printf("%d %d died\n", time, philo);
}

void	ft_free(t_rule *rule)
{
	free(rule->philo);
	free(rule->fork);
	free(rule->p);
}
