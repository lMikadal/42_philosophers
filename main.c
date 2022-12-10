/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:53:32 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/10 09:53:33 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	ft_check_argument(int ac, char **av)
{
	int	i;

	if (ft_atoi(av[1]) <= 0)
		return (0);
	i = 1;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) < 0)
			return (0);
	}
	return (1);
}

static void	ft_process_die(char **av, t_rule *r)
{
	int	die;

	die = 1;
	ft_print(ft_gettime(r->s_eat), FORK, 1, 1);
	usleep(ft_atoi(av[2]) * 1000);
	ft_print(ft_atoi(av[2]), DIE, 1, 1);
}

static void	ft_init_philo(t_philo *philo, int id, int ac, char **av)
{
	philo->id = id;
	philo->forkleft = id - 1;
	if (id == ft_atoi(av[1]))
		philo->forkright = 0;
	else
		philo->forkright = id;
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->n_eat = ft_atoi(av[5]);
	else
		philo->n_eat = -1;
	gettimeofday(&philo->l_eat, NULL);
}

static int	ft_add_rule(int ac, char **av, t_rule *r)
{
	int	i;

	r->n_philo = ft_atoi(av[1]);
	r->philo = (t_philo *)malloc(sizeof(t_philo) * r->n_philo);
	if (r->philo == NULL)
		return (0);
	i = -1;
	while (++i < r->n_philo)
		ft_init_philo(&r->philo[i], i + 1, ac, av);
	r->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * r->n_philo);
	if (r->fork == NULL)
		return (0);
	r->thread = (pthread_t *)malloc(sizeof(pthread_t) * r->n_philo);
	if (r->thread == NULL)
		return (0);
	gettimeofday(&r->s_eat, NULL);
	r->die = 0;
	r->p = 1;
	r->philo_full = 0;
	if (r->n_philo == 1)
	{
		ft_process_die(av, r);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_rule	rule;

	if ((ac == 5 || ac == 6) && ft_check_argument(ac, av))
	{
		if (ft_add_rule(ac, av, &rule))
			ft_thread(&rule);
		ft_free(&rule);
	}
	else
		printf("argument not correct\n");
	return (0);
}
