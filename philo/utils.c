/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:09:03 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/15 15:06:38 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(char *s)
{
	int	i;
	int	m;
	int	sum;

	i = 0;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	m = 1;
	if (s[i] == '-')
		m = -1;
	sum = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			sum = (sum * 10) + (s[i] - '0');
		else
			return (-1);
		i++;
	}
	return (sum * m);
}

long	ft_mil_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

long	ft_mil_print(long time_start)
{
	return (ft_mil_now() - time_start);
}

void	ft_print(long time, int mode, int id, int print)
{
	if (print == 1)
	{
		if (mode == FORK)
			printf("%s%ld %d has take a fork%s\n", BLUE, time, id, WHITE);
		else if (mode == EAT)
			printf("%s%ld %d is eating%s\n", PURPLE, time, id, WHITE);
		else if (mode == SLEEP)
			printf("%s%ld %d is sleeping%s\n", GREEN, time, id, WHITE);
		else if (mode == THINK)
			printf("%s%ld %d is think%s\n", YELLOW, time, id, WHITE);
		else if (mode == DIE)
			printf("%s%ld %d died%s\n", RED, time, id, WHITE);
	}
}

void	ft_free(t_rule *r)
{
	free(r->philo);
	free(r->thread);
	free(r->fork);
}
