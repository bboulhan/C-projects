/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:04:29 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/17 20:04:39 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(char **two_dimen)
{
	int	i;

	i = 0;
	while (two_dimen[i])
	{
		free(two_dimen[i]);
		i++;
	}
	free(two_dimen);
}

void	set_sim(char **av, t_sim *ph, int ac)
{
	int	i;

	i = 1;
	ph->number_of_philosophers = ft_atoi(av[i++]);
	ph->time_to_die = ft_atoi(av[i++]);
	ph->time_to_eat = ft_atoi(av[i++]);
	ph->time_to_sleep = ft_atoi(av[i++]);
	ph->mutex = malloc(sizeof(pthread_mutex_t *) * ph->number_of_philosophers);
	if (ac == 6)
		ph->cercle = ft_atoi(av[i]);
	else
		ph->cercle = -1;
	i = 0;
	ph->forks = ft_calloc(ph->number_of_philosophers + 1, 1);
	while (i < ph->number_of_philosophers)
	{
		ph->mutex[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(ph->mutex[i], NULL);
		ph->forks[i++] = '1';
	}
	ph->forks[i] = 0;
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (ft_atoi(av[1]) < 2 || ft_atoi(av[1]) > 200)
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
