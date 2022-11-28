/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:00:17 by pmikada           #+#    #+#             */
/*   Updated: 2022/11/28 20:00:37 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	ft_check_av(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) < 0)
			return (-1);
	}
	return (0);
}

static void	ft_init_philo(t_philo *philo, int id, t_rule *rule)
{
	philo->id = id;
	philo->fork = id - 1;
	philo->die = ft_atoi(rule->av[2]);
	philo->eat = ft_atoi(rule->av[3]);
	philo->sleep = ft_atoi(rule->av[4]);
	if (rule->ac == 6)
		philo->c_eat = ft_atoi(rule->av[5]);
	else
		philo->c_eat = -1;
}

static void	ft_add_rule(int ac, char **av, t_rule *rule)
{
	int	i;

	rule->ac = ac;
	rule->av = av;
	rule->n_philo = ft_atoi(av[1]);
	rule->philo = (t_philo *)malloc(sizeof(t_philo) * rule->n_philo);
	if (rule->philo == NULL)
		return ;
	i = -1;
	while (++i < rule->n_philo)
		ft_init_philo(&rule->philo[i], i + 1, rule);
	rule->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* rule->n_philo);
	if (rule->fork == NULL)
		return ;
	i = -1;
	while (++i < rule->n_philo)
		rule->philo[i].mutex = &rule->fork;
	rule->p = (pthread_t *)malloc(sizeof(pthread_t) * rule->n_philo);
	if (rule->p == NULL)
		return ;
}

int	main(int ac, char **av)
{
	t_rule	rule;

	if (ac == 5 || ac == 6)
	{
		if (ft_check_av(ac, av) == -1 || ft_atoi(av[1]) == 0)
		{
			printf("argument not correct\n");
			return (0);
		}
		ft_add_rule(ac, av, &rule);
		ft_run(&rule);
		ft_free(&rule);
	}
	else
		printf("argument not correct\n");
	return (0);
}
