/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:29:08 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/19 00:29:21 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"  

void	put_values_2(t_sim *ph, t_philosof ***s)
{
	t_philosof	**p;
	int			i;

	i = 0;
	p = *s;
	while (i < ph->number_of_philosophers)
	{
		p[i]->philosof_number = i;
		p[i]->sim = ph;
		p[i]->number_of_meals = 0;
		i++;
	}
	*s = p;
}

int	set_sim(char **av, t_sim *ph, int ac)
{
	int	i;

	i = 1;
	ph->number_of_philosophers = ft_atoi(av[i++]);
	ph->time_to_die = ft_atoi(av[i++]);
	ph->time_to_eat = ft_atoi(av[i++]);
	ph->time_to_sleep = ft_atoi(av[i++]);
	ph->mutex = malloc(sizeof(pthread_mutex_t *) * ph->number_of_philosophers);
	if (!ph->mutex)
		return (ft_error(2));
	ph->dying = malloc(sizeof(pthread_mutex_t) * 1);
	if (!ph->dying)
		return (ft_error(2));
	ph->meals_left = 0;
	if (ac == 6)
		ph->all_meals = ft_atoi(av[i]);
	else
		ph->all_meals = 0;
	i = 0;
	pthread_mutex_init(ph->dying, NULL);
	while (i < ph->number_of_philosophers)
	{
		ph->mutex[i] = malloc(sizeof(pthread_mutex_t));
		if (!ph->mutex[i])
			return (ft_error(2));
		pthread_mutex_init(ph->mutex[i++], NULL);
	}
	return (0);
}

int	check_num(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) > 2147483647)
			return (0);
		if (ft_atoi(av[1]) < 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (++i < ac)
	{
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				if (av[i][j] == '+' && ft_isdigit(av[i][j + 1]))
				{
				}
				else
					return (0);
			}
			j++;
		}
		j = 0;
	}
	return (check_num(ac, av));
}

int	ft_error(int Er)
{
	if (Er == 1)
		printf("arguments error\ncheck your arguments\n");
	else
		printf("Error\n");
	return (1);
}
