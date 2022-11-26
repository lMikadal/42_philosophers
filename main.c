/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:00:17 by pmikada           #+#    #+#             */
/*   Updated: 2022/11/05 15:00:18 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	ft_init_philo(t_philo *philo, int id)
{
	philo->id = id;
	philo->fork = 0;
}

static void	ft_add_rule(int ac, char **av, t_rule *rule)
{
	int	i;

	rule->n_philo = ft_atoi(av[1]);
	rule->die = ft_atoi(av[2]);
	rule->eat = ft_atoi(av[3]);
	rule->sleep = ft_atoi(av[4]);
	if (ac == 6)
		rule->c_eat = ft_atoi(av[5]);
	else
		rule->c_eat = -1;
	rule->philo = (t_philo *)malloc(sizeof(t_philo) * rule->n_philo);
	if (rule->philo == NULL)
		return ;
	i = -1;
	while (++i < rule->n_philo)
		ft_init_philo(&rule->philo[i], i + 1);
}

int	main(int ac, char **av)
{
	t_rule	rule;

	if (ac == 5 || ac == 6)
	{
		ft_add_rule(ac, av, &rule);
		ft_free(&rule);
	}
	else
		printf("argument not correct\n");
	return (0);
}
