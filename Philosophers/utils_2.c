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

void	put_values(t_sim *p)
{
	p->i[0] = 0;
	p->i[1] = 1;
	p->i[2] = 4;
	p->i[3] = 6;
	p->i[4] = 4;
}

int	ft_error(int Er)
{
	if (Er == 1)
		printf("arguments error\ncheck your arguments\n");
	else
		printf("Error\n");
	return (1);
}

unsigned int	get_time()
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	check_place(char *forks, int i)
{
	if (forks[i] == '1')
	{
		if (forks[i + 1])
		{
			if (forks[i + 1] == '1')
				return (i + 1);
		}
		else if (forks[0] == '1')
			return (0);
	}
	return (-1);
}