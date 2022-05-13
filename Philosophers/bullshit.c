/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullshit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:32:17 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/23 21:32:29 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main()
{
    int i = -1;
    while (++i < 100000)
    {
        printf("ibra\t%d\n", i);
    }
}

void	*philo_life(void *arg)
{
	t_sim *p;
	p = arg;

	while (1)
	{
		//printf("ib\n");
		if (p->i[1] % 10 == 9)		// || p->i[0] % 2 == p->i[1] % 2
		{
			//pthread_mutex_lock(&mutex);
			printf("ibra\t%d\n", p->i[1]);
			//ft_usleep(500);
			p->i[1]++;
			//sleep(1);
			//pthread_mutex_unlock(&mutex);
		}	
	}
	return (NULL);
}

void	*manager(void *arg)
{
	t_sim	*p;
	
	p = arg;
	while (1)
	{
		//printf("ib\n");
		//ft_usleep(1);
		//pthread_mutex_lock(&mutex);
		if (p->i[3] % 10 != 9)
			p->i[3]++;
		//ft_usleep(1);
		if (p->i[1] % 10 != 9)
			p->i[1]++;
		//pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

void	*philo_life_2(void *arg)
{
	t_sim *p;
	p = arg;
	while (1)
	{	
		//printf("ho\n");
		if (p->i[3] % 10 == 9)
		{
			//pthread_mutex_lock(&mutex);
			printf("yes\t%d\n", p->i[3]);
			//ft_usleep(500);
			p->i[3]++;
			//sleep(1);
			//pthread_mutex_unlock(&mutex);
		}
	}
	return (NULL);
}