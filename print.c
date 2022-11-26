/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:36:29 by pmikada           #+#    #+#             */
/*   Updated: 2022/11/26 15:36:31 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
	else
		printf("%d %d died\n", time, philo);
}
