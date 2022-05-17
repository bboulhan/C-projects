/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:03:29 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/17 01:03:44 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(pthread_t **philo, t_sim *ph, t_philosof ***s)
{
	int			i;
	t_philosof	**p;

	p = *s;
	i = 0;
	*philo = malloc(sizeof(pthread_t) * ph->number_of_philosophers);
	if (!(*philo))
		return (0);
	p = malloc(sizeof(t_philosof *) * (ph->number_of_philosophers) + 1);
	if (!p)
		return (0);
	while (i < ph->number_of_philosophers)
	{
		p[i] = malloc(sizeof(t_philosof) * 1);
		if (!p[i])
			return (0);
		p[i]->thread = philo[i];
		i++;
	}
	p[i] = NULL;
	put_values_2(ph, &p);
	*s = p;
	return (1);
}

void	free_all(t_sim *sim, t_philosof **p)
{
	int			i;
	t_philosof	**t;

	t = p;
	i = 0;
	while (i < sim->number_of_philosophers)
	{
		free(t[i]);
		pthread_mutex_destroy(sim->mutex[i]);
		free(sim->mutex[i]);
		i++;
	}
	free(t);
	free(sim->mutex);
}

int	main(int ac, char **av)
{
	pthread_t		*philo;
	t_sim			sim;
	t_philosof		**p;

	p = NULL;
	if ((ac != 6 && ac != 5) || !check_args(ac, av))
		return (ft_error(1));
	set_sim(av, &sim, ac);
	init(&philo, &sim, &p);
	if (manager(philo, p, &sim))
		return (1);
	free_all(&sim, p);
	return (0);
}
