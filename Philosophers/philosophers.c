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


void	put_values_2(t_sim *ph, t_philosof ***s)
{
	t_philosof	**p;
	int			i;

	i = 0;
	p = *s;
	while (i < ph->number_of_philosophers)
	{
		p[i]->eating_time = 0;
		p[i]->philosof_number = i;
		p[i]->sim = ph;
		p[i]->fork = 1;
		i++;
	}
	*s = p;
}

int	init(pthread_t **philo, t_sim *ph, t_philosof ***s)
{
	int	i;
	t_philosof **p;
	p = *s;
	i = 0;
	*philo = malloc(sizeof(pthread_t) * ph->number_of_philosophers);
	if (!(*philo))
		return (0);
	p = malloc(sizeof(t_philosof *) * (ph->number_of_philosophers + 1));
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

int	check_forks(int x, int y)
{
	if (x == y - 1)
		return (0);
	else
		return (x + 1);
}

void	*routine(void *arg)
{
	t_philosof *p;
	struct timeval	start;
	struct timeval	death;
	int i;
	
	i = 0;
	gettimeofday(&start, NULL);
	gettimeofday(&death, NULL);
	p = arg;
	while (1)
	{
		pthread_mutex_lock(p->sim->mutex[p->philosof_number]);
		//printf("%d philosopher [%d] has taken a fork\n", get_time(start), p->philosof_number);
		pthread_mutex_lock(p->sim->mutex[check_forks(p->philosof_number, p->sim->number_of_philosophers)]);
		if (get_time(death) > p->sim->time_to_die / 1000)
		{
			printf("%d philosopher [%d] died\t%d\n", get_time(start), p->philosof_number, get_time(death));
			p->sim->death++;
			
			return (NULL);
		}
		printf("%d philosopher [%d] has taken a fork\n", get_time(start), p->philosof_number);
		printf("%d philosopher [%d] is eating\n", get_time(start), p->philosof_number);
		gettimeofday(&death, NULL);
		usleep(p->sim->time_to_eat);
		i++;
		pthread_mutex_unlock(p->sim->mutex[check_forks(p->philosof_number, p->sim->number_of_philosophers)]);
		pthread_mutex_unlock(p->sim->mutex[p->philosof_number]);
		if (i > 0)
		{
			printf("%d philosopher [%d] is sleeping\n", get_time(start), p->philosof_number);
			usleep(p->sim->time_to_sleep);
			i = 0;
			printf("%d philosopher [%d] is thinking\n", get_time(start), p->philosof_number);
		}
	}
 	return (NULL);
}

// void	free_all(t_sim *sim, t_philosof **p)
// {
// 	int	i;
	
// 	i = 0;
// 	while (i < sim->number_of_philosophers)
// 	{
// 		free(sim->mutex[i++]);

// 	}	
// 	free(sim->mutex);

// }


int main(int ac, char **av)
{
	pthread_t	*philo;
	t_sim 		sim;
	t_philosof	**p;
	int			i;

	i = 0;
	p = NULL;
	if ((ac != 6 && ac != 5) || !check_args(ac, av))
		return (ft_error(1));
	set_sim(av, &sim, ac);
	init(&philo, &sim, &p);
	
	/************************************************************/
	
	while (i < ft_atoi(av[1]))
	{
		if(pthread_create(&philo[i], NULL, &routine,(void *) p[i]) != 0)
			return (ft_error(2));
		usleep(300);
		i++;
	}
	while(1)
	{
		if (sim.death > 0)
			break;
	}
	//pthread_join(philo[0], NULL);
	//pthread_mutex_destroy(&mutex);
	return (0);
}
