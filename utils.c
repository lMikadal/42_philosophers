/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:01:26 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/10 10:01:30 by pmikada          ###   ########.fr       */
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
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			sum = (sum * 10) + (str[i] - '0');
		else
			return (-1);
		i++;
	}
	return (sum * m);
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
			printf("%s%ld %d is thinking%s\n", YELLOW, time, id, WHITE);
		else if (mode == DIED)
			printf("%s%ld %d died%s\n", RED, time, id, WHITE);
	}
}

long	ft_getmil(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

long	ft_gettime(struct timeval start)
{
	long	re;

	re = ft_getmil() - ((start.tv_sec * 1000) + (start.tv_usec / 1000));
	return (re);
}

void	ft_usleep(int time)
{
	long	now;

	now = ft_getmil();
	while (ft_getmil() - now < (long)time)
		usleep(500);
}
