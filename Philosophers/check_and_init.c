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

void	set_sim(char **av, t_sim *ph, int ac)
{
	int	i;

	i = 1;
	ph->number_of_philosophers = ft_atoi(av[i++]);
	ph->time_to_die = ft_atoi(av[i++]) * 1000;
	ph->time_to_eat = ft_atoi(av[i++]) * 1000;
	ph->time_to_sleep = ft_atoi(av[i++]) * 1000;
	ph->mutex = malloc(sizeof(pthread_mutex_t *) * ph->number_of_philosophers);
	ph->meals_left = 0;
	if (ac == 6)
		ph->all_meals = ft_atoi(av[i]);
	else
		ph->all_meals = 0;
	i = 0;
	while (i < ph->number_of_philosophers)
	{
		ph->mutex[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(ph->mutex[i++], NULL);
	}
}

int	check_forks(int x, int y)
{
	if (x == y - 1)
		return (0);
	else
		return (x + 1);
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (ft_atoi(av[1]) < 1)
		return (0);
	while (i < ac)
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
		if (ft_atoi(av[i]) > 2147483647)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}
