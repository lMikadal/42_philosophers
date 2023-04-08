/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:08:36 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/15 16:27:33 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	ft_chk_arg(t_arg *arg)
{
	int	i;

	if (ft_atoi(arg->av[1]) <= 0)
		return (0);
	i = 1;
	while (++i < arg->ac)
	{
		if (ft_atoi(arg->av[i]) < 0)
			return (0);
	}
	return (1);
}

static void	ft_init_philo(t_philo *philo, int id, t_arg *arg, t_rule *r)
{
	philo->id = id;
	philo->forkleft = id - 1;
	if (id == ft_atoi(arg->av[1]))
		philo->forkright = 0;
	else
		philo->forkright = id;
	philo->c_eat = 0;
	philo->r = r;
}

static void	ft_set_time(t_rule *r)
{
	int		i;
	long	time;

	time = ft_mil_now();
	i = -1;
	while (++i < r->n_philo)
		r->philo[i].l_eat = 0;
	r->time_start = time;
}

static void	ft_add_rule(t_arg *arg, t_rule *r)
{
	int		i;

	r->n_philo = ft_atoi(arg->av[1]);
	r->philo = (t_philo *)malloc(sizeof(t_philo) * r->n_philo);
	if (r->philo == NULL)
		return ;
	i = -1;
	while (++i < r->n_philo)
		ft_init_philo(&r->philo[i], i + 1, arg, r);
	ft_set_time(r);
	r->time_die = ft_atoi(arg->av[2]);
	r->time_eat = ft_atoi(arg->av[3]);
	r->time_sleep = ft_atoi(arg->av[4]);
	if (arg->ac == 6)
		r->count_eat = ft_atoi(arg->av[5]);
	else
		r->count_eat = -1;
	r->full_philo = 0;
	r->thread = (pthread_t *)malloc(sizeof(pthread_t) * r->n_philo);
	if (r->thread == NULL)
		return ;
	r->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * r->n_philo);
	if (r->fork == NULL)
		return ;
	r->alive = 1;
}

int	main(int ac, char **av)
{
	t_rule	rule;
	t_arg	arg;

	if (ac == 6)
	{
		if (ft_atoi(av[5]) == 0)
			return (0);
	}
	arg.ac = ac;
	arg.av = av;
	if ((ac == 5 || ac == 6) && ft_chk_arg(&arg))
	{
		ft_add_rule(&arg, &rule);
		ft_run(&rule);
		ft_free(&rule);
	}
	else
		printf("argument not correct!!\n");
	return (0);
}
